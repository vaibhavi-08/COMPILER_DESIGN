struct Person {
    char* name;
    int age;
};

int main() {
    // Create a struct variable
    struct Person p1;

    // Create a pointer to the struct
    struct Person *ptr = &p1;

    p1.name="hello";
    p1.age=10;
    // Modify struct members using the pointer
    ptr->age = 30;


    // Test case validation
    if (p1.age == 30 && ptr->age == 30) {
//printf("Test Passed: Struct pointer is working correctly.\n");
    } else {
       // printf("Test Failed: Struct pointer is not working correctly.\n");
    }

    return 0;
}