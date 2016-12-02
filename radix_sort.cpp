//          Copyright Malte Skarupke 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See http://www.boost.org/LICENSE_1_0.txt)

#include "radix_sort.hpp"

#ifndef DISABLE_GTEST

#include <vector>
#include <gtest/gtest.h>

TEST(counting_sort, simple)
{
    std::vector<uint8_t> to_sort = { 5, 6, 19, 2, 5, 0, 7, 23, 6, 8, 99 };
    std::vector<uint8_t> result(to_sort.size());
    counting_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    std::sort(to_sort.begin(), to_sort.end());
    ASSERT_EQ(to_sort, result);
}

TEST(counting_sort, string)
{
    std::string to_sort = "Hello, World!";
    std::string result = to_sort;
    counting_sort(to_sort.begin(), to_sort.end(), result.begin());
    std::sort(to_sort.begin(), to_sort.end());
    ASSERT_EQ(to_sort, result);
}

TEST(radix_sort, uint8)
{
    std::vector<uint8_t> to_sort = { 5, 6, 19, 2, 5, 0, 7, 23, 6, 255, 8, 99 };
    std::vector<uint8_t> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, uint8_256_items)
{
    std::vector<uint8_t> to_sort(256, 254);
    to_sort.back() = 255;
    std::vector<uint8_t> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, int8)
{
    std::vector<int8_t> to_sort = { 5, 6, 19, -4, 2, 5, 0, -55, 7, 23, 6, 8, 127, -128, 99 };
    std::vector<int8_t> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, text)
{
    std::string to_sort = "Hello, World!";
    std::string result(to_sort.size(), ' ');
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto c){ return c; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, u16string)
{
    std::u16string to_sort = u"Hello, World!";
    std::u16string result(to_sort.size(), ' ');
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto c){ return c; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, u32string)
{
    std::u32string to_sort = U"Hello, World!";
    std::u32string result(to_sort.size(), ' ');
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto c){ return c; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, int16)
{
    std::vector<int16_t> to_sort = { 5, 6, 19, -4, 2, 5, 0, -55, 7, 1000, 23, 6, 8, 127, -128, -129, -256, -32768, 32767, 99 };
    std::vector<int16_t> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, uint16)
{
    std::vector<uint16_t> to_sort = { 5, 6, 19, 2, 5, 7, 0, 23, 6, 256, 255, 8, 99, 1024, 65535, 65534 };
    std::vector<uint16_t> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, int32)
{
    std::vector<int32_t> to_sort = { 5, 6, 19, -4, 2, 5, 0, -55, 7, 1000, 23, 6, 8, 127, -128, -129, -256, 32768, -32769, -32768, 32767, 99, 1000000, -1000001, std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max(), std::numeric_limits<int>::max() - 1, std::numeric_limits<int>::lowest() + 1 };
    std::vector<int32_t> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}
TEST(radix_sort, uint32)
{
    std::vector<uint32_t> to_sort = { 5, 6, 19, 2, 5, 7, 0, 23, 6, 256, 255, 8, 99, 1024, 65536, 65535, 65534, 1000000, std::numeric_limits<unsigned int>::max() };
    std::vector<uint32_t> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}
TEST(radix_sort, int64)
{
    std::vector<int64_t> to_sort = { 5, 6, 19, std::numeric_limits<std::int32_t>::lowest() - 1, std::numeric_limits<ino64_t>::lowest(), -1000000000000, 1000000000000, std::numeric_limits<int32_t>::max(), std::numeric_limits<int64_t>::max(), -4, 2, 5, 0, -55, 7, 1000, 23, 6, 8, 127, -128, -129, -256, 32768, -32769, -32768, 32767, 99, 1000000, -1000001, std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max(), std::numeric_limits<int>::max() - 1, std::numeric_limits<int>::lowest() + 1 };
    std::vector<int64_t> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}
TEST(radix_sort, uint64)
{
    std::vector<uint64_t> to_sort = { 5, 6, 19, 2, 5, 7, 0, std::numeric_limits<uint32_t>::max() + 1, 1000000000000, std::numeric_limits<uint64_t>::max(), 23, 6, 256, 255, 8, 99, 1024, 65536, 65535, 65534, 1000000, std::numeric_limits<unsigned int>::max() };
    std::vector<uint64_t> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}
