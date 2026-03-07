#include <stdio.h>
#include <string.h>

// Function to encrypt/decrypt text
void shiftCipher(char text[], int key, int choice) {
    int i;
    for(i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if(ch >= 'A' && ch <= 'Z') {
            if(choice == 1)
                ch = ((ch - 'A' + key) % 26) + 'A';
            else
                ch = ((ch - 'A' - key + 26) % 26) + 'A';
        } 
        else if(ch >= 'a' && ch <= 'z') {
            if(choice == 1)
                ch = ((ch - 'a' + key) % 26) + 'a';
            else
                ch = ((ch - 'a' - key + 26) % 26) + 'a';
        }
        printf("%c", ch);
    }
    printf("\n");
}

int main() {
    char text[200];
    int key, choice, j;

    for(j = 1; j <= 3; j++) {
        printf("\nInput %d\n", j);

        if(j > 1) getchar();  

        printf("Enter message: ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = 0; 

        printf("Enter shift key: ");
        scanf("%d", &key);

        printf("Choose 1 for Encryption, 2 for Decryption: ");
        scanf("%d", &choice);

        printf("Result: ");
        shiftCipher(text, key, choice);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 1\n");

    return 0;
}