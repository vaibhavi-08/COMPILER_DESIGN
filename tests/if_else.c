// Declare functions for output
void print_int(int x) {
    // Placeholder function to simulate printing integers
}

void print_bool(int x) {
    // Placeholder function to simulate printing boolean values (1 for true, 0 for false)
}

int main() {
    int a = 10;
    int b = 20;
    // Multiple conditions in if-else
    int x = 15;
    int y = 5;
    int flag = 1; // true
    // Simple if-else structure
    if (a < b) {
        print_int(a);  // Expected: 10 (since a < b is true)
    } else {
        print_int(b);
    }

    // Nested if-else structure
    if (a > b) {
        if (a % 2 == 0) {
            print_int(a);  // This block won't execute since a > b is false
        } else {
            print_int(b);
        }
    } else {
        if (b % 2 == 0) {
            print_int(b);  // Expected: 20 (since b % 2 == 0 is true)
        } else {
            print_int(a);
        }
    }

    // if (x > y && x % y == 0) {
    //     print_int(x);  // Expected: 15 (since x > y and x % y == 0 are both true)
    // } else if (x < y || y % x == 0) {
    //     print_int(y);
    // } else {
    //     print_int(-1); // Default case, won't execute here
    // }

    // If-else with boolean values
    
    if (flag) {
        print_bool(flag);  // Expected: 1 (true)
    } else {
        print_bool(0);     // Won't execute since flag is true
    }

    return 0;
}
