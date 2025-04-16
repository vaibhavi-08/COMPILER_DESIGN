// Declare function for output


int main() {
    // For loop with variable declared inside the initialization
    int i;
    for ( i = 1; i <= 5; i = i + 1) {
        int square = i * i;  // Variable declared inside the loop
        //print_int(square);   // Expected output: 1, 4, 9, 16, 25 (each on a new line or sequentially)
    }

    return 0;
}
