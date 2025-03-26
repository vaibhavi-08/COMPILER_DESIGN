
int main() {
    // printf("Testing break:\n");
    int i;
    int x = 0;
    for (i = 0; i < 10; i++) {
        if (i == 5)
            break; // should exit the loop when i == 5
         printf("%d ", i);
    }

//     printf("\n\nTesting continue:\n");
    for ( i = 0; i < 5; i++) {
        if (i == 2)
            continue; // should skip printing 2
        printf("%d ", i);
    }

   printf("\n\nTesting goto:\n");
    
start:
    printf("%d ", x);
    x++;
    if (x < 3)
        goto start; // should print 0 1 2 using goto loop

    return 0;
}