TEST(radix_sort, float)
{
    std::vector<float> to_sort = { 5, 6, 19, std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity(), -4, 2, 5, 0, -55, 7, 1000, 23, 6, 8, 127, -128, -129, -256, 32768, -32769, -32768, 32767, 99, 1000000, -1000001, 0.1f, 2.5f, 17.8f, -12.4f, -0.0000002f, -0.0f, -777777777.7f, 444444444444.4f };
    std::vector<float> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}
TEST(radix_sort, double)
{
    std::vector<double> to_sort = { 5, 6, 19, std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity(), -4, 2, 5, 0, -55, 7, 1000, 23, 6, 8, 127, -128, -129, -256, 32768, -32769, -32768, 32767, 99, 1000000, -1000001, 0.1, 2.5, 17.8, -12.4, -0.0000002, -0.0, -777777777.7, 444444444444.4 };
    std::vector<double> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}
TEST(radix_sort, pair)
{
    std::vector<std::pair<int, bool>> to_sort = { { 5, true }, { 5, false }, { 6, false }, { 7, true }, { 4, false }, { 4, true } };
    std::vector<std::pair<int, bool>> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, pair_other_direction)
{
    std::vector<std::pair<bool, int>> to_sort = { { true, 5 }, { false, 5 }, { false, 6 }, { true, 7 }, { false, 4 }, { true, 4 } };
    std::vector<std::pair<bool, int>> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, tuple)
{
    std::vector<std::tuple<bool, int, bool>> to_sort = { std::tuple<bool, int, bool>{ true, 5, true }, std::tuple<bool, int, bool>{ true, 5, false }, std::tuple<bool, int, bool>{ false, 6, false }, std::tuple<bool, int, bool>{ true, 7, true }, std::tuple<bool, int, bool>{ true, 4, false }, std::tuple<bool, int, bool>{ false, 4, true }, std::tuple<bool, int, bool>{ false, 5, false } };
    std::vector<std::tuple<bool, int, bool>> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto i){ return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}
TEST(radix_sort, reference)
{
    std::vector<int> to_sort = { 6, 5, 4, 3, 2, 1 };
    std::vector<int> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](int & i) -> int & { return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}
TEST(radix_sort, pair_reference)
{
    std::vector<std::pair<int, bool>> to_sort = { { 5, true }, { 5, false }, { 6, false }, { 7, true }, { 4, false }, { 4, true } };
    std::vector<std::pair<int, bool>> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto & i) -> decltype(auto) { return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(to_sort, result);
}
TEST(radix_sort, tuple_reference)
{
    std::vector<std::tuple<bool, int, bool>> to_sort = { std::tuple<bool, int, bool>{ true, 5, true }, std::tuple<bool, int, bool>{ true, 5, false }, std::tuple<bool, int, bool>{ false, 6, false }, std::tuple<bool, int, bool>{ true, 7, true }, std::tuple<bool, int, bool>{ true, 4, false }, std::tuple<bool, int, bool>{ false, 4, true }, std::tuple<bool, int, bool>{ false, 5, false } };
    std::vector<std::tuple<bool, int, bool>> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto & i) -> decltype(auto) { return i; });
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}
TEST(radix_sort, std_array)
{
    std::vector<std::array<float, 4>> to_sort = { {{ 1.0f, 2.0f, 3.0f, 4.0f }}, {{ 0.0f, 3.0f, 4.0f, 5.0f }}, {{ 1.0f, 1.5f, 2.0f, 2.5f }}, {{ 1.0f, 2.0f, 2.5f, 4.0f }}, {{ 1.0f, 2.0f, 2.5f, 3.5f }}, {{ 0.0f, 3.0f, 4.5f, 4.5f }} };
    std::vector<std::array<float, 4>> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin());
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}
TEST(radix_sort, move_only)
{
    std::vector<std::unique_ptr<int>> to_sort;
    to_sort.push_back(std::make_unique<int>(5));
    to_sort.push_back(std::make_unique<int>(0));
    to_sort.push_back(std::make_unique<int>(1234567));
    to_sort.push_back(std::make_unique<int>(-1000));
    std::vector<int> sorted;
    sorted.reserve(to_sort.size());
    for (const std::unique_ptr<int> & i : to_sort)
        sorted.push_back(*i);
    std::sort(sorted.begin(), sorted.end());
    std::vector<std::unique_ptr<int>> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin(), [](auto & i){ return *i; });
    for (size_t i = 0; i < sorted.size(); ++i)
    {
        if (which_buffer)
            ASSERT_EQ(sorted[i], *result[i]);
        else
            ASSERT_EQ(sorted[i], *to_sort[i]);
    }
}

