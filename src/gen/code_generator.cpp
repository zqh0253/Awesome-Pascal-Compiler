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

void CodeGenerator::gencode_children(Node *n) {
	if (!n) return;
//	std::cout << "Begin generating code for " << n->name << "(" << n << ")" << std::endl;
	for (auto &child: n->get_descendants()) {
		if (child)
			child->codegen(this);
	}
	n->sem_analyze(local_sem());
}

sem::SemType *CodeGenerator::get_sem_type(const std::string &name) {
	return local_sem()->find_type(name);
}

sem::SemType *CodeGenerator::get_var_sem_type(const std::string &name) {
	return local_sem()->find_var(name);
}

sem::FuncInfo *CodeGenerator::get_sem_func(const std::string &name) {
	return local_sem()->find_func(name);
}

llvm::Type *CodeGenerator::get_var_llvm_type(const std::string &name) {
	return to_llvm_type(get_var_sem_type(name));
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
		ret = ir_builder->CreateGlobalString(c->process_string());
	} else if (c->type == ConstValue::SYSCON && c->sys_con == ConstValue::MAXINT) {
		ret = llvm::ConstantInt::get(getIntTy(), 0x7fffffff);
	} else if (c->type == ConstValue::SYSCON && c->sys_con == ConstValue::TRUE) {
		ret = llvm::ConstantInt::get(getBoolTy(), true);
	} else if (c->type == ConstValue::SYSCON && c->sys_con == ConstValue::FALSE) {
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
		ret = getStringTy(s->size+1);
		ret = llvm::PointerType::get(ret, 0);
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
		ret = getStructTy(r->local->to_global_name(r->type_name));
	}
	if (ret && type->is_ptr) {
		ret = llvm::PointerType::get(ret, 0);
	}
	return ret;
}

llvm::Instruction *CodeGenerator::alloc_local_variable(llvm::Type *type, const std::string &name) {
	return ir_builder->CreateAlloca(type, nullptr, name);
}

llvm::Instruction *CodeGenerator::store_local_variable(llvm::Value *ptr, llvm::Value *val) {
	return ir_builder->CreateStore(val, ptr, false);
}

llvm::Instruction *CodeGenerator::store_local_variable(const std::string &name, llvm::Value *val) {
	return store_local_variable(get_local_variable(name), val);
}

llvm::Value *CodeGenerator::load_variable(llvm::Value *ptr) {
	return ir_builder->CreateLoad(ptr);
}

llvm::Value *CodeGenerator::load_local_variable(const std::string &name) {
	return load_variable(get_local_variable(name));
}

llvm::Value *CodeGenerator::get_local_variable(const std::string &name) {
	return local_bb()->getValueSymbolTable()->lookup(name);
}

llvm::Value *CodeGenerator::get_record_member(sem::RecordMember *rm) {
	llvm::Value *v = get_local_variable(rm->name);
	std::vector<llvm::Value*> idx;
	idx.push_back(ir_builder->getInt32(0));
	for (auto &t: rm->locations) {
		idx.push_back(ir_builder->getInt32(t));
	}
	if (!idx.empty())
		v = ir_builder->CreateGEP(to_llvm_type(rm->begin_type), v, idx);
	return v;
}

llvm::Value *CodeGenerator::get_record_member_el(sem::RecordMember *rm, llvm::Value *index) {
	auto v = get_local_variable(rm->name);
	std::vector<llvm::Value*> idx;
	idx.push_back(ir_builder->getInt32(0));
	for (auto &t: rm->locations) {
		idx.push_back(ir_builder->getInt32(t));
	}
	idx.push_back(index);
	v = ir_builder->CreateGEP(to_llvm_type(rm->begin_type), v, idx);
//	std::cout << index->getName().str() << " " << (index->getType()->isIntegerTy(32)) << std::endl;
	auto el_type = ((sem::Array*)(rm->real_type))->el_type;
	auto ptr = llvm::PointerType::get(to_llvm_type(el_type), 0);
	return ir_builder->CreateCast(llvm::Instruction::CastOps::BitCast, v, ptr);
}

llvm::Value *CodeGenerator::get_array_ptr(llvm::Value *arr, llvm::Type *el_type) const {
	auto ptr = llvm::PointerType::get(el_type, 0);
	return ir_builder->CreateCast(llvm::Instruction::CastOps::BitCast, arr, ptr);
}

