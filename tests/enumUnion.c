enum Operation { ADD, SUBTRACT };

union Data {
    int intValue;
    float floatValue;
};

void main() {
    enum Operation op = ADD;
    union Data data1, data2;

    data1.intValue = 10;
    data2.intValue = 5;

    if (op == ADD) {
        int result = data1.intValue + data2.intValue;
    }
}