TEST(radix_sort, vector_bool)
{
    std::vector<bool> to_sort = { true, false, true, true, false, true, true, true, false, true, false, false };
    std::vector<bool> result(to_sort.size());
    bool which_buffer = radix_sort(to_sort.begin(), to_sort.end(), result.begin());
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}

TEST(linear_sort, tuple)
{
    std::vector<std::tuple<bool, int, bool>> to_sort = { std::tuple<bool, int, bool>{ true, 5, true }, std::tuple<bool, int, bool>{ true, 5, false }, std::tuple<bool, int, bool>{ false, 6, false }, std::tuple<bool, int, bool>{ true, 7, true }, std::tuple<bool, int, bool>{ true, 4, false }, std::tuple<bool, int, bool>{ false, 4, true }, std::tuple<bool, int, bool>{ false, 5, false } };
    std::vector<std::tuple<bool, int, bool>> result = to_sort;
    bool which_buffer = linear_sort(to_sort.begin(), to_sort.end(), result.begin());
    if (which_buffer)
        std::sort(to_sort.begin(), to_sort.end());
    else
        std::sort(result.begin(), result.end());
    ASSERT_EQ(result, to_sort);
}

#endif

// benchmarks
#if 0

#include "benchmark/benchmark.h"

#include <random>
#include <deque>
#if 0
static std::vector<int32_t> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::vector<int32_t> result;
    result.reserve(size);
    std::uniform_int_distribution<int32_t> distribution;
    for (int i = 0; i < size; ++i)
    {
        result.push_back(distribution(randomness));
    }
    return result;
}
#elif 1
static std::vector<std::pair<bool, float>> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::vector<std::pair<bool, float>> result;
    result.reserve(size);
    std::uniform_int_distribution<int> int_distribution(0, 1);
    std::uniform_real_distribution<float> real_distribution;
    for (int i = 0; i < size; ++i)
    {
        result.emplace_back(int_distribution(randomness) != 0, real_distribution(randomness));
    }
    return result;
}
#elif 0
static std::deque<bool> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::deque<bool> result;
    std::uniform_int_distribution<int> int_distribution(0, 1);
    for (int i = 0; i < size; ++i)
    {
        result.emplace_back(int_distribution(randomness) != 0);
    }
    return result;
}
#elif 0
static std::vector<std::int8_t> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::vector<std::int8_t> result;
    result.reserve(size);
    std::uniform_int_distribution<std::int8_t> int_distribution(-128, 127);
    for (int i = 0; i < size; ++i)
    {
        result.emplace_back(int_distribution(randomness));
    }
    return result;
}
#elif 0
static std::vector<std::int16_t> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::vector<std::int16_t> result;
    result.reserve(size);
    std::uniform_int_distribution<std::int16_t> int_distribution(-32768, 32767);
    for (int i = 0; i < size; ++i)
    {
        result.emplace_back(int_distribution(randomness));
    }
    return result;
}
#elif 0
static std::vector<std::int64_t> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::vector<std::int64_t> result;
    result.reserve(size);
    std::uniform_int_distribution<std::int64_t> int_distribution(std::numeric_limits<int64_t>::lowest(), std::numeric_limits<int64_t>::max());
    for (int i = 0; i < size; ++i)
    {
        result.emplace_back(int_distribution(randomness));
    }
    return result;
}
#elif 0
static std::vector<std::tuple<std::int64_t, std::int64_t>> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::vector<std::tuple<std::int64_t, std::int64_t>> result;
    result.reserve(size);
    std::uniform_int_distribution<std::int64_t> int_distribution(std::numeric_limits<int64_t>::lowest(), std::numeric_limits<int64_t>::max());
    for (int i = 0; i < size; ++i)
    {
        result.emplace_back(int_distribution(randomness), int_distribution(randomness));
    }
    return result;
}
#elif 0
static std::vector<std::tuple<std::int32_t, std::int32_t, std::int64_t>> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::vector<std::tuple<std::int32_t, std::int32_t, std::int64_t>> result;
    result.reserve(size);
    std::uniform_int_distribution<std::int32_t> int32_distribution(std::numeric_limits<int32_t>::lowest(), std::numeric_limits<int32_t>::max());
    std::uniform_int_distribution<std::int64_t> int64_distribution(std::numeric_limits<int64_t>::lowest(), std::numeric_limits<int64_t>::max());
    for (int i = 0; i < size; ++i)
    {
        result.emplace_back(int32_distribution(randomness), int32_distribution(randomness), int64_distribution(randomness));
    }
    return result;
}
#else
template<size_t Size>
struct SizedStruct
{
    uint8_t array[Size] = {};
};
template<>
struct SizedStruct<0>
{
};
// 1 1
// benchmark_radix_sort/2k      15584 ns      15584 ns      45023
// benchmark_std_sort/2k        81390 ns      81387 ns       8402
// 1 4
// benchmark_radix_sort/2k      18295 ns      18294 ns      38503
// benchmark_std_sort/2k        88495 ns      88490 ns       7884
// 1 16
// benchmark_radix_sort/2k      24150 ns      24149 ns      29040
// benchmark_std_sort/2k        99820 ns      99816 ns       7030
// 1 64
// benchmark_radix_sort/2k      57376 ns      57374 ns      11904
// benchmark_std_sort/2k       140581 ns     140572 ns       4871
// 1 256
// benchmark_radix_sort/2k     143925 ns     143918 ns       4872
// benchmark_std_sort/2k       413432 ns     413412 ns       1697
// 4 4
// benchmark_radix_sort/2k      23582 ns      23581 ns      30160
// benchmark_std_sort/2k        86721 ns      86717 ns       8127
// 4 16
// benchmark_radix_sort/2k      39676 ns      39674 ns      17607
// benchmark_std_sort/2k        97408 ns      97403 ns       7164
// 4 64
// benchmark_radix_sort/2k     119144 ns     119138 ns       5932
// benchmark_std_sort/2k       137889 ns     137882 ns       4997
// 4 256
// benchmark_radix_sort/2k     340898 ns     340881 ns       2079
// benchmark_std_sort/2k       442650 ns     442628 ns       1585
// 16 16
// benchmark_radix_sort/2k     123524 ns     123519 ns       5533
// benchmark_std_sort/2k       111651 ns     111647 ns       6335
// 16 64
// benchmark_radix_sort/2k     346659 ns     346640 ns       1991
// benchmark_std_sort/2k       150146 ns     150128 ns       4537
// 16 256
// benchmark_radix_sort/2k    1194784 ns    1194713 ns        589
// benchmark_std_sort/2k       459288 ns     459260 ns       1545
// 64 64
// benchmark_radix_sort/2k    1881615 ns    1880636 ns        379
// benchmark_std_sort/2k       254113 ns     254002 ns       2770
// 64 256
// benchmark_radix_sort/2k    5500901 ns    5500572 ns        113
// benchmark_std_sort/2k       577450 ns     577417 ns       1203
// 256 256
// benchmark_radix_sort/2k   17657334 ns   17656224 ns         40
// benchmark_std_sort/2k       698080 ns     698040 ns       1008

