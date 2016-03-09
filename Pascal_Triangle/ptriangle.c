#include <stdio.h>

void main() {
    int nroRows;
    printf("Number of Rows to be printed\n");
    scanf("%d", &nroRows);

    int row, colSpaces, colChar;

    for (row = 0; row < nroRows - row; colSpaces >= 1; colSpaces--) {
        printf(" ");
    }

    int printChar = 1;
    int num = row;
    int den = 1;
    for (colChar = 0; colChar < row; ++colChar) {
        printf("%d", printChar);
        printChar = printChar * num;
        printChar = printChar / den;
        num--;
        den++;
    }
    printf("\n");
}