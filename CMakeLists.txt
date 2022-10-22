cmake_minimum_required(VERSION 3.14)
project(BSTree)

# executable
set(EXEC_NAME bstree)
set(SOURCES BSTree.cpp Iterators.cpp testsBSTree.cpp BSTree.h)
add_executable(${EXEC_NAME} ${SOURCES})

# coverage; make coverage
set(CMAKE_CXX_FLAGS "--coverage")
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/${EXEC_NAME}.dir)
add_custom_target(coverage
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
add_custom_command(TARGET coverage
    COMMAND echo "=================== COVERAGE ===================="
    COMMAND lcov -t "${EXEC_NAME}" -o ${EXEC_NAME}.info -c -d ${OBJECT_DIR} --rc lcov_branch_coverage=1
    COMMAND genhtml -o report ${EXEC_NAME}.info --rc lcov_branch_coverage=1;
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage
    )

add_dependencies(coverage ${EXEC_NAME})

# ${CMAKE_BINARY_DIR}/CMakeFiles/tester.dir/
