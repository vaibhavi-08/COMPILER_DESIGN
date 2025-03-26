// Function prototypes for dynamic memory allocation
void* malloc(int size);
void free(void* ptr);

void main() {
    int* arr; // Pointer to dynamically allocated memory
    int n;    // Size of the array
    int i;    // Loop variable

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically for 'n' integers
    arr = (int*)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Input elements into the dynamically allocated array
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the elements of the array
    printf("The entered integers are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);
}
