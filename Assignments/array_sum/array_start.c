#include <stdio.h>

#define NROWS 2
#define NCOLS 4

void print_array(int a[NROWS][NCOLS]);
//******* Function prototypes for the functions that you must complete *******
//******* Prototypes de fonctions pour les fonctions que vous devez compléter *******
void sum_arrays(int a[NROWS][NCOLS], int b[NROWS][NCOLS], int sum[NROWS][NCOLS]);

/*
 * Main function of the program. DO NOT MODIFY THIS FUNCTION
 * Fonction principale du programme. NE PAS MODIFIER CETTE FONCTION
*/
int main() {

    int array_a[NROWS][NCOLS] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            };
    int array_b[NROWS][NCOLS] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            };

    int array_sum[NROWS][NCOLS];

    sum_arrays(array_a, array_b, array_sum);
    print_array(array_sum);

    return 0;
}

/* YOU MUST COMPLETE THE CODE FOR THIS FUNCTION - VOUS DEVEZ REMPLIR LE CODE POUR CETTE FONCTION */
void sum_arrays(int a[NROWS][NCOLS], int b[NROWS][NCOLS], int sum[NROWS][NCOLS])
{
    int i, j;
    for (i = 0; i < NROWS; i++)
    {
        for (j = 0; j < NCOLS; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

/*
 * DO NOT MODIFY THIS FUNCTION
 * NE PAS MODIFIER CETTE FONCTION
 */
void print_array(int a[NROWS][NCOLS])
{
    for (int i = 0; i < NROWS; i++)
    {
        for (int j = 0; j < NCOLS; j++)
        {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}