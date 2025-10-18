#include <gtest/gtest.h>
#include "../include/Binary.hpp"

TEST(BinaryTests, DefaultConstructor) {
    Binary b;
    EXPECT_EQ(b.toDecimal(), 0);
}

TEST(BinaryTests, DecimalConstructor) {
    Binary b(123);
    EXPECT_EQ(b.toDecimal(), 123);
}

TEST(BinaryTests, CopyConstructor) {
    Binary b1(42);
    Binary b2(b1);
    EXPECT_EQ(b1.toDecimal(), b2.toDecimal());
}

TEST(BinaryTests, MoveConstructor) {
    Binary b1(42);
    Binary b2(std::move(b1));
    EXPECT_EQ(b2.toDecimal(), 42);
}

TEST(BinaryTests, CopyAssignment) {
    Binary b1(42);
    Binary b2;
    b2 = b1;
    EXPECT_EQ(b1.toDecimal(), b2.toDecimal());
}

TEST(BinaryTests, MoveAssignment) {
    Binary b1(42);
    Binary b2;
    b2 = std::move(b1);
    EXPECT_EQ(b2.toDecimal(), 42);
}

TEST(BinaryTests, Addition) {
    Binary b1(123);
    Binary b2(456);
    Binary sum = b1 + b2;
    EXPECT_EQ(sum.toDecimal(), 579);
}

TEST(BinaryTests, Subtraction) {
    Binary b1(456);
    Binary b2(123);
    Binary diff = b1 - b2;
    EXPECT_EQ(diff.toDecimal(), 333);
}

TEST(BinaryTests, ComparisonOperators) {
    Binary b1(100);
    Binary b2(200);
    Binary b3(100);

    EXPECT_TRUE(b1 < b2);
    EXPECT_TRUE(b2 > b1);
    EXPECT_TRUE(b1 == b3);
    EXPECT_FALSE(b1 == b2);
}

TEST(BinaryTests, ComplexOperations) {
    Binary b1(50);
    Binary b2(30);
    Binary b3(10);

    // Test chained operations
    Binary result = b1 + b2 - b3;
    EXPECT_EQ(result.toDecimal(), 70);

    // Test multiple additions
    Binary sum = b1 + b2 + b3;
    EXPECT_EQ(sum.toDecimal(), 90);

    // Test multiple subtractions
    Binary diff = b1 - b2 - b3;
    EXPECT_EQ(diff.toDecimal(), 10);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
