add_executable(
  IteratorsTest
  gtest_main.cpp
  IteratorsEqual_Test.cpp
  IteratorsCopy_Test.cpp
  IteratorsFind_Test.cpp
  IteratorsRemoveCopyIf_Test.cpp
)
target_link_libraries(IteratorsTest ${GTEST_LIBRARIES})

#add_test(AllTestsInIterators_Unit Iterators_Unit)
