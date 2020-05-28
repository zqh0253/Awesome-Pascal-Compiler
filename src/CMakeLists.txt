include_directories(.)

add_executable(apc main.cpp)
target_link_libraries(apc ast gen parser sem)

add_subdirectory(ast)
add_subdirectory(gen)
add_subdirectory(parser)
add_subdirectory(sem)
