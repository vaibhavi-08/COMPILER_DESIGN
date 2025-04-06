
void main() {
    int arr[2][3] = { {1, 2, 3}, {4, 5, 6} }; // 2x3 multidimensional array
    int i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            arr[i][j] += 1; // Increment each element
        }
    }
}
