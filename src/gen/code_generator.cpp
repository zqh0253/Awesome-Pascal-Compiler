#include "code_generator.h"

void CodeGenerator::gencode(Node *root) {
	// 初始化 LLVM
	this->context = new llvm::LLVMContext;
	this->module = new llvm::Module("main", *this->context);
	this->ir_builder = new llvm::IRBuilder<>(*this->context);

	root->codegen(this);
}

void CodeGenerator::pre_gencode(Node *n) {
	for (auto child: n->get_descendants()) {
		child->codegen(this);
	}
	n->sem_analyze(top_sem());
}

//void CodeGenerator::set_local_variable() {
//
//}

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
	} else if (c->type == ConstValue::MAXINT) {
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
		ret = getStructTy(r->llvm_name);
	}
	return ret;
}

/* ----- Code Generation ----- */
void Program::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);
}

void ProgramHeading::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);
	std::string &program_name = program_ID->name;
	llvm::FunctionType *func_type = llvm::FunctionType::get(llvm::Type::getVoidTy(*cg->context), false);
	llvm::Function *func = llvm::Function::Create(func_type, llvm::Function::InternalLinkage, program_name, cg->module);
	llvm::BasicBlock *bb = llvm::BasicBlock::Create(*cg->context, CodeGenerator::get_entry_name(program_name), func);
	cg->ir_builder->SetInsertPoint(bb);
}

void Routine::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);
}

void RoutineHead::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);
}

void LabelPart::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);
}

void ConstPart::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);
}

void ConstExprList::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);
}

void ConstExpr::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);
	std::string &const_name = id->idt;
	sem::SemType *const_type = cg->top_sem()->vars[const_name];
	llvm::Type *llvm_type = cg->to_llvm_type(const_type);
	llvm::Value *llvm_value = cg->to_llvm_constant(const_value);

}

void TypePart::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);
}

void TypeDecList::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);
}

void TypeDef::codegen(CodeGenerator *cg) {
	cg->pre_gencode(this);

	std::string &type_name = id->idt;
}