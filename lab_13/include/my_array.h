#ifndef LAB_13_MY_ARRAY_H
#define LAB_13_MY_ARRAY_H

#include <cstdio>
#include <cstddef>
#include <cassert>
#include <cstdint>

namespace lab_13 {
  template<typename T, std::size_t N>
  class my_array {
   public:

    const T& at(std::size_t index) const {
      assert((index >= 0 && index < N) && "Index Out Of Range");
      return arr[index];
    };

    T& at(std::size_t index) {
      assert((index >= 0 && index < N) && "Index Out Of Range");
      return arr[index];
    };

    const T& operator[](std::size_t index) const {
      return arr[index];
    };

    T& operator[](std::size_t index) {
      return arr[index];
    };

    bool empty() const {
      return N == 0;
    };

    size_t size() const {
      return N;
    };

    void fill(const T& val) {
      for(std::size_t i = 0; i < N; i++){
        arr[i] = val;
      }
    };

  private:
    T arr[N];
  };

  template<std::size_t N>
  class my_array<bool, N> {
    struct BitReference {
      BitReference(uint8_t* byte_ptr, std::size_t bit_n) : byte(*byte_ptr), bit_n(bit_n) {};

      BitReference operator=(bool b) {
        if(b) {
          byte |= 1 << bit_n;
        } else {
          byte &= (~(1 << bit_n));
        }
        return *this;
      }

      operator bool() {
        return byte & (1 << bit_n);
      }

      uint8_t byte;
      size_t bit_n;
    };

  public:
    bool at(std::size_t index) const {
      assert((index >= 0 && index < N) && "Index Out Of Range");
      uint8_t byte = arr[index / 8];
      return byte & (1 << (index % 8));
    };

    BitReference at(std::size_t index) {
      assert((index >= 0 && index < N) && "Index Out Of Range");
      return BitReference(&arr[index / 8], index % 8);
    };

    bool operator[](std::size_t index) const {
      uint8_t byte = arr[index / 8];
      return byte & (1 << (index % 8));
    };

    BitReference operator[](std::size_t index) {
      return BitReference(&arr[index / 8], index % 8);
    };

    bool empty() const {
      return N == 0;
    };

    size_t size() const {
      return N;
    };

    void fill(bool val) {
      uint8_t zero = 0;
      uint8_t x = val? ~zero : zero;
      for(std::size_t i = 0; i < (N + 7) / 8; i++){
        arr[i] = x;
      }
    };

  private:
    uint8_t arr[(N + 7) / 8];
  };
}

#endif
