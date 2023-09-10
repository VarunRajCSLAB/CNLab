#include <stdio.h>

int arr[17];

void xor(int x[], int y[]) {
    int k = 0;
    for (int i = 1; i < 16; i++) {
        if (x[i] == y[i])
            arr[k++] = 0;
        else
            arr[i] = 1;
    }
}

void main() {
    int dd[17], div[33], ze[17], i, k;
    printf("Enter the dataword:\n");
    for (i = 0; i < 17; i++)
        scanf("%d", &div[i]);

    for (i = i; i < 33; i++)
        div[i] = 0;

    for (i = 0; i < 17; i++)
        ze[i] = 0;

    printf("Enter dividend:\n");
    for (i = 0; i < 17; i++)
        scanf("%d", &dd[i]);

    i = 0;
    k = 0;
    for (i = i; i < 17; i++)
        arr[k++] = div[i];

    while (i < 33) {
        if (arr[0] == 0)
            xor(arr, ze);
        else
            xor(arr, dd);

        arr[16] = div[i++];
    }

    k = 0;
    for (i = 17; i < 33; i++)
        div[i] = arr[k++];

    printf("Codeword: ");
    for (i = 0; i < 33; i++)
        printf("%d", div[i]);

    for (i = 0; i < 17; i++)
        arr[i] = 0;

    printf("\nAt the receiver end:\n");
    k = 0;
    for (i = i; i < 17; i++)
        arr[k++] = div[i];

    while (i < 33) {
        if (arr[0] == 0)
            xor(arr, ze);
        else
            xor(arr, dd);

        arr[16] = div[i++];
    }

    k = 0;
    for (i = 17; i < 33; i++)
        div[i] = arr[k++];

    printf("Codeword: ");
    for (i = 0; i < 33; i++)
        printf("%d", div[i]);
}
