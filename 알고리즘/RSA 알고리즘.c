#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int Encrypt(int, int, int);
int Decrypt(int, int, int);
int find_d(int, int);

void main() {
    int M;
    printf("Enter the message (UNDER 55)"); // MSG FROM ALICE TO SEND BOB
    scanf("%d", &M);
    // p,q -> prime number p=5,q=11
    /*
    N = p*q, euler = p-1 * q -1, e = 3 or 7 or ...(coprime with euler), d*e mod euler = 1
    */
    int N = 33, euler = 20, e = 3; // e*d mod euler = 1
    int d = find_d(euler, e);
    printf("%d", d);
    printf("SENDING message from alice:%d\n", M);
    int C = Encrypt(M, e, N);
    printf("Encrypted message: %d\n", C);
    printf("Message that bob can read: %d\n", C);
    int D = Decrypt(C, d, N);
    printf("Message decrypted is %d", D);
}

// encrypt C=M^e MOD N
int Encrypt(int M, int e, int N) {
    int remainder = 1;
    for (int i = 0; i < e; i++) { // M^e is too large and we only need remainder.
        remainder = (remainder * M) % N;
    }
    return remainder;
}

// decrypt M=C^d MOD N
int Decrypt(int C, int d, int N) {
    int remainder = 1;
    for (int i = 0; i < d; i++) {
        remainder = (remainder * C) % N;
    }
    return remainder;
}

int find_d(int euler, int e) {
    int d = -1;
    int temp = euler;
    while (1) {
        if (((euler + 1) % e) == 0) { // Find number d that satisfy d*e mod euler = 1
            d = ((euler + 1) / e);
            break;
        }
        else {
            euler = euler + temp;
        }
    }
    return d;
}
