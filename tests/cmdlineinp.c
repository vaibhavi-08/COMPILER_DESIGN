// Declare function prototypes
int add(int a, int b);
int subtract(int a, int b);

void main(int argc, char* argv[]) {
    int x, y; // Operands
    int result; // Result of the operation
    char* operation; // Operation to perform

    // Check if the correct number of arguments is provided
    if (argc != 4) {
        printf("Usage: <program_name> <num1> <num2> <operation>\n");
        printf("Example: ./program 10 5 add\n");
        return;
    }

    // Parse command-line arguments
    x = atoi(argv[1]); // Convert the first argument to an integer
    y = atoi(argv[2]); // Convert the second argument to an integer
    operation = argv[3]; // Get the operation as a string

    // Perform the specified operation
    if (strcmp(operation, "add") == 0) {
        result = add(x, y);
        printf("Result of addition: %d\n", result);
    } else if (strcmp(operation, "subtract") == 0) {
        result = subtract(x, y);
        printf("Result of subtraction: %d\n", result);
    } else {
        printf("Invalid operation. Use 'add' or 'subtract'.\n");
    }
}

// Function definitions
int add(int a, int b) {
    return a + b; // Returns the sum of two integers
}

int subtract(int a, int b) {
    return a - b; // Returns the difference of two integers
}
