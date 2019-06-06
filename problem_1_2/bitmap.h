#include <vector>

class Bitmap
{
  size_t m_size;
  std::vector<unsigned char> bytes;

public:

  // TODO: what must be the type of size?
  Bitmap(size_t size);

  bool get_bit(size_t pos) const; 

  void set_bit(size_t pos, bool bit);

  size_t size() const;

};
