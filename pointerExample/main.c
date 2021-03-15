#include <stdio.h>

void changeInt(int a);
void changeIntByRef(int* a);

int main(int argc, char** argv)
{
    int a = 5;
    int* a_address = &a;
    int* b = a_address;
    void* b_address = &b;

    printf("%d\n%p\n%p\n%p\n", a, a_address, b, b_address);
    printf("a_address = %p\n*a_address = %d\na = %d\n", a_address, *a_address, a);

    printf("in main, a = %d\n", a);
    changeIntByRef(&a);
    printf("in main, a = %d\n", a);
}

void changeIntByRef(int* a)
{
    printf("in changeInt, a = %d\n", *a);
    *a = 13;
    printf("in changeInt, a = %d\n", *a);
}

void changeInt(int a)
{
    printf("in changeInt, a = %d\n", a);
    a = 13;
    printf("in changeInt, a = %d\n", a);
}