llvm::Value *CodeGenerator::get_array_ptr(llvm::Value *arr, sem::SemType *el_type) {
	return get_array_ptr(arr, to_llvm_type(el_type));
}

llvm::Value *CodeGenerator::get_array_el(llvm::Value *arr, llvm::Value *index, llvm::Type *el_type, int size) {
	auto ptr = llvm::PointerType::get(el_type, 0);
	auto v = ir_builder->CreateGEP(getArrayTy(el_type, size), arr, index);
	return ir_builder->CreateCast(llvm::Instruction::CastOps::BitCast, v, ptr);
}

llvm::Value *CodeGenerator::get_array_el(llvm::Value *arr, llvm::Value *index, sem::SemType *arr_type) {
	if (arr_type->type != sem::ARRAY) return nullptr;
	auto t = (sem::Array*)arr_type;
	return get_array_el(arr, index, to_llvm_type(t->el_type), t->size());
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
	llvm::Function *func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage,
	                                              func_name, cg->cur_module);
	llvm::BasicBlock *bb = llvm::BasicBlock::Create(*cg->context, "start", func);
	cg->push_block(bb, new sem::SemanticAnalyzer(func_name));
	cg->link_printf();
	cg->gencode_children(this);
	cg->ir_builder->CreateRetVoid();
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
//	std::cout << const_name << std::endl;
//	std::cout << const_value->type << std::endl;
	llvm::Type *llvm_type = cg->get_var_llvm_type(const_name);
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
	if (type_dec->type == TypeDec::RECORD) {
		// 在 LLVM 中重命名 Record
		sem::Record *record = (sem::Record *)cg->get_sem_type(id->idt);
		llvm::StructType *t = cg->getStructTy(record->global_name());
		record->type_name = id->idt;
		t->setName(record->global_name());
	}
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
	sem::Record *record = cg->local_sem()->last_record();
	std::vector<llvm::Type*> types;
	for (auto &var: record->types) {
		types.push_back(cg->to_llvm_type(var.second));
	}
	cg->createStructTy(types, record->global_name());
}

void VarDecList::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void VarDec::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void VarPart::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
	if (!is_empty) {
		for (auto &var: var_dec_list->var_dec_list) {
			llvm::Type *type = cg->to_llvm_type(var->type_dec->sem_type);
			for (auto &id: var->id_list->ID_list) {
				cg->alloc_local_variable(type, id->idt);
			}
		}
	}
}

void RoutinePart::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void SubProgram::codegen(CodeGenerator *cg) {
	head->codegen(cg);
	routine->codegen(cg);
	cg->ir_builder->CreateRet(cg->load_local_variable(head->id->idt));
	cg->pop_block();
}

void SubProgramHead::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
	std::string &func_name = id->idt;
	cg->create_llvm_function(func_name, cg->get_sem_func(func_name));
}

void Parameters::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void ParaDecList::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void ParaTypeList::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

// Routine Body
void RoutineBody::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void CompoundStmt::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void StatementList::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void Statement::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void CaseStmt::codegen(CodeGenerator *cg) {
	llvm::BasicBlock *old_bb = cg->local_cbb();
	llvm::BasicBlock *new_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	expr->codegen(cg);

	std::vector<llvm::BasicBlock *> case_bbs;
	for (auto &e: this->case_expr_list->case_expr_list) {
		llvm::BasicBlock *case_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
		case_bbs.push_back(case_bb);
		cg->set_local_cbb(case_bb);
		e->stmt->codegen(cg);
		cg->ir_builder->CreateBr(new_bb);
	}

	cg->set_local_cbb(old_bb);
	for (int i = 0; i < case_bbs.size(); i++) {
		llvm::BasicBlock *next_bb = new_bb;
		if (i < case_bbs.size()-1)
			next_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
		auto exp = this->case_expr_list->case_expr_list[i];
		llvm::Value *cond;
		if (exp->type == CaseExpr::CONST) {
			cond = cg->to_llvm_constant(exp->const_value);
		} else {
			exp->idd->codegen(cg);
			cond = cg->load_variable(cg->get_record_member(exp->idd->re_mem));
		}
		cond = cg->ir_builder->CreateICmpEQ(expr->llvm_val, cond);
		cg->ir_builder->CreateCondBr(cond, case_bbs[i], next_bb);
		cg->set_local_cbb(next_bb);
	}
}

