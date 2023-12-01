

#include <algorithm>
#include <array>
#include <ranges>
#include <string_view>

namespace
{
static constexpr std::array<std::string_view, 19> digits = {"0",    "1",   "2",     "3",     "4",   "5",     "6",
                                                            "7",    "8",   "9",     "one",   "two", "three", "four",
                                                            "five", "six", "seven", "eight", "nine"};

constexpr auto to_digit(std::string_view str)
{
    // Find the digit which is prefix of our current string (if any)
    auto match = std::ranges::find_if(digits, [&](auto &&digit) { return str.starts_with(digit); });
    if (match == digits.end())
        return -1;

    // Turn the position in the array of digits into a digit
    const auto digit = static_cast<int>(std::distance(digits.begin(), match));
    if (digit >= 10)
        return digit - 9;
    return digit;
}
} // namespace

namespace part_two
{
constexpr auto spelled_out(std::string_view document)
{
    return std::ranges::fold_left(document | std::views::split('\n'), 0, [&](int64_t acc, auto &&line) {
        int64_t first = -1;
        int64_t last = -1;
        // We want to iterate over all the suffixes
        for (const auto &pos : std::views::iota(line.begin(), line.end()))
        {
            // Current suffix
            auto substr = std::string_view(pos, line.end());

            // Check if it begins with a digit and update first and last
            if (int64_t digit = to_digit(substr); digit != -1)
            {
                if (first == -1)
                    first = digit;
                last = digit;
            }
        }
        return acc + first * 10 + last;
    });
}
} // namespace part_two

namespace test
{
constexpr auto test2_input = R"(two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen)";

static_assert(part_two::spelled_out(test2_input) == 281);

} // namespace test
