add_custom_target(
		apc-test
		COMMAND apc < ${CMAKE_CURRENT_SOURCE_DIR}/pasfile/stmtTest.pas
		DEPENDS apc
)