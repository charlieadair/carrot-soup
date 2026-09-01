// This needs to be an implementation of the Split-Multiply algorithm
// Constraints: 1≤𝑛≤20000; n is also guaranteed to be a power of 2
//    x and y are both positive numbers of the same length.

#include <stdio.h>
#include <iostream>
#include <cstdint>

uint64_t multiply_by_ten(uint64_t input) {
  uint64_t output;
  output = (input << 3); // Multiply input by eight
  output += (input << 1); // Add input times 2

  return output;
}

// Find how many digits in input
uint64_t num_digits(uint64_t input) {
  if (input == 0) {
    return 0;
  }

  uint64_t numDigits = 1;
  uint64_t tmp = input;

  while (tmp >= 10) {
    
    tmp = tmp / 10;
    numDigits++;

  }
  return numDigits;
}

typedef struct {
  uint64_t head;
  uint64_t tail;
} Tuple;

// Given a number, split it into its
// front n/2 digits and back n/2 digits
Tuple split_number(uint64_t input) {

  uint64_t numDigits = num_digits(input);
  
  Tuple output;
  output.head = 0;
  output.tail = 0;

  if (numDigits == 1) {
    output.tail = input;
    return output;
  }

  // pop the last n/2 digits
  // by dividing by 10
  uint64_t tmp = input;
  for (uint64_t i = 0; i < (numDigits / 2); i++) {
    uint64_t addToTail = tmp % 10;
    tmp /= 10;

    // Multiply by 10 based on digit position
    for (uint64_t j = 0; j < i; j++) {
      addToTail = multiply_by_ten(addToTail);
    }

    output.tail += addToTail;
  }

  output.head = tmp;

  return output;
}

// x * y = ac * 10^{2m} + (ad + bc) * 10^m + bd
//
//       = 10^{2m}e + 10^m(g + h) + f
//        where: e = ac ; f = bd ; g = bc ; h = ad
//
//       = term1 + term2 + f
uint64_t split_multiply(uint64_t x, uint64_t y, uint64_t numDigits) {
  // Base case — multiply 2 single digit numbers
  // Note: We are guaranteed that numDigits is a power of 2
  //       so we should never be in a situation where 0 + 2 = 2
  //       causes logic to break. In otherwords, x = y.
  if (numDigits <= 1) {
    return x * y;
  }

  Tuple left, right;
  left = split_number(x);
  right = split_number(y);

  uint64_t a, b, c, d;
  a = left.head;
  b = left.tail;
  c = right.head;
  d = right.tail;

  uint64_t halfDigits = numDigits >> 1;

  uint64_t e = split_multiply(a, c, halfDigits);
  uint64_t f = split_multiply(a, d, halfDigits);
  uint64_t g = split_multiply(b, c, halfDigits);
  uint64_t h = split_multiply(b, d, halfDigits);

  uint64_t m =  halfDigits;
  uint64_t twoM = ( m << 1 );

  uint64_t term1 = e;
  for (uint64_t i = 0; i < twoM; i++) {
    term1 = multiply_by_ten(term1);
  }

  uint64_t term2 = g + f;
  for (uint64_t i = 0; i < m; i++){
    term2 = multiply_by_ten(term2);
  }

  return term1 + term2 + h;

}

// x and y must have the same digit length for split_multiply's
// constraints to hold, so we pass num_digits(x) as the length.
void run_test(uint64_t x, uint64_t y) {
  uint64_t actual = split_multiply(x, y, num_digits(x));
  printf("%llu\n", actual);
}

int main(void) {

  uint64_t x, y;

  std::cin >> x;
  std::cin >> y;


  run_test(x, y);

  return 0;
}
