add_library(bmp bmp.c)

# Tests
add_executable(bmp_test test.c)
target_link_libraries(bmp_test bmp)
set_target_properties(bmp_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../../target/test)
file(COPY test_files/MARBLES.bmp DESTINATION ../../target/test)