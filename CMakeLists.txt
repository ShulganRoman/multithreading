cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0167 NEW)
project(project)
set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)
pkg_check_modules(PQXX REQUIRED libpqxx)
include_directories(${PQXX_INCLUDE_DIRS})
link_directories(${PQXX_LIBRARY_DIRS})

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(projectLib ${SOURCES})
target_link_libraries(projectLib ${Boost_LIBRARIES} ${PQXX_LIBRARIES})

add_executable(project ${SOURCES})
target_link_libraries(project PRIVATE ${Boost_LIBRARIES} ${PQXX_LIBRARIES})

find_package(Catch2 REQUIRED)
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

include(cmake/UpdateSubmodules.cmake)
add_subdirectory(external)

include(CTest)
if(TEST_SOURCES)
  add_executable(projectTests ${TEST_SOURCES})
  target_link_libraries(projectTests PRIVATE GTest::gtest_main
                                                     projectLib)
  include(GoogleTest)
  gtest_discover_tests(projectTests)
endif()
