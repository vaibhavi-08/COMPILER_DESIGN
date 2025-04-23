union Data {
    int i;
    float f;
    char ch;
};

enum Color{RED,BLUE,GREEN};

int main() {
    union Data d;

    d.i = 10;      // Assign to int

    d.f = 3.14;    // Assign to float (overwrites int)

    d.ch = 'A';    // Assign to char (overwrites float)

    return 0;
}

