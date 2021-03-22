#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringLength(char* s);
char mapRot13(char c);
int indexOf(char* s, char c);
int main(int argc, char** argv)
{
    char* c2 = malloc(6 * sizeof(char));
    int* i;
    c2 = "hello";
    char c = 'q';
    printf("%c\n", c);
    printf("%c\n", mapRot13(c));
}

//finish writing our encoder for entire strings using
//old C style pointers

int indexOf(char* s, char c)
{
    for(int i = 0; i < stringLength(s); i++)
    {
        if(*(s + i) == c)
        {
            return i;
        }
    }
    return -1;
}

char mapRot13(char c)
{
    //return the char that is the rot13 encoded version of c
    char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    int currentIndex = indexOf(alphabet, c);
    int map = (currentIndex + 13) % 26;
    return *(alphabet + map);
}

int stringLength(char* s)
{
    int length = 0;
    while(*s != '\0')
    {
        length++;
        s = s + 1;
    }
    return length;
}