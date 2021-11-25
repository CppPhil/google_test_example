#include <iostream>
#include <vector>

#include <fibonacci.hpp>
#include <insertion_sort.hpp>

int main()
{
  std::cout << "fibonacci(5): " << gtep::fibonacci(5) << '\n';

  std::vector<int> vector{5, 4, 2, 3};
  gtep::insertionSort(vector.begin(), vector.end());

  for (int i : vector) {
    std::cout << i << ' ';
  }

  std::cout << '\n';
}
