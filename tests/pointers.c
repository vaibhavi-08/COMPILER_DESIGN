

int main() {
    int x = 10;
    int *ptr = &x; 
    *ptr = 20;
    *ptr=40;

    if (x == 20) {
        x++;
    } else {
       x--;
    }

   return 0;
}
