#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2 || num == 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int count = 0;
    int currentNumber = n + 1;

    while (count < k) {
        if (isPrime(currentNumber)) {
            count++;
            if (count == k) {
                printf("%d\n", currentNumber);
                return 0;
            }
        }
        currentNumber++;
    }

    return 0;
}