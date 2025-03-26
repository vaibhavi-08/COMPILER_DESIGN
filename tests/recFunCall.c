int factorial(int n); // Function prototype

void main() {
    int number; // Variable to store input
    int result; // Variable to store the factorial result

    // Input from user
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Call the recursive function and store the result
    result = factorial(number);

    // Output the result
    printf("Factorial of %d is %d\n", number, result);
}

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0) {
        return 1; // Base case: factorial of 0 is 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}
