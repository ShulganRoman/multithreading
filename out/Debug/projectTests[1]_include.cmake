if(EXISTS "/Users/romanshulgan/reps/multithreading/out/Debug/projectTests[1]_tests.cmake")
  include("/Users/romanshulgan/reps/multithreading/out/Debug/projectTests[1]_tests.cmake")
else()
  add_test(projectTests_NOT_BUILT projectTests_NOT_BUILT)
endif()
