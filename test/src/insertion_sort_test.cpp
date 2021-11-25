#include <vector>

#include <gtest/gtest.h>

#include <insertion_sort.hpp>

TEST(insertionSort, shouldSortSequence)
{
  std::vector<int>       data{1, 2, 4, 3, 5, 1, 7};
  const std::vector<int> expected{1, 1, 2, 3, 4, 5, 7};
  gtep::insertionSort(data.begin(), data.end());
  EXPECT_EQ(expected, data);
}

TEST(insertionSort, shouldDoNothingIfTheSequenceIsEmpty)
{
  std::vector<int>       data{};
  const std::vector<int> expected{};
  gtep::insertionSort(data.begin(), data.end());
  EXPECT_EQ(expected, data);
}

TEST(insertionSort, shouldDoNothingIfTheSequenceIsOfSize1)
{
  std::vector<int>       data{1};
  const std::vector<int> expected{1};
  gtep::insertionSort(data.begin(), data.end());
  EXPECT_EQ(expected, data);
}

TEST(insertionSort, shouldSortASequenceOfTwoElements)
{
  std::vector<int>       data{2, 1};
  const std::vector<int> expected{1, 2};
  gtep::insertionSort(data.begin(), data.end());
  EXPECT_EQ(expected, data);
}

TEST(insertionSort, shouldDoNothingWhenTheSequenceIsAlreadySorted)
{
  std::vector<int>       data{1, 2, 3, 4, 5};
  const std::vector<int> expected{1, 2, 3, 4, 5};
  gtep::insertionSort(data.begin(), data.end());
  EXPECT_EQ(expected, data);
}

TEST(insertionSort, shouldBeAbleToSortASubSequence)
{
  std::vector<int>       data{0, 5, 6, 1, 2, 9, 2};
  const std::vector<int> expected{0, 1, 2, 5, 6, 9, 2};
  gtep::insertionSort(data.begin() + 1, data.end() - 1);
  EXPECT_EQ(expected, data);
}
