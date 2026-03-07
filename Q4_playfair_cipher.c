#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[]) {
    int used[26] = {0};
    int i, k = 0;
    char ch;

    used['J' - 'A'] = 1;

    for(i = 0; key[i]; i++) {
        ch = toupper(key[i]);
        if(ch < 'A' || ch > 'Z') continue;

        if(!used[ch - 'A']) {
            matrix[k/5][k%5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for(ch = 'A'; ch <= 'Z'; ch++) {
        if(!used[ch - 'A']) {
            matrix[k/5][k%5] = ch;
            k++;
        }
    }
}

void playfairCipher(char text[], int choice) {
    int i,j,k,r1,c1,r2,c2;

    for(i=0;text[i];i+=2) {

        char a = toupper(text[i]);
        char b = toupper(text[i+1] ? text[i+1] : 'X');

        if(a == b) b = 'X';

        for(j=0;j<5;j++)
        for(k=0;k<5;k++){
            if(matrix[j][k]==a){ r1=j; c1=k; }
            if(matrix[j][k]==b){ r2=j; c2=k; }
        }

        if(choice == 1) { // Encrypt

            if(r1==r2)
                printf("%c%c", matrix[r1][(c1+1)%5], matrix[r2][(c2+1)%5]);

            else if(c1==c2)
                printf("%c%c", matrix[(r1+1)%5][c1], matrix[(r2+1)%5][c2]);

            else
                printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
        }

        else { // Decrypt

            if(r1==r2)
                printf("%c%c", matrix[r1][(c1+4)%5], matrix[r2][(c2+4)%5]);

            else if(c1==c2)
                printf("%c%c", matrix[(r1+4)%5][c1], matrix[(r2+4)%5][c2]);

            else
                printf("%c%c", matrix[r1][c2], matrix[r2][c1]);
        }
    }

    printf("\n");
}

int main() {

    char text[200], key[100];
    int choice, j;

    for(j=1;j<=3;j++) {

        printf("\nInput %d\n", j);
        if(j>1) getchar();

        printf("Enter message: ");
        fgets(text,sizeof(text),stdin);
        text[strcspn(text,"\n")] = 0;

        printf("Enter key: ");
        fgets(key,sizeof(key),stdin);
        key[strcspn(key,"\n")] = 0;

        printf("Choose 1 for Encryption, 2 for Decryption: ");
        scanf("%d",&choice);

        generateMatrix(key);

        printf("Result: ");
        playfairCipher(text,choice);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 4\n");

    return 0;
}