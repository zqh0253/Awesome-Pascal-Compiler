#include "code_generator.h"

#include <iostream>

void CodeGenerator::gencode(Node *root) {
	// 初始化 LLVM
	if (this->context == nullptr) {
		this->context = new llvm::LLVMContext;
		this->ir_builder = new llvm::IRBuilder<>(*this->context);
	}
//	std::cout << "Begin generating code ..." << std::endl;
	if (root && root->is_root()) {
		root->codegen(this);
	}
//	std::cout << "End generating code !" << std::endl;
	llvm::llvm_shutdown();
}

void CodeGenerator::gencode_children(Node *root) {
	if (!root) return;
	for (auto child: root->get_descendants()) {
		if (child)
			child->codegen(this);
	}
	root->sem_analyze(local_sem());
}

llvm::Instruction *CodeGenerator::alloc_local_variable(llvm::Type *type, std::string &name) {
	return new llvm::AllocaInst(type, type->getPrimitiveSizeInBits(), name, local_bb());
}

llvm::Instruction *CodeGenerator::store_local_variable(std::string &name, llvm::Value *val) {
	llvm::Value *v = local_bb()->getValueSymbolTable()->lookup(name);
	return new llvm::StoreInst(val, v, false, local_bb());
}

llvm::Constant *CodeGenerator::to_llvm_constant(ConstValue *c) {
	llvm::Constant *ret = nullptr;
	if (c->type == ConstValue::INTEGER) {
		ret = llvm::ConstantInt::get(getIntTy(), c->integer);
	} else if (c->type == ConstValue::REAL) {
		ret = llvm::ConstantFP::get(getRealTy(), c->real);
	} else if (c->type == ConstValue::CHAR) {
		ret = llvm::ConstantInt::get(getCharTy(), c->ch);
	} else if (c->type == ConstValue::STRING) {
//		ret = new llvm::StringLiteral(c->str);
	} else if (c->type == ConstValue::MAXINT) {
		ret = llvm::ConstantInt::get(getIntTy(), 0x7fffffff);
	} else if (c->type == ConstValue::TRUE) {
		ret = llvm::ConstantInt::get(getBoolTy(), true);
	} else if (c->type == ConstValue::FALSE) {
		ret = llvm::ConstantInt::get(getBoolTy(), false);
	}
	return ret;
}

llvm::Type *CodeGenerator::to_llvm_type(sem::SemType *type) {
	llvm::Type *ret = nullptr;
	if (type->type == sem::VOID) {
		ret = getVoidTy();
	} else if (type->type == sem::INT) {
		ret = getIntTy();
	} else if (type->type == sem::REAL) {
		ret = getRealTy();
	} else if (type->type == sem::CHAR) {
		ret = getCharTy();
	} else if (type->type == sem::BOOL) {
		ret = getBoolTy();
	} else if (type->type == sem::STRING) {
		sem::String *s = (sem::String *)type;
		ret = getStringTy(s->size);
	} else if (type->type == sem::ARRAY) {
		sem::Array *a = (sem::Array *)type;
		ret = getArrayTy(to_llvm_type(a->el_type), a->end - a->begin);
	} else if (type->type == sem::RANGE) {
		ret = getStructTy("range");
		if (ret == nullptr) {
			std::vector<llvm::Type*> types;
			types.push_back(llvm::Type::getInt32Ty(*context));
			types.push_back(llvm::Type::getInt32Ty(*context));
			ret = createStructTy(types, "range");
		}
	} else if (type->type == sem::RECORD) {
		sem::Record *r = (sem::Record *)type;
		ret = getStructTy(r->local->global_name(r->type_name));
	}
	return ret;
}



/* ----- Code Generation ----- */
void Node::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void Program::codegen(CodeGenerator *cg) {
	// 初始化 Module 和 main 函数
	std::string &program_name = get_program_name();
	cg->add_module(program_name);
	std::string func_name = "main";
	llvm::FunctionType *func_type = llvm::FunctionType::get(llvm::Type::getVoidTy(*cg->context), false);
	llvm::Function *func = llvm::Function::Create(func_type, llvm::Function::InternalLinkage,
	                                              func_name, cg->cur_module);
	llvm::BasicBlock *bb = llvm::BasicBlock::Create(*cg->context,
			CodeGenerator::get_entry_name(func_name), func);
	cg->push_block(bb, func_name);

	cg->gencode_children(this);

	cg->cur_module->print(llvm::outs(), nullptr);
}

void ProgramHeading::codegen(CodeGenerator *cg) {

}

void Routine::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void RoutineHead::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void LabelPart::codegen(CodeGenerator *cg) {
//	cg->gencode_children(this);
}

void ConstPart::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void ConstExprList::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void ConstExpr::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
	std::string &const_name = id->idt;

	sem::SemType *const_type = cg->local_sem()->vars[const_name];
	llvm::Type *llvm_type = cg->to_llvm_type(const_type);
	llvm::Value *llvm_value = cg->to_llvm_constant(const_value);

	cg->alloc_local_variable(llvm_type, const_name);
	cg->store_local_variable(const_name, llvm_value);
}

void TypePart::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void TypeDecList::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void TypeDef::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
//	std::string &type_name = id->idt;
}

void TypeDec::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void SimpleType::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void ArrayType::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void RecordType::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
//	sem::Record *record = cg->local_sem()->last_record();
	std::vector<llvm::Type*> types;
//	for (auto re)
//	for (auto var_dec: record_dec_list->var_dec_list) {
//		llvm::Type *type = cg->to_llvm_type(var_dec->type_dec->sem_type);
//		for (auto var: var_dec->id_list->ID_list) {
//			names.push_back(var->idt);
//			types.push_back(type);
//		}
//	}
//	cg->createStructTy(types, record->global_name());
}

void VarDecList::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void VarDec::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}
