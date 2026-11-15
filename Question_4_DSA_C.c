// 4.	Write a recursive program:
// a.	To find the sum of first N natural numbers [5]
// b.	To find the factorial of a number [5]
// c.	To find the Nth term of a Fibonacci series [5]
// d.	To generate N terms of a Fibonacci series [5]

#include <stdio.h>

// a. Sum of first N natural numbers
int sum_n(int n) {
    if (n <= 0)             // base case
        return 0;
    return n + sum_n(n - 1);
}

// b. Factorial of a number
long long factorial(int n) {
    if (n <= 1)             // base case: 0! = 1! = 1
        return 1;
    return n * factorial(n - 1);
}

// c. Nth term of Fibonacci series (F(1)=0, F(2)=1)
int fib(int n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

// d. Generate N terms of Fibonacci series
// Prints terms 1..n by recursing down, then printing on the way back up
void fib_series(int n) {
    if (n <= 0)
        return;
    fib_series(n - 1);
    printf("%d ", fib(n));
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    printf("Sum of first %d natural numbers: %d\n", n, sum_n(n));
    printf("Factorial of %d: %lld\n", n, factorial(n));
    printf("Nth Fibonacci term: %d\n", fib(n));
    printf("First %d Fibonacci terms: ", n);
    fib_series(n);
    printf("\n");

    return 0;
}
