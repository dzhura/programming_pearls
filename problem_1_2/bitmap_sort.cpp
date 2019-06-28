#include <fstream>
#include <iostream>
#include <vector>
#include "bitmap.h"

int main(int argc, char * argv[])
{
  size_t N;
  std::cin >> N;

  std::vector<bool> bitmap(N);

  while (std::cin.good()) {
    size_t number;
    std::cin >> number;

    bitmap[number-1] = true;
  }

  for (size_t i=0; i<bitmap.size(); ++i) {
    if (bitmap[i]) {
      std::cout << i+1 << std::endl;
    }
  }
}