void CaseExprList::codegen(CodeGenerator *cg) {

}

void CaseExpr::codegen(CodeGenerator *cg) {

}

void GotoStmt::codegen(CodeGenerator *cg) {

}

void ProcStmt::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
	std::vector<llvm::Value*> args;
	if (this->type == ProcStmt::ID_WITH_ARGS) {
		for (auto &e: args_list->args_list) {
			args.push_back(e->llvm_val);
		}
	}
	cg->make_call(id->idt, args);
}

void AssignStmt::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
	llvm::Value *v, *val;
	if (this->type == AssignStmt::ARRAY) {
		v = cg->get_record_member_el(idd->re_mem, this->e1->llvm_val);
		val = e2->llvm_val;
	} else {
		v = cg->get_record_member(idd->re_mem);
		if (this->ptr) {
			v = cg->load_variable(v);
		}
		val = e1->llvm_val;
	}
	cg->ir_builder->CreateStore(val, v);
}

void IfStmt::codegen(CodeGenerator *cg) {
	llvm::BasicBlock *old_bb = cg->local_cbb();
	llvm::BasicBlock *new_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	llvm::BasicBlock *true_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	expr->codegen(cg);
	cg->set_local_cbb(true_bb);
	stmt->codegen(cg);
	cg->ir_builder->CreateBr(new_bb);

	llvm::BasicBlock *false_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	cg->set_local_cbb(false_bb);
	else_clause->codegen(cg);
	cg->ir_builder->CreateBr(new_bb);

	cg->set_local_cbb(old_bb);
	cg->ir_builder->CreateCondBr(expr->llvm_val, true_bb, false_bb);
	cg->set_local_cbb(new_bb);
}

void ElseClause::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void RepeatStmt::codegen(CodeGenerator *cg) {
	llvm::BasicBlock *old_bb = cg->local_cbb();
	llvm::BasicBlock *new_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	llvm::BasicBlock *loop_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	cg->set_local_cbb(loop_bb);
	this->stmt_list->codegen(cg);
	this->expr->codegen(cg);
	llvm::Value *cond = cg->ir_builder->CreateICmpEQ(expr->llvm_val, cg->ir_builder->getTrue());
	cg->ir_builder->CreateCondBr(cond, new_bb, loop_bb);

	cg->set_local_cbb(old_bb);
	cg->ir_builder->CreateBr(loop_bb);
	cg->set_local_cbb(new_bb);
}

void WhileStmt::codegen(CodeGenerator *cg) {
	llvm::BasicBlock *old_bb = cg->local_cbb();
	llvm::BasicBlock *new_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	llvm::BasicBlock *cond_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	llvm::BasicBlock *loop_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	cg->ir_builder->SetInsertPoint(cond_bb);
	expr->codegen(cg);
	llvm::Value *cond = cg->ir_builder->CreateICmpEQ(expr->llvm_val, cg->ir_builder->getTrue());
	cg->ir_builder->CreateCondBr(cond, loop_bb, new_bb);
	cg->set_local_cbb(loop_bb);
	stmt->codegen(cg);
	cg->ir_builder->CreateBr(cond_bb);

	cg->set_local_cbb(old_bb);
	cg->ir_builder->CreateBr(cond_bb);
	cg->set_local_cbb(new_bb);
}

void ForStmt::codegen(CodeGenerator *cg) {
	llvm::BasicBlock *old_bb = cg->local_cbb();
	llvm::BasicBlock *new_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	llvm::BasicBlock *cond_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());
	llvm::BasicBlock *loop_bb = llvm::BasicBlock::Create(*cg->context, "", cg->local_bb()->getParent());

	idd->codegen(cg);
	expr1->codegen(cg);
	llvm::Value *loop_var_ptr = cg->get_record_member(idd->re_mem);
	cg->store_local_variable(loop_var_ptr, expr1->llvm_val);
	expr2->codegen(cg);
	cg->ir_builder->SetInsertPoint(cond_bb);
	llvm::Value *loop_var = cg->load_variable(loop_var_ptr);
	llvm::Value *cond = cg->ir_builder->CreateICmpSLE(loop_var, expr2->llvm_val);
	cg->ir_builder->CreateCondBr(cond, loop_bb, new_bb);
	cg->set_local_cbb(loop_bb);
	stmt->codegen(cg);
	loop_var = cg->ir_builder->CreateAdd(loop_var, cg->ir_builder->getInt32(1), loop_var->getName());
	cg->store_local_variable(loop_var_ptr, loop_var);
	cg->ir_builder->CreateBr(cond_bb);

	cg->set_local_cbb(old_bb);
	cg->ir_builder->CreateBr(cond_bb);
	cg->set_local_cbb(new_bb);
}

