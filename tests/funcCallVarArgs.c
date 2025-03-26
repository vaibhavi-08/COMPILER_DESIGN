// Manual implementation of variable argument handling without typedef
void* va_list; // Pointer to represent the variable argument list

// Function to initialize the argument list
void va_start(void** ap, void* last) {
    *ap = (char*)last + sizeof(last);
}

// Function to fetch the next argument
void* va_arg(void** ap, int size) {
    void* arg = *ap;
    *ap = (char*)*ap + size;
    return arg;
}

// Function to clean up the argument list
void va_end(void** ap) {
    *ap = NULL;
}

// Function prototype for variable arguments
int sum(int count, ...);

void main() {
    int result; // Variable to store the result

    // Call the function with different numbers of arguments
    result = sum(3, 10, 20, 30); // Sum of 3 numbers
    printf("Sum of 3 numbers: %d\n", result);

    result = sum(5, 1, 2, 3, 4, 5); // Sum of 5 numbers
    printf("Sum of 5 numbers: %d\n", result);
}

// Function to calculate the sum of variable arguments
int sum(int count, ...) {
    void* args; // Variable argument list
    int total = 0; // Variable to store the sum
    int i;

    // Initialize the argument list
    va_start(&args, &count);

    // Iterate through the arguments and calculate the sum
    for (i = 0; i < count; i++) {
        total += *(int*)va_arg(&args, sizeof(int));
    }

    // Clean up the argument list
    va_end(&args);

    return total;
}
