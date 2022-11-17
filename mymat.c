/*
 *  File:  mymat.c operations between/on matrices.
 */
#include "mymat.h"


void read_mat(mat pmat, mat val)
{
    int row,col;
    for(row = 0; row < MAT_SIZE;row++) /*Enter given values to the given matrix*/
        for (col = 0; col < MAT_SIZE; ++col)
        {
            pmat[row][col] = val[row][col];

        }
}

void print_mat(mat pmat1)
{
    int row,col;
    for (row = 0; row < MAT_SIZE; row++)/*print given matrix*/
    {
        for (col = 0; col < MAT_SIZE; col++)
        {
            printf("|%7.2f ", pmat1[row][col]);
        }
        printf("|\n");
    }
    printf("\n");
}

void add_mat(mat pmat1,mat pmat2,mat pmat3)
{
    int row,col;
    mat calculate = {0};/*temp matrix to store values in*/

    for(row = 0;row<MAT_SIZE;row++)
        for(col=0;col<MAT_SIZE;col++)
            calculate[row][col] = pmat1[row][col] + pmat2[row][col];/*Add result to temp matrix*/

    for(row = 0;row<MAT_SIZE;row++)
        for(col=0;col<MAT_SIZE;col++)
            pmat3[row][col] =  calculate[row][col];/*Enter result from temp matrix to the original matrix*/
}
void sub_mat(mat pmat1,mat pmat2,mat pmat3)
{
    int row,col;
    mat calculate;

    for(row = 0;row<MAT_SIZE;row++)
        for(col=0;col<MAT_SIZE;col++)
            calculate[row][col] = pmat1[row][col] - pmat2[row][col];/*Sub result to temp matrix*/

    for(row = 0;row<MAT_SIZE;row++)
        for(col=0;col<MAT_SIZE;col++)
            pmat3[row][col] =  calculate[row][col];/*Enter result from temp matrix to the original matrix*/
}

void mul_mat(mat pmat1,mat pmat2,mat pmat3)
{
    int row,col,mulind;
    double mult_val;
    mat calculate;

    for(row=0; row < MAT_SIZE; row++)
        for(col=0; col < MAT_SIZE;col++)
        {
            mult_val = 0;
            for(mulind=0; mulind < MAT_SIZE; mulind++)
            {
                mult_val += pmat1[row][mulind]* pmat2[mulind][col];
            }
            calculate[row][col] = mult_val;/*Mul result to temp matrix*/
        }

    for(row = 0; row<MAT_SIZE;row++)
        for(col=0;col<MAT_SIZE;col++)
            pmat3[row][col] = calculate[row][col];/*Enter result from temp matrix to the original matrix*/
}

void mul_scalar(mat pmat1,double scalar, mat pmat2)
{
    int row,col;
    mat calculate;
    double scalar_val;

    for(row=0; row < MAT_SIZE; row++)
        for(col=0; col < MAT_SIZE; col++)
        {
            scalar_val = pmat1[row][col] * scalar;/*calculate scalar result*/
            calculate[row][col] = scalar_val;/*enter the scalar to temp matrix*/
        }

    for(row=0; row < MAT_SIZE; row++)
        for(col=0; col < MAT_SIZE; col++)
           pmat2[row][col] = calculate[row][col];/*Enter result from temp matrix to the original matrix*/
}
void trans_mat(mat pmat1,mat pmat2)
{
    int row,col;
    mat calculate = {0};
    for(row=0; row < MAT_SIZE; row++)
        for(col=0; col < MAT_SIZE; col++)
            calculate[col][row] = pmat1[row][col];/*Trans give matrix to temp matrix*/

    for(row = 0;row < MAT_SIZE;row++)
        for(col = 0; col < MAT_SIZE;col++)
            pmat2[row][col] = calculate[row][col];/*Enter values to original matrix*/
}

void stop()
{
    printf("Stop program.");
    exit(0);
}



