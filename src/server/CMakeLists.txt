file(GLOB_RECURSE SERVER_LIB "*.cpp")
add_library(server ${SERVER_LIB})

target_link_libraries(server exception user chat db)
target_include_directories(server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

