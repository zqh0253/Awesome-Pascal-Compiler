add_custom_target(
		apc-test
		COMMAND apc < ${CMAKE_CURRENT_SOURCE_DIR}/pasfile/stmtTest.pas
		DEPENDS apc
)

add_custom_target(
		apc-test-gen-func
		COMMAND apc < ${CMAKE_CURRENT_SOURCE_DIR}/pasfile/gen_func.pas
		DEPENDS apc
)

add_custom_target(
		apc-test-gen-exp
		COMMAND apc < ${CMAKE_CURRENT_SOURCE_DIR}/pasfile/gen_exp.pas
		DEPENDS apc
)

add_custom_target(
		apc-test-gen-type
		COMMAND apc < ${CMAKE_CURRENT_SOURCE_DIR}/pasfile/gen_type.pas
		DEPENDS apc
)

add_custom_target(
		apc-test-gen-pointer
		COMMAND apc < ${CMAKE_CURRENT_SOURCE_DIR}/pasfile/gen_pointer.pas
		DEPENDS apc
)


add_custom_target(
		apc-test-sem
		COMMAND apc < ${CMAKE_CURRENT_SOURCE_DIR}/pasfile/typeTest.pas
		DEPENDS apc
)