#define SORT_ON_FIRST_ONLY
typedef std::int64_t benchmark_sort_key;
#define NUM_SORT_KEYS 1
typedef SizedStruct<0> benchmark_sort_value;
#if NUM_SORT_KEYS == 1
static std::vector<std::tuple<benchmark_sort_key, benchmark_sort_value>> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::vector<std::tuple<benchmark_sort_key, benchmark_sort_value>> result;
    result.reserve(size);
    std::uniform_int_distribution<benchmark_sort_key> distribution(std::numeric_limits<benchmark_sort_key>::lowest(), std::numeric_limits<benchmark_sort_key>::max());
    for (int i = 0; i < size; ++i)
    {
        result.emplace_back(distribution(randomness), benchmark_sort_value());
    }
    return result;
}
#elif NUM_SORT_KEYS == 2
static std::vector<std::tuple<std::pair<benchmark_sort_key, benchmark_sort_key>, benchmark_sort_value>> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::vector<std::tuple<std::pair<benchmark_sort_key, benchmark_sort_key>, benchmark_sort_value>> result;
    result.reserve(size);
    std::uniform_int_distribution<benchmark_sort_key> distribution(std::numeric_limits<benchmark_sort_key>::lowest(), std::numeric_limits<benchmark_sort_key>::max());
    for (int i = 0; i < size; ++i)
    {
        result.emplace_back(std::make_pair(distribution(randomness), distribution(randomness)), benchmark_sort_value());
    }
    return result;
}
#else
static std::vector<std::tuple<std::array<benchmark_sort_key, NUM_SORT_KEYS>, benchmark_sort_value>> create_radix_sort_data(std::mt19937_64 & randomness, int size)
{
    std::vector<std::tuple<std::array<benchmark_sort_key, NUM_SORT_KEYS>, benchmark_sort_value>> result;
    result.reserve(size);
    std::uniform_int_distribution<benchmark_sort_key> distribution(std::numeric_limits<benchmark_sort_key>::lowest(), std::numeric_limits<benchmark_sort_key>::max());
    for (int i = 0; i < size; ++i)
    {
        std::array<benchmark_sort_key, NUM_SORT_KEYS> key;
        for (int i = 0; i < NUM_SORT_KEYS; ++i)
            key[i] = distribution(randomness);
        result.emplace_back(key, benchmark_sort_value());
    }
    return result;
}
#endif
#endif


