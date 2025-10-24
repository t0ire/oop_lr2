#include <gtest/gtest.h>

#include "eleven.h"

TEST(ElevenTest, Constructor1) {
    Eleven num;
    EXPECT_EQ(num.print(), "0");
    EXPECT_EQ(num.getSize(), 0);
}

TEST(ElevenTest, Constructor2) {
    Eleven num(5, 3);
    EXPECT_EQ(num.print(), "33333");
    EXPECT_EQ(num.getSize(), 5);
}

TEST(ElevenTest, Constructor3) {
    Eleven num(3, 10);
    EXPECT_EQ(num.print(), "AAA");
    EXPECT_EQ(num.getSize(), 3);
}

TEST(ElevenTest, Constructor4) {
    Eleven num = {10, 6, 1};
    EXPECT_EQ(num.print(), "A61");
    EXPECT_EQ(num.getSize(), 3);
}

TEST(ElevenTest, Constructor5) {
    Eleven num("1a3");
    EXPECT_EQ(num.print(), "1A3");
    EXPECT_EQ(num.getSize(), 3);
}

TEST(ElevenTest, Constructor6) {
    Eleven num("001a3");
    EXPECT_EQ(num.print(), "1A3"); //обрезает 
}

TEST(ElevenTest, Constructor7) {
    Eleven num = {0, 0, 0};
    EXPECT_EQ(num.print(), "0");//обрезает 
}

TEST(ElevenTest, Error) {
    EXPECT_THROW(Eleven({1, 15, 2}), std::invalid_argument);
    EXPECT_THROW(Eleven("12G"), std::invalid_argument);
}

TEST(ElevenTest, Copy) {
    Eleven original("1A23");
    Eleven copy(original);
    
    EXPECT_EQ(original.print(), copy.print());
    EXPECT_EQ(original.getSize(), copy.getSize());
    EXPECT_TRUE(original.eq(copy));
}

TEST(ElevenTest, Addition1) {
    Eleven a("1A3");  // 234
    Eleven b("25");   // 27
    Eleven res = a.add(b);
    EXPECT_EQ(res.print(), "218");  // 261
}

TEST(ElevenTest, Addition2) {
    Eleven a("999");  // 1197
    Eleven b("1");   // 1
    Eleven res = a.add(b);
    EXPECT_EQ(res.print(), "99A");  // 1198
}

TEST(ElevenTest, Addition3) {
    Eleven num1("A");
    Eleven num2("A");
    Eleven res = num1.add(num2);
    EXPECT_EQ(res.print(), "19");
}

TEST(ElevenTest, Subtraction1) {
    Eleven num1("1A3");
    Eleven num2("1A3");
    Eleven res = num1.sub(num2);
    EXPECT_EQ(res.print(), "0");
}

TEST(ElevenTest, Subtraction2) {
    Eleven num1("12");
    Eleven num2("35"); 
    EXPECT_THROW(num1.sub(num2), std::invalid_argument);
}

TEST(ElevenTest, Subtraction3) {
    Eleven num1("AA");
    Eleven num2("1");
    Eleven res = num1.sub(num2);
    EXPECT_EQ(res.print(), "A9");
}

TEST(ElevenTest, Сomparison1) {
    Eleven num1("1A3");
    Eleven num2("1A3"); 
    EXPECT_TRUE(num1.eq(num2));
    EXPECT_FALSE(num1.lt(num2));
    EXPECT_FALSE(num1.gt(num2));
}

TEST(ElevenTest, Сomparison2) {
    Eleven num1("12");
    Eleven num2("23");
    EXPECT_TRUE(num1.lt(num2));
    EXPECT_FALSE(num1.gt(num2));
    EXPECT_FALSE(num1.eq(num2));
}