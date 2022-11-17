#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "mymat.h"


#define USER_INPUT 256 /*size of user input*/
#define NAME_LEN 5 /*size of matrices name*/
#define NUM_OF_MATRICES 6 /*Number of matrices in the calculator*/
#define NUM_OF_COMMANDS 8/*Number of commands in the calculator*/
#define FIRST_MAT 1/*Value given to flag for check_mat_name function */
#define SECOND_MAT 2/*Value given to flag for check_mat_name function */
#define RESULT_MAT 3/*Value given to flag for check_mat_name function */
#define OK 1
#define ERROR 0

int get_command(char *);/*Function that check the validation of the command*/
int check_mat_name(int);/*Function that check the validation of the matrices names*/
int check_values(mat,char *);/*Function that check validation of the values*/
double get_scalar(char *);/*Function to get the scalar value */
