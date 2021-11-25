#include "fibonacci.hpp"

namespace gtep {
std::uint64_t fibonacci(std::uint64_t n) noexcept
{
  if (n <= 1) {
    return n;
  }

  std::uint64_t grandParent{0};
  std::uint64_t parent{1};
  std::uint64_t result{};

  for (std::uint64_t i{2}; i <= n; ++i) {
    result = grandParent + parent;
    grandParent = parent;
    parent      = result;
  }

  return result;
}
} // namespace gtep
