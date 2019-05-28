add_library(algorithms algorithms.c)

# Tests
add_executable(algorithms_test test.c)
target_link_libraries(algorithms_test mod_matrix)
target_link_libraries(algorithms_test mod)
target_link_libraries(algorithms_test algorithms)
set_target_properties(algorithms_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../../target/test)