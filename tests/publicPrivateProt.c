class MyClass {
private:
    int privateVar; // Private member variable

    void privateFunction() {
        privateVar = 10; // Modify private variable
    }

protected:
    int protectedVar; // Protected member variable

    void protectedFunction() {
        protectedVar = 20; // Modify protected variable
    }

public:
    int publicVar; // Public member variable

    void publicFunction() {
        privateFunction();   // Access private function
        protectedFunction(); // Access protected function
        publicVar = 30;      // Modify public variable
    }

    int getPrivateVar() {
        return privateVar; // Provide access to private variable
    }

    int getProtectedVar() {
        return protectedVar; // Provide access to protected variable
    }
};

class DerivedClass : public MyClass {
public:
    void modifyProtectedVar() {
        protectedVar = 50; // Access protected member from the base class
    }
};

int main() {
    // MyClass obj;
    // obj.publicFunction(); // Access public function

    // DerivedClass derivedObj;
    // derivedObj.modifyProtectedVar(); // Access protected member through derived class

    return 0;
}
