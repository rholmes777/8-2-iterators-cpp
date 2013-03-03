cmake_minimum_required (VERSION 2.8)
project (iterators_8_2)

set(CMAKE_CXX_COMPILER g++-4.6)

#enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ./8-2-iterators-impl)

set(TEST_SRC ./Unit-GTests)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++0x)

add_executable(
  IteratorsTest
  ${TEST_SRC}/gtest_main.cpp 
  ${TEST_SRC}/IteratorsEqual_Test.cpp 
  ${TEST_SRC}/IteratorsCopy_Test.cpp 
  ${TEST_SRC}/IteratorsFind_Test.cpp
)
target_link_libraries(IteratorsTest ${GTEST_LIBRARIES})

#add_test(AllTestsInIterators_Unit Iterators_Unit)
