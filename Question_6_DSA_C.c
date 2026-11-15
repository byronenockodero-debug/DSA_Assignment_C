#include <stdio.h>
#define MAX 100

int main() {
    int a[10][10], sp[MAX][3];
    int r, c, i, j, k = 1;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    // Triplet representation: row 0 holds rows, cols, non-zero count
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (a[i][j] != 0) {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = a[i][j];
                k++;
            }

    sp[0][0] = r;
    sp[0][1] = c;
    sp[0][2] = k - 1;

    printf("\nSparse matrix (Row Col Value):\n");
    for (i = 0; i < k; i++)
        printf("%d\t%d\t%d\n", sp[i][0], sp[i][1], sp[i][2]);

    return 0;
}