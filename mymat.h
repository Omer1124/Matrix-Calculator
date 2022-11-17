#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



#define MAT_SIZE 4 /*Row and col size of the matrices*/
#define RUN_PROGRAM for(;;)/*Endless loop for main function*/


typedef double mat[MAT_SIZE][MAT_SIZE];/*Matrix 4x4 typedef*/


void read_mat(mat ,mat );/*Enter values to given matrix*/
void print_mat(mat);/*print given matrix*/
void add_mat(mat,mat,mat);/*Add operation between two given matrices*/
void sub_mat(mat,mat,mat);/*Sub operation between two given matrices*/
void mul_mat(mat,mat,mat);/*Mul operation between two given matrices*/
void mul_scalar(mat,double ,mat );/*Scalar mul with given matrix*/
void trans_mat(mat,mat);/*Trans matrix*/
void stop();/*Stop program*/

