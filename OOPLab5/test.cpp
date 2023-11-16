#include "findDivider.cpp"

#include <gtest/gtest.h>

TEST(test_01, notFind)
{
    ASSERT_TRUE(findDivider(5, 7)== 5);
}

TEST(test_02, lessThenZero)
{
    EXPECT_THROW(findDivider(-5, 35), std::range_error);
}

TEST(test_03, lessTthenZero2)
{
    EXPECT_THROW(findDivider(5, -35), std::range_error);
}

TEST(test_04, zeros)
{
    EXPECT_THROW(findDivider(0, 0), std::range_error);
}

TEST(test_05, norm)
{
    ASSERT_TRUE(findDivider(2, 6)==6);
}

TEST(test_06, bigNorm)
{
    ASSERT_TRUE(findDivider(4389, 52400)==48279);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}