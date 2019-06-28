#include <vector>
#include <iostream>

#include <random>
#include <chrono>
#include <cmath>

void algorithm_p(std::vector<size_t> & src);

std::vector<size_t> algorithm_p2(size_t n, size_t N);

std::vector<size_t> algorithm_p(size_t N);

void swap(size_t & l, size_t & r);

void print(const std::vector<size_t> & src);

int main(int argc, char * argv[])
{

  if (argc != 3) {
    std::cout << "Useage: " << argv[0] << " <num numbers to generate> <max range>" << std::endl;
    return 1;
  }

  const size_t N = atoi(argv[1]);

  const size_t max_n = atoi(argv[2]);

  if (max_n < N) {
    std::cout << "error: max range must be not less than number of numbers to generate";
    return 2;
  }

  std::vector<size_t> res = algorithm_p2(N, max_n);

  print(res);

  return 0;
}

void algorithm_p(std::vector<size_t> & src)
{
  std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_real_distribution<double> distribution(0.0, 1.0);

  for (size_t j = src.size(); j > 1; --j) {
    double U = distribution(generator);

    size_t k = floor(U * j) + 1;

    swap(src[j-1], src[k-1]);
  }
}

std::vector<size_t> algorithm_p2(size_t n, size_t N)
{
  std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_real_distribution<double> distribution(0.0, 1.0);

  std::vector<size_t> dst(N);
  for (size_t i=0; i<N; ++i) {
    dst[i] = i+1;
  }

  for (size_t j = N; j > N - n; --j) {
    double U = distribution(generator);

    size_t k = floor(U * j) + 1;

    swap(dst[j-1], dst[k-1]);
  }

  if (n > dst.size())
    return std::vector<size_t>();
  else
    return std::vector<size_t>(dst.begin() + N - n, dst.end());
}

std::vector<size_t> algorithm_p(size_t N)
{
  std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_real_distribution<double> distribution(0.0, 1.0);

  std::vector<size_t> dst(N);

  for (size_t j = 0; j < N; ++j) {
    double U = distribution(generator);

    size_t k = floor(U * (j+1));

    dst[j] = dst[k];
    dst[k] = j+1;
  }

  return dst;
}

void swap(size_t & l, size_t & r)
{
  size_t t = l;
  l = r;
  r = t;
}

void print(const std::vector<size_t> & src)
{
  for(size_t el : src) {
    std::cout << el << std::endl;
  }
}
