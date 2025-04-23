
int main() {
    int value = 10;
    int * x=&value;
}
void modifyValue(int* ref) {
    *ref = 20; // Modify the value at the referenced address
}
