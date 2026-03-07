#include <stdio.h>
#include <string.h>

void vigenereCipher(char text[], char key[], int choice) {
    int i, keylen = strlen(key);
    for(i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        int k = key[i % keylen];
        if(k >= 'a' && k <= 'z') k = k - 'a';
        else if(k >= 'A' && k <= 'Z') k = k - 'A';

        if(ch >= 'A' && ch <= 'Z') {
            if(choice == 1)
                ch = ((ch - 'A' + k) % 26) + 'A';
            else
                ch = ((ch - 'A' - k + 26) % 26) + 'A';
        } else if(ch >= 'a' && ch <= 'z') {
            if(choice == 1)
                ch = ((ch - 'a' + k) % 26) + 'a';
            else
                ch = ((ch - 'a' - k + 26) % 26) + 'a';
        }
        printf("%c", ch);
    }
    printf("\n");
}

int main() {
    char text[200], key[100];
    int choice, j;

    for(j = 1; j <= 3; j++) {
        printf("\nInput %d\n", j);
        if(j > 1) getchar();  

        printf("Enter message: ");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = 0;

        printf("Enter key (word): ");
        fgets(key, sizeof(key), stdin);
        key[strcspn(key, "\n")] = 0;

        printf("Choose 1 for Encryption, 2 for Decryption: ");
        scanf("%d", &choice);

        printf("Result: ");
        vigenereCipher(text, key, choice);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 3\n");
    return 0;
}