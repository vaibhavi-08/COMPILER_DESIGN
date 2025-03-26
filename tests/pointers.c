

int main() {
    int x = 10;
    int *ptr = &x; // pointer storing address of x

  
    // Change the value of x using the pointer
    *ptr = 20;

     printf("Modified value of x: %d\n", x);
     printf("Modified value using pointer: %d\n", *ptr);

    if (x == 20 && *ptr == 20) {
        printf("Test Passed: Pointer is working correctly.\n");
    } else {
        printf("Test Failed: Pointer is not working correctly.\n");
    }

   return 0;
}
