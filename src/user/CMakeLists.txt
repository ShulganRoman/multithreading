file(GLOB_RECURSE USER_LIB "*.cpp")
add_library(user ${USER_LIB})
target_include_directories(user PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
