#include <algorithm>
#include <array>
#include <ranges>
#include <string_view>

using namespace std::literals;

namespace part_one
{
constexpr auto calibration_values(std::string_view document)
{
    constexpr auto isntdigit = [](char c) { return (c < '0' || c > '9'); };
    constexpr auto first_digit = std::views::drop_while(isntdigit);
    constexpr auto last_digit = std::views::reverse | first_digit;

    // Treat the first element of a range of character as a decimal digit
    constexpr auto decimal = [](auto &&rng) { return *rng.begin() - '0'; };

    // Accumulate the converted calibration values
    return std::ranges::fold_left(document | std::views::split('\n'), 0, [&](auto &&acc, auto &&line) {
        return acc + decimal(line | first_digit) * 10 + decimal(line | last_digit);
    });
}
} // namespace part_one

namespace test
{
constexpr auto test1_input = R"(1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet)"sv;

static_assert(part_one::calibration_values(test1_input) == 142);
} // namespace test
