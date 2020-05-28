add_custom_command(
		OUTPUT scanner.cpp
		COMMAND flex -o scanner.cpp ${CMAKE_CURRENT_SOURCE_DIR}/pascal.l
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/pascal.l pascal.hpp
)

add_custom_command(
		OUTPUT pascal.cpp pascal.hpp
		COMMAND bison -d -o pascal.cpp ${CMAKE_CURRENT_SOURCE_DIR}/pascal.y
		DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/pascal.y
)

add_library(parser scanner.cpp pascal.cpp)
target_link_libraries(parser ast)