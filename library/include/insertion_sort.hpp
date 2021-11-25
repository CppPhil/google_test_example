#pragma once
#include <algorithm>

namespace gtep {
template<typename It>
void insertionSort(It first, It last)
{
  if (first == last) {
    return;
  }

  for (It i{first + 1}; i != last; ++i) {
    for (It j{i}; (j != first) && (*j < *(j - 1)); --j) {
      std::iter_swap(j, j - 1);
    }
  }
}
} // namespace gtep
