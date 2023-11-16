#include <gtest/gtest.h>
#include "../include/Vector.hpp"


TEST(constructor_test, default_constructor_test) {
    Vector<int> test_1; 

    EXPECT_TRUE(test_1.capacity() == 0);
    EXPECT_TRUE(test_1.size() == 0);
}

TEST(constructor_test, initializer_constructor_test) {
    Vector<int> test_1{1, 2, 3, 4, 5, 6};

    EXPECT_TRUE(test_1[0] == 1 && test_1[5] == 6);
}

TEST(constructor_test, copy_constructor_test) {

    Vector<int> test_1 {54,54,67,89,78,98};

    Vector<int> test_2 (test_1);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(assigment_operator_test, copy_rvalue_test) {
    Vector<int> test_1 {54,54,67,89,78,98};

    Vector<int> test_2 (std::move(test_1));

    EXPECT_TRUE(test_2[0] == 54 && test_2[1] == 54 && test_2[5] == 98);
}

TEST(reserve_test, empty_vector) {
    Vector<double> test_1;
    size_t capacity = 100;

    test_1.reserve(capacity); 

    EXPECT_EQ(test_1.capacity(), capacity);
}

TEST(resize_test, resize_vector) {
    Vector<int> test_1 {54,54,67,89,78,98};
    size_t size = 10;

    test_1.resize(size); 

    EXPECT_EQ(test_1.capacity(), size);
    EXPECT_EQ(test_1.size(), size);

}

TEST(push_back_test, push_back_test_and_back_test_and_emplace_back_test) {
    
    Vector<int> a;
    a.push_back(3);
    a.emplace_back(1,2,3,4,5);


    EXPECT_TRUE(a[0] == 3 && a.back() == 5 && a.size() == 6);
}

TEST(pop_back_test, pop_back_test) {
    
    Vector<int> a;
    a.emplace_back(1,2,3,4,5);

    a.pop_back();

    EXPECT_TRUE(a.size() == 4);
}

TEST(emty_test, true_return) {
    Vector<float> test_1;

    EXPECT_TRUE(test_1.empty());
}

TEST(empty_test, false_return) {
    Vector<float> test_1{1};

    EXPECT_FALSE(test_1.empty());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}