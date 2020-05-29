add_custom_target(
		apc-test
		COMMAND apc < ${CMAKE_CURRENT_SOURCE_DIR}/pasfile/stmtTest.pas
		DEPENDS apc
)

add_custom_target(
		apc-test-gen
		COMMAND apc < ${CMAKE_CURRENT_SOURCE_DIR}/pasfile/gen.pas
		DEPENDS apc
)