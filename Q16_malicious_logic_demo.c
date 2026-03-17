#include <stdio.h>
int main(){
    FILE *fp;
    int i;

    fp = fopen("malicious_demo.txt", "w");

    if(fp == NULL)
    {
        printf("File could not be created.\n");
        return 1;
    }

    printf("Writing data to file...\n");

    for(i = 1; i <= 100000; i++)   // controlled limit
    {
        fprintf(fp, "This is line number %d written by the program.\n", i);
    }

    fclose(fp);

    printf("File writing completed successfully.\n");

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 16");
    return 0;
}