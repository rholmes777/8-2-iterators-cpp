cmake_minimum_required (VERSION 2.8)
project (iterators_8_2)

# Ubuntu allows us to get gcc 4.7 from this repo:
# sudo add-apt-repository ppa:ubuntu-toolchain-r/test
set(CMAKE_CXX_COMPILER g++-4.7)

# increase warn level
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CSS_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")


#enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ./8-2-iterators-impl)


set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)

add_subdirectory(8-2-iterators-impl)
add_subdirectory(Unit-GTests)