void SysProc::codegen(CodeGenerator *cg) {

}

void IDDotted::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

// Expressions
void Expression::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
	if (this->op == Expression::SINGLE) {
		this->llvm_val = expr->llvm_val;
	} else {
		auto v0 = expression->llvm_val;
		auto v1 = expr->llvm_val;
		if (this->op == Expression::GE) {
			if (this->resault_type == sem::REAL) {
				if (expression->resault_type != sem::REAL)
					v0 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v0, cg->getRealTy());
				if (expr->resault_type != sem::REAL)
					v1 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v1, cg->getRealTy());
				this->llvm_val = cg->ir_builder->CreateFCmpOGE(v0, v1);
			} else {
				this->llvm_val = cg->ir_builder->CreateICmpSGE(v0, v1);
			}
		} else if (this->op == Expression::GT) {
			if (this->resault_type == sem::REAL) {
				if (expression->resault_type != sem::REAL)
					v0 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v0, cg->getRealTy());
				if (expr->resault_type != sem::REAL)
					v1 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v1, cg->getRealTy());
				this->llvm_val = cg->ir_builder->CreateFCmpOGT(v0, v1);
			} else {
				this->llvm_val = cg->ir_builder->CreateICmpSGT(v0, v1);
			}
		} else if (this->op == Expression::LE) {
			if (this->resault_type == sem::REAL) {
				if (expression->resault_type != sem::REAL)
					v0 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v0, cg->getRealTy());
				if (expr->resault_type != sem::REAL)
					v1 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v1, cg->getRealTy());
				this->llvm_val = cg->ir_builder->CreateFCmpOLE(v0, v1);
			} else {
				this->llvm_val = cg->ir_builder->CreateICmpSLE(v0, v1);
			}
		} else if (this->op == Expression::LT) {
			if (this->resault_type == sem::REAL) {
				if (expression->resault_type != sem::REAL)
					v0 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v0, cg->getRealTy());
				if (expr->resault_type != sem::REAL)
					v1 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v1, cg->getRealTy());
				this->llvm_val = cg->ir_builder->CreateFCmpOLT(v0, v1);
			} else {
				this->llvm_val = cg->ir_builder->CreateICmpSLT(v0, v1);
			}
		} else if (this->op == Expression::EQ) {
			if (this->resault_type == sem::REAL) {
				if (expression->resault_type != sem::REAL)
					v0 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v0, cg->getRealTy());
				if (expr->resault_type != sem::REAL)
					v1 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v1, cg->getRealTy());
				this->llvm_val = cg->ir_builder->CreateFCmpOEQ(v0, v1);
			} else {
				this->llvm_val = cg->ir_builder->CreateICmpEQ(v0, v1);
			}
		} else if (this->op == Expression::NE) {
			if (this->resault_type == sem::REAL) {
				if (expression->resault_type != sem::REAL)
					v0 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v0, cg->getRealTy());
				if (expr->resault_type != sem::REAL)
					v1 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v1, cg->getRealTy());
				this->llvm_val = cg->ir_builder->CreateFCmpONE(v0, v1);
			} else {
				this->llvm_val = cg->ir_builder->CreateICmpNE(v0, v1);
			}
		}
	}
}

void Expr::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
	if (this->op == Expr::SINGLE) {
		this->llvm_val = term->llvm_val;
	} else {
		auto v0 = expr->llvm_val;
		auto v1 = term->llvm_val;
		if (this->op == Expr::PULS) {
			if (this->resault_type == sem::REAL) {
				if (expr->resault_type != sem::REAL)
					v0 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v0, cg->getRealTy());
				if (term->resault_type != sem::REAL)
					v1 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v1, cg->getRealTy());
				this->llvm_val = cg->ir_builder->CreateFAdd(v0, v1);
			} else {
				this->llvm_val = cg->ir_builder->CreateAdd(v0, v1);
			}
		} else if (this->op == Expr::MINUS) {
			if (this->resault_type == sem::REAL) {
				if (expr->resault_type != sem::REAL)
					v0 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v0, cg->getRealTy());
				if (term->resault_type != sem::REAL)
					v1 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v1, cg->getRealTy());
				this->llvm_val = cg->ir_builder->CreateFSub(v0, v1);
			} else {
				this->llvm_val = cg->ir_builder->CreateSub(v0, v1);
			}
		} else if (this->op == Expr::OR) {
			this->llvm_val = cg->ir_builder->CreateOr(v0, v1);
		}
	}
}