static constexpr int profile_multiplier = 4;
static constexpr int max_profile_range = 2 << 15;

static void benchmark_radix_sort(benchmark::State & state)
{
    std::mt19937_64 randomness(77342348);
    auto buffer = create_radix_sort_data(randomness, state.range(0));
    while (state.KeepRunning())
    {
        auto to_sort = create_radix_sort_data(randomness, state.range(0));
#ifdef SORT_ON_FIRST_ONLY
        radix_sort(to_sort.begin(), to_sort.end(), buffer.begin(), [](auto && a){ return std::get<0>(a); });
#else
        bool which = radix_sort(to_sort.begin(), to_sort.end(), buffer.begin());
        if (which)
            assert(std::is_sorted(buffer.begin(), buffer.end()));
        else
            assert(std::is_sorted(to_sort.begin(), to_sort.end()));
#endif
    }
}
BENCHMARK(benchmark_radix_sort)->RangeMultiplier(profile_multiplier)->Range(profile_multiplier, max_profile_range);

static void benchmark_linear_sort(benchmark::State & state)
{
    std::mt19937_64 randomness(77342348);
    auto buffer = create_radix_sort_data(randomness, state.range(0));
    while (state.KeepRunning())
    {
        auto to_sort = create_radix_sort_data(randomness, state.range(0));
#ifdef SORT_ON_FIRST_ONLY
        linear_sort(to_sort.begin(), to_sort.end(), buffer.begin(), [](auto && a){ return std::get<0>(a); });
#else
        bool which = linear_sort(to_sort.begin(), to_sort.end(), buffer.begin());
        if (which)
            assert(std::is_sorted(buffer.begin(), buffer.end()));
        else
            assert(std::is_sorted(to_sort.begin(), to_sort.end()));
#endif
    }
}
BENCHMARK(benchmark_linear_sort)->RangeMultiplier(profile_multiplier)->Range(profile_multiplier, max_profile_range);

static void benchmark_std_sort(benchmark::State & state)
{
    std::mt19937_64 randomness(77342348);
    while (state.KeepRunning())
    {
        auto to_sort = create_radix_sort_data(randomness, state.range(0));
#ifdef SORT_ON_FIRST_ONLY
        std::sort(to_sort.begin(), to_sort.end(), [](auto && l, auto && r){ return std::get<0>(l) < std::get<0>(r); });
#else
        std::sort(to_sort.begin(), to_sort.end());
        assert(std::is_sorted(to_sort.begin(), to_sort.end()));
#endif
    }
}
BENCHMARK(benchmark_std_sort)->RangeMultiplier(profile_multiplier)->Range(profile_multiplier, max_profile_range);

#endif
