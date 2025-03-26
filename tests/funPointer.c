// Declare function prototypes
int add(int a, int b);
int subtract(int a, int b);
void applyOperation(int (*operation)(int, int), int x, int y);

void main() {
    int x = 10; // First operand
    int y = 5;  // Second operand

    // Call applyOperation with the add function pointer
    printf("Applying addition:\n");
    applyOperation(add, x, y);

    // Call applyOperation with the subtract function pointer
    printf("Applying subtraction:\n");
    applyOperation(subtract, x, y);
}

// Function definitions
int add(int a, int b) {
    return a + b; // Returns the sum of two integers
}

int subtract(int a, int b) {
    return a - b; // Returns the difference of two integers
}

// Function to apply an operation using a function pointer
void applyOperation(int (*operation)(int, int), int x, int y) {
    int result = operation(x, y); // Call the function via the pointer
    printf("Result: %d\n", result);
}
