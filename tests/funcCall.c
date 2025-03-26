struct Person {
    char *name; // make name a pointer
    int age;
};

// void updatePerson(struct Person *p, char *newName, int newAge) {
//     p->name = newName;  // direct assignment is now valid
//     p->age = newAge;
// }

void add () {
    int a=0;
    int b=1;
    int c = a + b;
}

int main() {
    struct Person p1 = {"Alice", 25};

    printf("Before update:\n");
    printf("Name: %s\n", p1.name);
    printf("Age: %d\n", p1.age);

    // Function call with pointer and arguments
    // updatePerson(&p1, "Bob", 30);

    // printf("\nAfter update:\n");
    // printf("Name: %s\n", p1.name);
    // printf("Age: %d\n", p1.age);

    return 0;
}