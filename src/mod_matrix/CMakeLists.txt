add_library(mod_matrix mod_matrix.c)

# Tests
add_executable(mod_matrix_test test.c)
target_link_libraries(mod_matrix_test mod)
target_link_libraries(mod_matrix_test mod_matrix)
set_target_properties(mod_matrix_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../../target/test)