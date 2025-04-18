file(GLOB_RECURSE DATABASE_LIB "*.h")
add_library(db INTERFACE ${DATABASE_LIB})

target_include_directories(db INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(db INTERFACE user chat)
