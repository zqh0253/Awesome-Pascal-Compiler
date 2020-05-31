include_directories(.)
aux_source_directory(. SRCS)
add_library(ast ${SRCS})