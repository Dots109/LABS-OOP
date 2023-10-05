#include "../include/Hex.hpp"

#include <gtest/gtest.h>

bool constructorTest()
{
    Hex s1{'1', '2', '3'};
    std::string test = "123";
    Hex s2(test);
    Hex s3{'3', '6', '1'}, s4(s3);
    Hex s5{'0', '0', '0'}, s6("000");

    return (s1 == s2) && (s3 == s4) && (s5 == s6);
}

TEST(test_01, thorw_constructor_test)
{
    ASSERT_THROW(Hex s1("50J"), std::range_error);
}

TEST(test_02, throw_constrctor_test)
{

    ASSERT_THROW(Hex s1("f&k*"), std::range_error);
}

TEST(test_03, throw_constrctor_test)
{
    std::string test = "24 1";

    EXPECT_THROW(Hex s1(test), std::range_error);
}

TEST(test_10, basic_arithmetic_plus_test)
{
    Hex s1{'F', '2', '3'};
    Hex s2{'2', 'E', '5'};
    Hex s3{'1', '2', '0', '8'};

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_11, big_arithmetic_plus_test)
{
    Hex s1{'F', '2', '3', 'E', '2', '5', 'A', '4'};
    Hex s2{'A', '3', 'C', '0', '0', '6'};
    Hex s3{'F', '2', 'E', '1', 'E', '5', 'A', 'A'};

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_12, small_arithmetic_plus_test)
{
    Hex s1{'6'};
    Hex s2{'E', '3', '5'};
    Hex s3{'E', '3', 'B'};

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_13, zero_arithmetic_plus_test)
{
    Hex s1{'0', '0', '0', '5'};
    Hex s2{'2', '3', '5'};
    Hex s3("23A");

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_20, big_arithmetic_minus_test)
{
    std::string a = "65412321";
    std::string b = "40021";
    std::string c = "653D2300";
    Hex s1(a);
    Hex s2(b);
    Hex s3(c);

    ASSERT_TRUE((s1 - s2) == s3);
}

TEST(test_21, result0)
{
    std::string a = "FFFF";
    std::string b = "FFFF";
    std::string c = "0";
    Hex s1(a);
    Hex s2(b);
    Hex s3(c);

    ASSERT_TRUE((s1 - s2) == s3);
}

TEST(test_22, big_sub_arithmetic_minus_test)
{
    Hex s1{'1', '3', '4'};
    Hex s2{'6', '1', '2', '1', '1', '0'};

    EXPECT_THROW((s1 - s2), std::range_error);
}

TEST(test_23, big_sub_arithmetic_minus_test)
{
    Hex s1{'6', '6', '1', '0', '1', 'F'};
    Hex s2{'6', '1', '6', '1', '1', '0'};
    Hex s3("4AF0F");

    ASSERT_TRUE((s1 - s2) == s3);
}

TEST(test_24, boolean_operator_equal_test)
{
    Hex s1{'1', '2', '3'};
    Hex s2{'1', '2', '3'};

    ASSERT_TRUE((s1 == s2) == true);
}

TEST(test_25, boolean_operator_not_equal_test)
{
    Hex s1{'F', '1', '3'};
    Hex s2{'2', 'E', '3'};

    ASSERT_TRUE((s1 != s2) == true);
}

TEST(test_26, boolean_operator_more_test)
{
    Hex s1{'F', '2', '3'};
    Hex s2{'1', '2', 'D'};

    ASSERT_TRUE((s1 > s2) == true);
}

TEST(test_27, boolean_operator_less_test)
{
    Hex s1{'F', '2', '3'};
    Hex s2{'1', 'D', '3'};

    ASSERT_TRUE((s2 < s1) == true);
}

TEST(test_34, boolean_operator_more_equal_test)
{
    Hex s1{'3', '2', '3'};
    Hex s2{'1', '2', '3'};
    Hex s3{'1', '2', '3'};

    ASSERT_TRUE(((s1 >= s2) && (s2 >= s3)) == true);
}

TEST(test_28, boolean_operator_less_equal_test)
{
    Hex s1{'3', '2', '3'};
    Hex s2{'1', '2', '3'};
    Hex s3{'1', '2', '3'};

    ASSERT_TRUE(((s2 <= s1) && (s2 <= s3)) == true);
}

TEST(test_29, add_with_assign_operator_test)
{
    Hex s1{'3', '2', '3'};
    Hex s2{'1', '1', '1'};
    Hex s3{'3', '2', '3'};
    s3 = s3 + s2;

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_30, sub_with_assign_operator_test)
{
    Hex s1{'3', '2', '3'};
    Hex s2{'1', '1', '1'};
    Hex s3{'3', '2', '3'};
    s3 = s3 - s2;

    ASSERT_TRUE(s3 == s3);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}