#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Simplified S-box (for demo, still 8x4x16 can be used)
int SBOX[8][4][16] = {
    {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
    {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
    {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
    {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
    {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
    {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
    {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
    {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}
};

// XOR two 64-bit blocks
void xor64(char *a, char *b, char *res) {
	int i;
    for( i=0;i<64;i++) res[i] = ((a[i]-'0') ^ (b[i]-'0')) + '0';
}

// Simple 4-bit S-box substitution per 6-bit input
void sboxSub(char *in, char *out) {
    int i,j;
    for(i=0;i<8;i++){
        int row = (in[i*6]-'0')*2 + (in[i*6+5]-'0');
        int col = (in[i*6+1]-'0')*8 + (in[i*6+2]-'0')*4 + (in[i*6+3]-'0')*2 + (in[i*6+4]-'0');
        int val = SBOX[i][row][col];
        for(j=0;j<4;j++) out[i*4+3-j] = ((val>>j)&1)+'0';
    }
}

// Convert 8-character string to 64-bit binary
void strToBin(char *s, char *b) {
	int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++) b[i*8+7-j] = ((s[i]>>j)&1)+'0';
    }
}

// Convert 64-bit binary to 8-character string
void binToStr(char *b, char *s){
	int i, j;
    for(i=0;i<8;i++){
        s[i]=0;
        for(j=0;j<8;j++) s[i]|=(b[i*8+j]-'0')<<(7-j);
    }
    s[8]='\0';
}

// Feistel function for demonstration (XOR+S-box)
void feistel(char *R, char *K, char *out){
    char temp[48], sub[32];
    int i;
    for(i=0;i<48;i++) temp[i] = R[i%32]; // simple expansion
    xor64(temp,K,temp);
    sboxSub(temp,sub);
    for(i=0;i<32;i++) out[i]=sub[i];
}

// DES encrypt/decrypt (16 rounds)
void des64(char *data, char subkeys[16][48], int decrypt){
    char L[32],R[32],temp[32];
    int i, r;
    for(i=0;i<32;i++) {L[i]=data[i]; R[i]=data[i+32];}
    for(r=0;r<16;r++){
        int round = decrypt ? 15-r : r;
        feistel(R,subkeys[round],temp);
        for(i=0;i<32;i++){
            temp[i] ^= L[i];
            L[i]=R[i]; R[i]=temp[i];
        }
    }
    for(i=0;i<32;i++){data[i]=R[i]; data[i+32]=L[i];}
}

// Generate 16 subkeys (simplified: just repeat key pattern)
void genKeys(char *key, char subkeys[16][48]){
	int i,r ;
    for(r=0;r<16;r++) for(i=0;i<48;i++) subkeys[r][i] = key[i%64];
}

int main(){
    char plaintext[9], key[9], binPlain[65], binKey[65], cipherBin[65], decryptedBin[65], dec[9];
    char subkeys[16][48];
    int i;
    for(i=1;i<=3;i++){
        printf("\nInput %d\nEnter plaintext (8 chars): ",i);
        scanf("%s",plaintext);
        printf("Enter key (8 chars): "); scanf("%s",key);

        strToBin(plaintext,binPlain);
        strToBin(key,binKey);
        genKeys(binKey,subkeys);

        strcpy(cipherBin,binPlain);
        des64(cipherBin,subkeys,0); // encrypt

        strcpy(decryptedBin,cipherBin);
        des64(decryptedBin,subkeys,1); // decrypt

        binToStr(decryptedBin,dec);

        printf("Encrypted (binary): %.64s\n",cipherBin);
        printf("Decrypted: %s\n",dec);
    }
    printf("\nName: Smrity Thapa\nRoll no: 52\nLab no: 17");
    return 0;
}
