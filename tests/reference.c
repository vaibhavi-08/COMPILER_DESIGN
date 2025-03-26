void modifyValue(int* ref);

void main() {
    int value = 10;
    int * x=&value;
    func(value);
    // Pass the address of the variable to simulate reference behavior
    modifyValue(&value);
}

void modifyValue(int* ref) {
    *ref = 20; // Modify the value at the referenced address
}
