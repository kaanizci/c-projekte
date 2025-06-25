#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // Negative numbers and numbers ending with 0 (except 0 itself) cannot be palindromes
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // Check if the number is a palindrome
    return x == reversed || x == reversed / 10;
}

int main() {
    int number;

    // Input from user
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Check if the number is a palindrome
    if (isPalindrome(number)) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }

    return 0;
}