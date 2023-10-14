#include <stdio.h>

int main()
{
    FILE *ptr = NULL;
    char string[64] = "This tutorial is produced by tutorial64.c";
    // ***** Reading a file
    // ptr = fopen("myfile.txt","r");
    // fscanf(ptr,"%s",string);
    // printf("The content of a file has %s\n",string);

    //***** Writing a file***
    ptr=fopen("myfile.txt","w");
    fprintf(ptr,"%s",string);

    //***** To add a content***
    ptr=fopen("myfile.txt","a");
    fprintf(ptr,"%s",string)

    return 0;
}