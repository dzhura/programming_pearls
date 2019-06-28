#include <fstream>
#include <iostream>
#include "bitmap.h"

int main(int argc, char * argv[])
{
  size_t N;
  std::cin >> N;

  Bitmap bitmap(N);

  while (std::cin.good()) {
    size_t number;
    std::cin >> number;

    bitmap.set_bit(number-1, true);
  }

  for (size_t i=0; i<bitmap.size(); ++i) {
    if (bitmap.get_bit(i)) {
      std::cout << i+1 << std::endl;
    }
  }
}
