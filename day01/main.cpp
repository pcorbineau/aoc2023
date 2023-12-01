#include <print>

#include "input.hpp"
#include "part_one.hpp"
#include "part_two.hpp"

int main()
{
    std::print("The sum of calibration values is: {}\n", part_one::calibration_values(input::day01));
    std::print("The sum of calibration values with spelled out digits is: {}\n", part_two::spelled_out(input::day01));
}
