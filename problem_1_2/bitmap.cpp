#include <array>
#include <cmath>
#include <cassert>
#include "bitmap.h" 

static const std::array<unsigned char, 8> masks = {
  0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80
};

Bitmap::Bitmap(size_t in_size):
 m_size(in_size),
 bytes(ceil((double)in_size / 8), 0x0)
{ }

bool Bitmap::get_bit(size_t pos) const
{
  const unsigned char & byte = bytes[pos / 8];
  return (byte & (masks[pos % 8])) == masks[pos % 8];
}

void Bitmap::set_bit(size_t pos, bool bit)
{ 
  unsigned char & byte = bytes[pos / 8];

  if (bit) {
    byte = byte | masks[pos % 8];
  }
  else {
    byte = byte & (~masks[pos % 8]);
  }
}

size_t Bitmap::size() const
{
  return m_size;
}