void Term::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
	if (this->op == Term::SINGLE) {
		this->llvm_val = factor->llvm_val;
	} else {
		auto v0 = term->llvm_val;
		auto v1 = factor->llvm_val;
		if (this->op == Term::AND) {
			this->llvm_val = cg->ir_builder->CreateAnd(v0, v1);
		} else if (this->op == Term::MUL) {
			if (this->resault_type == sem::REAL) {
				if (term->resault_type != sem::REAL)
					v0 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v0, cg->getRealTy());
				if (factor->resault_type != sem::REAL)
					v1 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v1, cg->getRealTy());
				this->llvm_val = cg->ir_builder->CreateFMul(v0, v1);
			} else {
				this->llvm_val = cg->ir_builder->CreateMul(v0, v1);
			}
		} else if (this->op == Term::DIV) {
			if (this->resault_type == sem::REAL) {
				if (term->resault_type != sem::REAL)
					v0 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v0, cg->getRealTy());
				if (factor->resault_type != sem::REAL)
					v1 = cg->ir_builder->CreateCast(llvm::Instruction::CastOps::SIToFP, v1, cg->getRealTy());
				this->llvm_val = cg->ir_builder->CreateFDiv(v0, v1);
			} else {
				this->llvm_val = cg->ir_builder->CreateSDiv(v0, v1);
			}
		} else if (this->op == Term::MOD) {
			this->llvm_val = cg->ir_builder->CreateSRem(v0, v1);
		}
	}
}

void Factor::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
	if (this->type == Factor::CONST_VALUE) {
		this->llvm_val = cg->to_llvm_constant(this->const_value);
	} else if (this->type == Factor::EXPRESSION) {
		this->llvm_val = this->expr->llvm_val;
	} else if (this->type == Factor::ARRAY) {
		this->llvm_val = cg->get_record_member_el(this->idd->re_mem, expr->llvm_val);
		this->llvm_val = cg->load_variable(llvm_val);
	} else if (this->type == Factor::MEMBER) {
		this->llvm_val = cg->get_record_member(this->idd->re_mem);
		this->llvm_val = cg->load_variable(llvm_val);
	} else if (this->type == Factor::NOT_FACTOR) {
		this->llvm_val = cg->ir_builder->CreateNot(this->factor->llvm_val);
	} else if (this->type == Factor::MINUS_FACTOR) {
		this->llvm_val = cg->ir_builder->CreateNeg(this->factor->llvm_val);
	} else if (this->type == Factor::FUNC_WITH_NO_ARGS) {
		this->llvm_val = cg->make_call(id1->idt);
	} else if (this->type == Factor::FUNC) {
		std::vector<llvm::Value*> args;
		for (auto &e: args_list->args_list) {
			args.push_back(e->llvm_val);
		}
		this->llvm_val = cg->make_call(id1->idt, args);
	} else if (this->type == Factor::ASTERISK) {
		this->llvm_val = cg->get_record_member(this->idd->re_mem);
		this->llvm_val = cg->load_variable(llvm_val);
		this->llvm_val = cg->load_variable(llvm_val);
	} else if (this->type == Factor::ADDR) {
		this->llvm_val = cg->get_record_member(this->idd->re_mem);
	} else if (this->type == Factor::ASTERISK_ARRAY) {
		this->llvm_val = cg->get_record_member_el(this->idd->re_mem, expr->llvm_val);
		this->llvm_val = cg->load_variable(llvm_val);
		this->llvm_val = cg->load_variable(llvm_val);
	} else if (this->type == Factor::ADDR_ARRAY) {
		this->llvm_val = cg->get_record_member_el(this->idd->re_mem, expr->llvm_val);
	}
}

void ArgsList::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
}

void ExprList::codegen(CodeGenerator *cg) {
	cg->gencode_children(this);
	if (!expr_list.empty())
		this->llvm_val = expr_list[expr_list.size()-1]->llvm_val;
}