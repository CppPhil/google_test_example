#include <gtest/gtest.h>

#include <fibonacci.hpp>

TEST(fibonacci, shouldCalculateCorrectValueForTheFirstNumber)
{
  EXPECT_EQ(0, gtep::fibonacci(0));
}

TEST(fibonacci, shouldCalculateCorrectValueForTheSecondNumber)
{
  EXPECT_EQ(1, gtep::fibonacci(1));
}

TEST(fibonacci, shouldCalculateCorrectValueForTheThirdNumber)
{
  EXPECT_EQ(1, gtep::fibonacci(2));
}

TEST(fibonacci, shouldCalculateCorrectValueForTheFourthNumber)
{
  EXPECT_EQ(2, gtep::fibonacci(3));
}

TEST(fibonacci, shouldCalculateCorrectValueForNumber12)
{
  EXPECT_EQ(144, gtep::fibonacci(12));
}
