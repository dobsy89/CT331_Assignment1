#include <stdio.h>

int a;
int* b;
long c;
double* d;
char** e;

int main(int arg, char* argc[]){
    printf("Hello assignment1.\n");
    
    printf("%lu \n", sizeof(a));
    printf("%lu \n", sizeof(b));
    printf("%lu \n", sizeof(c));
    printf("%lu \n", sizeof(d));
    printf("%lu \n", sizeof(e));
    
    return 0;
}