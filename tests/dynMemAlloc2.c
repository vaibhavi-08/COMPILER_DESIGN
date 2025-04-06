int main(){
    int n;
    //cout << "Enter number of elements: ";
    //cin >> n;

    // Allocate memory for an array of n integers
    int* arr = new int[n];

    // Assign values
    for (int i = 0; i < n; i++) {
        arr[i] = i * 5;
    }
}