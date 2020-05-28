#include "code_generator.h"

void CodeGenerator::gencode(Node *root) {
	// 初始化 LLVM
	this->context = new llvm::LLVMContext;
	this->module = new llvm::Module("main", *this->context);
	this->ir_builder = new llvm::IRBuilder<>(*this->context);

//	root->codegen(this);
}

//void CodeGenerator::set_local_variable() {
//
//}

//llvm::Constant *CodeGenerator::get_constant() {
//	return nullptr;
//}
//
//
//llvm::Value* Program::codegen(CodeGenerator *cg) {
//	program_heading->codegen(cg);
//	routine->codegen(cg);
//
//	return nullptr;
//}
//
//llvm::Value* ProgramHeading::codegen(CodeGenerator *cg) {
//	std::string &program_name = program_ID->name;
//	llvm::FunctionType *func_type = llvm::FunctionType::get(llvm::Type::getVoidTy(*cg->context), false);
//	llvm::Function *func = llvm::Function::Create(func_type, llvm::Function::InternalLinkage, program_name, cg->module);
//	llvm::BasicBlock *bb = llvm::BasicBlock::Create(*cg->context, CodeGenerator::get_entry_name(program_name), func);
//	cg->ir_builder->SetInsertPoint(bb);
//
//	return nullptr;
//}
//
//llvm::Value* Routine::codegen(CodeGenerator *cg) {
//	routine_head->codegen(cg);
//	routine_body->codegen(cg);
//	return nullptr;
//}
//
//llvm::Value* RoutineHead::codegen(CodeGenerator *cg) {
//	for (auto child: get_descendants()) {
//		child->codegen(cg);
//	}
//	this->sem_analyze(cg->top_sem());
//
//
//	return nullptr;
//}
//
//llvm::Value* LabelPart::codegen(CodeGenerator *cg) {
//
//	this->sem_analyze(cg->top_sem());
//
//	return nullptr;
//}
//
//llvm::Value* ConstPart::codegen(CodeGenerator *cg) {
//	if (!is_empty) {
//		const_expr_list->codegen(cg);
//	}
//	this->sem_analyze(cg->top_sem());
//	return nullptr;
//}
//
//llvm::Value* ConstExprList::codegen(CodeGenerator *cg) {
//	for (auto child: const_expr_list) {
//		child->codegen(cg);
//	}
//	this->sem_analyze(cg->top_sem());
//	return nullptr;
//}
//
//llvm::Value* ConstExpr::codegen(CodeGenerator *cg) {
//	this->sem_analyze(cg->top_sem());
//	std::string &const_name = id->idt;
//
//	switch (const_value->type) {
//		case ConstValue::INTEGER:
//
//			break;
//		case ConstValue::REAL:
//			break;
//		case ConstValue::CHAR:
//			break;
//		case ConstValue::STRING:
//			break;
//		case ConstValue::SYSCON:
//			break;
//	}
//	return nullptr;
//}
//
//llvm::Value* TypePart::codegen(CodeGenerator *cg) {
//	if (!is_empty) {
//		type_dec_list->codegen(cg);
//	}
//	this->sem_analyze(cg->top_sem());
//	return nullptr;
//}
//
//llvm::Value* TypeDecList::codegen(CodeGenerator *cg) {
//	for (auto type_decl: type_definition_list) {
//		type_decl->codegen(cg);
//	}
//	this->sem_analyze(cg->top_sem());
//	return nullptr;
//}
//
//llvm::Value* TypeDef::codegen(CodeGenerator *cg) {
//	for (auto child: get_descendants()) {
//		child->codegen(cg);
//	}
//	this->sem_analyze(cg->top_sem());
//
//	std::string &type_name = id->idt;
//
//	return nullptr;
//}