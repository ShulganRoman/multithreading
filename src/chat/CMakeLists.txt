file(GLOB_RECURSE CHAT_LIB "*.cpp")
add_library(chat ${CHAT_LIB})
target_include_directories(chat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
