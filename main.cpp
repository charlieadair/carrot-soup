// New startegy — Use vectors to represent the number instead of integers
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>

// Turns a string (expected to represent a number) into a vector of integers
std::vector<int> vectorize(std::string input, int numDigits) {
  std::vector<int> result;
    
  int pad = numDigits - input.length();
  for (int i = 0; i < pad; ++i) {
    result.push_back(0);
  }
   
  for (char c : input) {
    result.push_back(c - '0');
  }
    
  return result;
}
// Takes two vector<int> and adds their values toegether resulting in a new vector
std::vector<int> add_vectors(std::vector<int> a, std::vector<int> b) {
  std::vector<int> result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    
    // Iterate from the least significant digit (right) to most significant (left)
  while (i >= 0 || j >= 0 || carry > 0) {
    int sum = carry;
    if (i >= 0) sum += a[i--];
    if (j >= 0) sum += b[j--];
        
    result.push_back(sum % 10);
    carry = sum / 10;
  }
     
  std::reverse(result.begin(), result.end());
  return result;
}

// Converts a vector of ints to a string
std::string vector_to_string(std::vector<int> in) {
  std::string result;

  for (int digit : in) {
      result += static_cast<char>(digit + '0');
  }
    
  return result;
}

// Multiplies a number (expressed as a vector) by a power of 10
std::vector<int> mult_power_of_ten(std::vector<int> in, int power) {
  if (power == 0) {
    return in;
  }
  
  std::vector<int> result;
  int pad = in.size() + power;

  for (int i = 0; i < pad; ++i) {
    result.push_back(0);
  }

  for (int i = 0; i < in.size(); i++) {
    result[i] = in[i];
  }

  return result;
}

// x * y = ac * 10^{2m} + (ad + bc) * 10^m + bd
//
//       = 10^{2m}e + 10^m(g + h) + f
//        where: e = ac ; f = bd ; g = bc ; h = ad
//
//       = term1 + term2 + f
std::vector<int> split_multiply(std::vector<int>  x, std::vector<int> y, int numDigits) {
  // Base case — multiply 2 single digit numbers
  // Note: We are guaranteed that numDigits is a power of 2
  //       so we should never be in a situation where 0 + 2 = 2
  //       causes logic to break. In otherwords, x = y.
  
if (numDigits <= 1) {
    std::vector<int> output;
    int out_int = x[0] * y[0];

    if (out_int >= 10) {
      output.push_back(out_int / 10); 
    }

    output.push_back(out_int % 10);     

    return output;
}

int m = numDigits >> 1; // Effectively numDigits / 2

std::vector<int> a(x.begin(), x.begin() + m);
std::vector<int> c(y.begin(), y.begin() + m);
std::vector<int> b(x.begin() + m, x.end());
std::vector<int> d(y.begin() + m, y.end());
  
std::vector<int> e = split_multiply(a, c, m);
std::vector<int> f = split_multiply(a, d, m);
std::vector<int> g = split_multiply(b, c, m);
std::vector<int> h = split_multiply(b, d, m);

std::vector<int> term1 = mult_power_of_ten(e, numDigits);
  
std::vector<int> term2 = mult_power_of_ten(add_vectors(g, f), m);

std::vector<int> result = add_vectors(add_vectors(term1, term2), h);
return result;

}

int main(void) {
  int numDigits;
  std::string in_x, in_y;
  
  // Get input
  std::cin >> numDigits;
  std::cin.ignore();
  std::getline(std::cin, in_x);
  std::getline(std::cin, in_y);

  std::vector<int> X = vectorize(in_x, numDigits);
  std::vector<int> Y = vectorize(in_y, numDigits);
 
  std::string result = vector_to_string(split_multiply(X, Y, numDigits));

  printf("%s\n", result.c_str());

  // Debug
  // printf("Digits: %d, X: %s, Y: %s\n", numDigits, x.c_str(), y.c_str());

  return 0;
}

