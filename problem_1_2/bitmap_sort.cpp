#include <fstream>
#include <iostream>
#include "bitmap.h"

int main(int argc, char * argv[])
{
  if (argc != 2) {
    std::cerr << "Wrong argc!" << std::endl;
    return 1;
  }

  char * in_filename = argv[1];

  std::ifstream in_file(in_filename);

  size_t N;
  in_file >> N;

  Bitmap bitmap(N);

  while (!in_file.eof()) {
    size_t number;
    in_file >> number;

    bitmap.set_bit(number-1, true);
  }

  for (size_t i=0; i<bitmap.size(); ++i) {
    if (bitmap.get_bit(i)) {
      std::cout << i+1 << std::endl;
    }
  }
}
