int add(int a, int b) {
    return a + b;
}
int main() {
    // Declare a function pointer
    int (*func_ptr)(int, int);

    // Assign the address of the function to the pointer
    func_ptr = &add;
}