#include <stdio.h>
#include <string.h>

void railFenceEncrypt(char text[], int key) {

    int len = strlen(text);
    char rail[50][200];
    int i,j;

    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            rail[i][j]='\n';

    int row=0,dir=1;

    for(i=0;i<len;i++) {

        rail[row][i]=text[i];

        row += dir;

        if(row==0 || row==key-1)
            dir = -dir;
    }

    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            if(rail[i][j]!='\n')
                printf("%c",rail[i][j]);

    printf("\n");
}

void railFenceDecrypt(char cipher[], int key) {

    int len=strlen(cipher);
    char rail[50][200];
    int i,j;

    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            rail[i][j]='\n';

    int row=0,dir=1;

    for(i=0;i<len;i++) {

        rail[row][i]='*';

        row+=dir;

        if(row==0 || row==key-1)
            dir=-dir;
    }

    int index=0;

    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            if(rail[i][j]=='*' && index<len)
                rail[i][j]=cipher[index++];

    row=0;
    dir=1;

    for(i=0;i<len;i++) {

        printf("%c",rail[row][i]);

        row+=dir;

        if(row==0 || row==key-1)
            dir=-dir;
    }

    printf("\n");
}

int main() {

    char text[200];
    int key,choice,j;

    for(j=1;j<=3;j++) {

        printf("\nInput %d\n",j);
        if(j>1) getchar();

        printf("Enter message: ");
        fgets(text,sizeof(text),stdin);
        text[strcspn(text,"\n")]=0;

        printf("Enter key (number of rails): ");
        scanf("%d",&key);

        printf("Choose 1 for Encryption, 2 for Decryption: ");
        scanf("%d",&choice);

        printf("Result: ");

        if(choice==1)
            railFenceEncrypt(text,key);
        else
            railFenceDecrypt(text,key);
    }

    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 5\n");

    return 0;
}