#include <stdio.h>
#include <stdlib.h>

void print_matrix(char *name, int a[], int nrows, int ncols);
void multiply(int a[], int a_nrows, int a_ncols,
              int b[], int b_nrows, int b_ncols,
              int c[], int *c_nrows, int *c_ncols);
int print_item(char *name, int a[], int nrows, int ncols, int row, int col);
//******* Function prototypes for the functions that you must complete *******
//******* Prototypes de fonctions pour les fonctions que vous devez compléter *******
int print_column_sums(char *name, int a[], int nrows, int ncols);
int print_row_sums(char *name, int a[], int nrows, int ncols);

/*
 * Main function of the program. DO NOT MODIFY THIS FUNCTION
 * Fonction principale du programme. NE PAS MODIFIER CETTE FONCTION
*/
int main(void) {

    int a_nrows = 3;
    int a_ncols = 4;
    int a[] = { 1,  2,  3,  4,
                5,  6,  7,  8,
                9, 10, 11, 12 };

    int b_nrows = 4;
    int b_ncols = 3;
    int b[] = { 1,   2,  3,
                4,   5,  6,
                7,   8,  9,
                10,  11, 12 };

    int c_nrows, c_ncols;
    int c[9];

    int d_nrows, d_ncols;
    int d[16];

    print_matrix("a", a, a_nrows, a_ncols);
    print_item("a", a, a_nrows, a_ncols, 2, 1);
    print_column_sums("a", a, a_nrows, a_ncols);
    print_row_sums("a", a, a_nrows, a_ncols);

    print_matrix("b", b, b_nrows, b_ncols);

    multiply(a, a_nrows, a_ncols,
             b, b_nrows, b_ncols,
             c, &c_nrows, &c_ncols);

    print_matrix("c", c, c_nrows, c_ncols);

    multiply(b, b_nrows, b_ncols,
             a, a_nrows, a_ncols,
             d, &d_nrows, &d_ncols);

    print_matrix("d", d, d_nrows, d_ncols);

    return EXIT_SUCCESS;
}

/*
 * DO NOT MODIFY THIS FUNCTION
 * NE PAS MODIFIER CETTE FONCTION
 */
void print_matrix(char *name, int a[], int nrows, int ncols) {
    printf("Matrix %s:\n", name);
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            printf("%4d", a[i * ncols + j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * DO NOT MODIFY THIS FUNCTION
 * NE PAS MODIFIER CETTE FONCTION
 */
void multiply(int a[], int a_nrows, int a_ncols,
              int b[], int b_nrows, int b_ncols,
              int c[], int *c_nrows, int *c_ncols) {

    if (a_nrows != b_ncols || a_ncols != b_nrows) {
        printf("Sizes of matrices are not compatible\n");
    }

    *c_nrows = a_nrows;
    *c_ncols = b_ncols;

    for (int i = 0; i < *c_nrows; i++) {
        for (int j = 0; j < *c_ncols; j++) {
            int sum = 0;
            for (int k = 0; k < a_ncols; k++) {
                // sum = sum + a_ik * b_kj
                sum = sum + a[i * a_ncols + k] * b[k * b_ncols + j];
            }
            c[i * *c_ncols + j] = sum;
        }
    }
}

/* YOU MUST COMPLETE THE CODE FOR THIS FUNCTION - VOUS DEVEZ REMPLIR LE CODE POUR CETTE FONCTION */
int print_column_sums(char *name, int a[], int nrows, int ncols) {
    printf("Column sums for matrix %s:\n", name);
    int i, j, sum;
    for (j = 0; j < ncols; j++) {
        sum = 0;
        for (i = 0; i < nrows; i++) {
            sum += a[i * ncols + j];
        }
        printf("%d \n", sum);
    }
    return 0;
}

/* YOU MUST COMPLETE THE CODE FOR THIS FUNCTION - VOUS DEVEZ REMPLIR LE CODE POUR CETTE FONCTION */
int print_row_sums(char *name, int a[], int nrows, int ncols) {
    printf("Row sums for matrix %s:\n", name);
    int i, j, sum;
    for (i = 0; i < nrows; i++) {
        sum = 0;
        for (j = 0; j < ncols; j++) {
            sum += a[i * ncols + j];
        }
        printf("%d \n", sum);
    }
    return 0;
}

/*
 * DO NOT MODIFY THIS FUNCTION
 * NE PAS MODIFIER CETTE FONCTION
 */
int print_item(char *name, int a[], int nrows, int ncols, int row, int col) {
    int item = a[row * ncols + col];
    printf("a[%d][%d] = %d\n\n", row, col, item);
}