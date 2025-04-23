int main() {
    int value = 10;      // A simple integer variable
    int* ptr1 = &value;  // Pointer to the integer
    int** ptr2 = &ptr1;  // Pointer to the pointer

    **ptr2 = 20;         // Modify the value using the multi-level pointer
}
