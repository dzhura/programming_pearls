#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

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

  std::vector<size_t> src(N);

  size_t i = 0;
  while (!in_file.eof()) {
    size_t number;
    in_file >> number;

    src[i++] = number;
  }

  std::sort(src.begin(), src.end());

  for (size_t n : src) {
    std::cout << n << std::endl;
  }
}
