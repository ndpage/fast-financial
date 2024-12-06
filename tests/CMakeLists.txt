# Add tests using the Catch2 framework or GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_my_project test_main.cpp)
target_link_libraries(test_my_project PRIVATE ${Boost_LIBRARIES} GTest::GTest GTest::Main)

add_test(NAME my_project_tests COMMAND test_my_project)