// This needs to be an implementation of the Split-Multiply algorithm
// Constraints: 1≤𝑛≤20000; n is also guaranteed to be a power of 2
//    x and y are both positive numbers of the same length.

#include <stdio.h>

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


  numDigits_x = num_digits(x) 
  
  Tuple left, right;
  if (num_digits(x) > 1) {
    left = split_number(x);
  }
  else {
    left.tail = x;
  }
  if (num_digits(y) > 1) {
    right = split_multiply(y);
    split_multiple(right.head, right.tail, numDigits);
  }
  else {
    right.tail = y;
  }

  if (numDigits_x == 1 && numDigits_y == 1) {
    return left.tail * right.tail
  }

  e = split_multiply(left.head, right.head, numDigits);
  f = split_multiply(left.tail, right.tail, numDigits);
  g = split_multiple(left.tail, right.head, numDigits);
  h = split_multiply(left.head, right.tail, numDigits);
  m = num_digits(x);

  tenToThe2m = 1;

  // i can't guarentee that the numDigits will be less than 10, so I don't think
  // i'm actually able to split_multiply this number.
  for (int i = 0; i < split_multiply(2, numDigits, 1 + num_digits(numDigits))) {
    tenToThe2m = multiply_by_ten(tenToThe2m);
  }
}

// x and y must have the same digit length for split_multiply's
// constraints to hold, so we pass num_digits(x) as the length.
void run_test(int x, int y) {
  int expected = x * y;
  int actual = split_multiply(x, y, num_digits(x));

  printf("Input: %d * %d\n", x, y);
  printf("Expected output: %d\n", expected);
  printf("Actual output: %d\n", actual);
  printf("\n");
}

int main(void) {

  // n = 1 (single digit, base case)
  run_test(3, 7);
  run_test(9, 9);

  // n = 2
  run_test(12, 34);
  run_test(10, 20); // tail of each operand is 0

  // n = 4
  run_test(1234, 5678);
  run_test(1000, 2000); // head AND tail land on 0 for both operands
  run_test(1000, 9999); // one operand's tail is 0, mixed digit sizes internally

  return 0;
}
