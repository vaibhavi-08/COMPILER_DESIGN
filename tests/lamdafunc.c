int main(){
    auto greet = []() {
        int z;
    };
    greet(); // Call the lambda function

    // Example 2: Lambda with Parameters
    auto add = [](int a, int b) -> int {
        return a + b;
    };
    

    // Example 3: Lambda with Capture Clause
    int num = 10;
    auto increment = [&num]() {
        num++;
    };
}