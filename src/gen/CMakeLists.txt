include_directories(.)
aux_source_directory(. SRCS)

# LLVM
execute_process(COMMAND llvm-config --libs OUTPUT_VARIABLE LLVM_LINK_LIBRARIES)
string(STRIP "${LLVM_LINK_LIBRARIES}" LLVM_LINK_LIBRARIES)

add_library(gen ${SRCS})
target_link_libraries(gen curses)
target_link_libraries(gen "${LLVM_LINK_LIBRARIES}")
