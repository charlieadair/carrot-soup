# To run...

```
make run
./run
```
```
```
```
```

# Assignment Description

Please see Tips for programming problems for more instructions on solving programming problems.

You have stumbled upon lots of rabbits, and they are all VERY hungry for carrot soup! You must write a program to determine how much carrot soup to make.

Your program will be told how many rabbits there are and how many bowls of carrot soup each rabbit wants to eat (every rabbit wants this number of bowls). Your program should output a single number, the total number of bowls of soup you need to make to satisfy all rabbits.

For example, if your program is told there are 2 rabbits and each wants 3 bowls of soup, your program should output the number 6, because 2 times 3 is 6.

There is a catch: there are several restrictions on your program.

    Your program cannot use any built-in multiplication operators except for multiplying two single-digit numbers. You also may not use any operators or libraries that are equivalent to doing a multiple-digit multiplication (e.g. exponentiation, or other math library calls), except where specified below.
    Your program also must be recursive. The purpose of this assignment is for you to write your own SplitMultiply algorithm from scratch.
    You may use multi-digit addition and subtraction, and digit shifting (e.g. multiplying by powers of 10) (hint: many languages have a big number library which allows this). As I said in class these operations can be done "easily" (in O(n)) -- the main goal of this assignment is to practice the multiplication & recursion parts of the algorithm.

Input

The entire input to your program contains 3 integers, each on separate lines: n, x and y

    1≤𝑛≤20000 gives the number of digits in x and y. n is also guaranteed to be a power of 2
    x and y are both positive numbers of the same length.

Output

Output a single number, the result of multiplying x*y. Note, you can get full credit (100%) for this assignment without passing all test cases. See "optional challenge" below. To get full credit for this assignment, your algorithm should be a correct, reasonably efficient implementation of a O(n2) recursive multiplication algorithm. The timeout is 3 seconds. If your algorithm is timing out, you should first make sure it is correct, then make sure it is O(n2), then try to find any obvious inefficiencies, then ask the course staff for help.
Sample Input 0 	Sample Output 0

1
2
3

	

6

Sample Input 1 	Sample Output 1

1
5
7

	

35

Sample Input 2 	Sample Output 1

4
1000
2000

	

2000000

(these are the first three test cases run on gradescope -- gradescope is open now)
Optional Challenge

The final two test cases are optional, worth an extra 5% of the total points. To get credit for these cases, submit a correct, efficient implementation of a faster than O(n2) algorithm (see Ch 1.9 in your book for hints about this -- note, the implementation is a little finicky). The timeout is ~30 seconds.

For a second challenge, try re-implementing your algorithm without any using any built-in addition / subtraction / exponentiation libraries (implement them yourself using arrays).

The point of this challenge is to give motivated students extra practice with multiplication & implementation. This algorithm is something we expect you to understand eventually, but it's optional on this assignment because we will discuss it after this assignment is due.
