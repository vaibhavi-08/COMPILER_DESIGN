struct _FILE {
    int dummy; // Dummy structure to represent FILE
};

struct _FILE* fopen(const char* filename, const char* mode);
int fprintf(struct _FILE* stream, const char* format, ...);
int fscanf(struct _FILE* stream, const char* format, ...);
int fclose(struct _FILE* stream);

void main() {
    struct _FILE* file; // File pointer
    char data[50];      // Buffer to store data

    // Open a file in write mode
    file = fopen("test.txt", "w");
    if (file) {
        fprintf(file, "Hello, File!"); // Write data to the file
        fclose(file);                  // Close the file
    }

    // Open the file in read mode
    file = fopen("test.txt", "r");
    if (file) {
        fscanf(file, "%s", data); // Read data from the file
        fclose(file);             // Close the file
    }
}
