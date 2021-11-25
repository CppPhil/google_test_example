#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

TEST(assertions, demonstration)
{
  ASSERT_EQ(0, 0);
  EXPECT_EQ(0, 0);

  ASSERT_EQ(0, 0) << "0 and 0 must be equal";

  EXPECT_TRUE(true);
  EXPECT_FALSE(false);

  EXPECT_NE(5, 3);
  EXPECT_LT(3, 5);
  EXPECT_LE(5, 5);
  EXPECT_GT(5, 4);
  EXPECT_GE(5, 5);

  EXPECT_STREQ("test", "test");
  EXPECT_STRNE("test", "text");
  EXPECT_STRCASEEQ("TEST", "test");
  EXPECT_STRCASENE("TEST", "text");

  EXPECT_FLOAT_EQ(1.0F, 1.0F);
  EXPECT_DOUBLE_EQ(2.0, 2.0);

  EXPECT_NO_THROW([] {}());
  EXPECT_THROW([] { throw std::runtime_error{"BAD"}; }(), std::runtime_error);
}

class TestFixture : public testing::Test {
protected:
  TestFixture() : data{1, 2, 3, 4}
  {
  }

  ~TestFixture()
  {
    std::cout << "~TestFixture" << std::endl;
  }

  std::vector<int> data;
};

TEST_F(TestFixture, shouldWork)
{
  EXPECT_EQ((std::vector<int>{1, 2, 3, 4}), data);
}

class TestFixture2 : public testing::Test {
protected:
  void SetUp() override
  {
    data = new int[5];

    for (int i{0}; i < 5; ++i) {
      data[i] = i * i;
    }
  }

  void TearDown() override
  {
    delete[] data;
  }

  int* data;
};

TEST_F(TestFixture2, shouldWork)
{
  const int  a[5]{0, 1, 4, 9, 16};
  const bool areEqual{std::equal(std::begin(a), std::end(a), data)};
  EXPECT_TRUE(areEqual);
}

TEST(predicateAssertions, example)
{
  auto areEqual{[](int a, int b) { return a == b; }};
  // EXPECT_TRUE(areEqual(1, 2));
  EXPECT_PRED2(areEqual, 1, 1);
}

static bool isOdd(int value)
{
  return (value & 1) == 1;
}

static testing::AssertionResult isOddAssertion(int value)
{
  if (isOdd(value)) {
    return testing::AssertionSuccess() << "is odd";
  }

  return testing::AssertionFailure() << "is even";
}

TEST(customAssert, shouldWork)
{
  EXPECT_TRUE(isOddAssertion(1));
  EXPECT_FALSE(isOddAssertion(2));
}

namespace {
class MyCustomType {
public:
  friend bool operator==(const MyCustomType& lhs, const MyCustomType& rhs)
  {
    return (lhs.m_i == rhs.m_i) && (lhs.m_s == rhs.m_s);
  }

  friend bool operator!=(const MyCustomType& lhs, const MyCustomType& rhs)
  {
    return !(lhs == rhs);
  }

  friend std::ostream& operator<<(std::ostream& os, const MyCustomType& obj)
  {
    return os << "MyCustomType{\"m_i\": " << obj.m_i << ", \"m_s\": \""
              << obj.m_s << "\"}";
  }

  friend void PrintTo(const MyCustomType& obj, std::ostream* os)
  {
    *os << '{' << obj.m_i << ", " << obj.m_s << '}';
  }

  MyCustomType(int i, std::string s) : m_i{i}, m_s{std::move(s)}
  {
  }

private:
  int         m_i;
  std::string m_s;
};
} // anonymous namespace

TEST(withCustomType, shouldWork)
{
  const MyCustomType a{1, "test"};
  const MyCustomType b{1, "test"};
  EXPECT_EQ(a, b);
}

class ParameterizedTest
  : public testing::Test
  , public testing::WithParamInterface<int> {
protected:
};

TEST_P(ParameterizedTest, shouldWork)
{
  EXPECT_LT(GetParam(), 5);
}

INSTANTIATE_TEST_SUITE_P(
  Prefix,
  ParameterizedTest,
  testing::Values(1, 2, 3, 4));
