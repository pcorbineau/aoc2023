add_library(day01-lib INTERFACE)
target_sources(day01-lib INTERFACE input.hpp part_one.hpp part_two.hpp)

add_executable(day01 main.cpp)
target_link_libraries(day01 PRIVATE day01-lib)
