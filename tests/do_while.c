// Declare function for output
void print_int(int x) {
    // Placeholder function to simulate printing integers
}

int main() {
    int i = 1;  // Loop control variable

    // Do-while loop with variable declared inside the loop body
    do {
        int cube = i * i * i;  // Variable declared inside the loop
        print_int(cube);       // Expected output: 1, 8, 27, 64, 125 (each on a new line or sequentially)
        i = i + 1;             // Increment the loop control variable
    } while (i <= 5);

    return 0;
}

