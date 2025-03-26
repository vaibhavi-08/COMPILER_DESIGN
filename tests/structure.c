struct Person {
    char name[20];
    int age;
};

int main() {
    // Create a struct variable
    struct Person p1 = {"Alice", 25};

    // Create a pointer to the struct
    struct Person *ptr = &p1;

    // Print original values
    printf("Original Name: %s\n", ptr->name);
    printf("Original Age: %d\n", ptr->age);

    // Modify struct members using the pointer
    ptr->age = 30;

    // Print modified values
    printf("Modified Age: %d\n", ptr->age);
    printf("Modified Age via p1: %d\n", p1.age);

    // Test case validation
    if (p1.age == 30 && ptr->age == 30) {
        printf("Test Passed: Struct pointer is working correctly.\n");
    } else {
        printf("Test Failed: Struct pointer is not working correctly.\n");
    }

    return 0;
}