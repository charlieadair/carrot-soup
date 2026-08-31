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
  int numDigits = 0;
  int tmp = input;
  while (tmp / 10 > 1) {
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

  //DEBUG
  printf("numDigits: %d\n", numDigits);

  Tuple output;
  output.head = 0;
  output.tail = 0;

  if (numDigits == 1) {
    output.tail = input;
    return output;
  }

  int tmp = input;
  // pop the last n/2 digits
  // by dividing by 10
  //
  printf("numDigits / 2: %d\n", numDigits / 2);
  for (int i = 0; i < (numDigits / 2); i++) {
    
    int addToTail = tmp % 10;
    tmp /= 10;

    // Multiply by 10 based on digit position
    for (int j = 0; j < i; i++) {
      addToTail = multiply_by_ten(addToTail);
    }

    output.tail += addToTail;
  }

  output.head = tmp;

  return output;
}

int split_multiply(int x, int y) {
  // Base case: numbers are single digit
  int newX, newY = 0;
  if (x / 10.0 > 1) {
    // Don't do anything to x
    newX = x;
  }
  else {
    int i = 0;
  }
  if (y / 10.0 > 1) {
    newY = y;
  }
  return 0;
}


int main(void) {
  int input = 1234;
  printf("Input: [%d]\n", input);
  Tuple output = split_number(input);
  printf("Output: [%d, %d]\n", output.head, output.tail);
  return 0;
}
