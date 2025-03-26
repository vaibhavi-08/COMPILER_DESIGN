// Typedef for basic types
typedef unsigned int uint; // Alias for unsigned int
typedef float real;        // Alias for float

// Typedef for function pointer
typedef int (*operation)(int, int);

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);

void main() {
    uint number1 = 10; // Using typedef alias for unsigned int
    uint number2 = 5;  // Using typedef alias for unsigned int
    int result1,result2;
    real pi = 3.14;    // Using typedef alias for float

    operation op;      // Using typedef alias for function pointer

    // Assign and call the add function
    op = add;
    result1 = op(number1, number2);

    // Assign and call the subtract function
    op = subtract;
    result2 = op(number1, number2);
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}
