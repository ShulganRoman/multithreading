file(GLOB_RECURSE DATABASE_LIB "*.cpp")
add_library(db ${DATABASE_LIB})
target_include_directories(db PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/requests)
