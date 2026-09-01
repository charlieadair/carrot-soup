// This needs to be an implementation of the Split-Multiply algorithm
// Constraints: 1≤𝑛≤20000; n is also guaranteed to be a power of 2
//    x and y are both positive numbers of the same length.

#include <stdio.h>
#include <iostream>

int multiply_by_ten(int input) {
  int output;
  output = (input << 3); // Multiply input by eight
  output += (input << 1); // Add input times 2

  return output;
}

// Find how many digits in input
int num_digits(int input) {
  if (input == 0) {
    return 0;
  }

  int numDigits = 1;
  int tmp = input;

  while (tmp / 10 > 0.1) {
    
    tmp = tmp / 10;
    numDigits++;

  }
  return numDigits;
}

typedef struct {
  int head;
  int tail;
} Tuple;

// Given a number, split it into its
// front n/2 digits and back n/2 digits
Tuple split_number(int input) {

  int numDigits = num_digits(input);
  
  Tuple output;
  output.head = 0;
  output.tail = 0;

  if (numDigits == 1) {
    output.tail = input;
    return output;
  }

  // pop the last n/2 digits
  // by dividing by 10
  int tmp = input;
  for (int i = 0; i < (numDigits / 2); i++) {
    int addToTail = tmp % 10;
    tmp /= 10;

    // Multiply by 10 based on digit position
    for (int j = 0; j < i; j++) {
      addToTail = multiply_by_ten(addToTail);
    }

    output.tail += addToTail;
  }

  output.head = tmp;

  return output;
}

// x * y = ac * 10^{2m} + (ad + bc) * 10^m + bd
//       = 10^{2m}e + 10^m(g + h) + f
//            e = ac ; f = bd ; g = bc ; h = ad
int split_multiply(int x, int y, int numDigits) {
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

  int a, b, c, d;
  a = left.head;
  b = left.tail;
  c = right.head;
  d = right.tail;

  int halfDigits = numDigits >> 1;

  int e = split_multiply(a, c, halfDigits);
  int f = split_multiply(a, d, halfDigits);
  int g = split_multiply(b, c, halfDigits);
  int h = split_multiply(b, d, halfDigits);

  int m =  halfDigits;
  int twoM = ( m << 1 );

  int term1 = e;
  for (int i = 0; i < twoM; i++) {
    term1 = multiply_by_ten(term1);
  }

  int term2 = g + f;
  for (int i = 0; i < m; i++){
    term2 = multiply_by_ten(term2);
  }

  return term1 + term2 + h;

}

// x and y must have the same digit length for split_multiply's
// constraints to hold, so we pass num_digits(x) as the length.
void run_test(int x, int y) {
  int actual = split_multiply(x, y, num_digits(x));
  printf("%d\n", actual);
}

int main(void) {

  int x, y, numDigits;

  std::cin >> x;
  std::cin >> y;
  std::cin >> numDigits;

  run_test(x, y);

  return 0;
}
