/*
 *  File:  mainmat.c  main function of the calculator.
 *  The main deal with I/O.
 *  Call functions to analyze the input.
 *  Call functions to do operations between matrices.
 */

#include "mymat.h"
#include "input.h"

int main()
{
    enum{read,print,add,sub,mul,scalar,trans,stop_p};/*Integer indexes for commands*/
    char user_input[USER_INPUT];/*Variable for user input*/
    char temp[USER_INPUT];/*Variable for strcpy of the input*/
    char *ptr;/*Pointer to temp*/
    int cmd_to_exe;/*Variable to save the returned command index from function*/
    int mat_to_use;/*Variable to save the returned matrix index from function*/

    mat MAT_A = {0}, MAT_B = {0}, MAT_C = {0}, MAT_D = {0}, MAT_E = {0}, MAT_F = {0};
    struct
    {/*Struct with pointers to the matrices above, each matrix indexed from 0 to 5 */
     mat *matrix;
    }mats[] = {
            {&MAT_A},
            {&MAT_B},
            {&MAT_C},
            {&MAT_D},
            {&MAT_E},
            {&MAT_F},
    };

    printf("matrix calculator options:\n");
    printf("To add values to matrix use command read_mat\n");
    printf("To print the matrix use command print_mat \n");
    printf("For matrices addition use command add_mat \n");
    printf("For matrices subtraction use command sub_mat \n");
    printf("For matrices multiplication use command mul_mat \n");
    printf("For scalar multiplication use command mul_scalar\n");
    printf("For matrix transportation use command trans_mat \n");
    printf("To exit write \"stop\" \n");
    printf("Please enter matrix calc command\n");
    RUN_PROGRAM
    {
        printf("$:");
        fgets(user_input, sizeof(user_input),stdin);/*Get user input*/
        printf("%s", user_input);
        user_input[USER_INPUT -1 ] = '\0';
        strcpy(temp,user_input);
        ptr = temp;
        cmd_to_exe = get_command(user_input);/*Get command index*/

        /*Switch to activate the given command*/
        switch (cmd_to_exe)
        {
            case read:
            {
                int flag, mat_name_flag = FIRST_MAT;
                mat values = {0};
                mat_to_use = check_mat_name(mat_name_flag); /*Get matrix index*/
                if(mat_to_use < NUM_OF_MATRICES) {
                    flag = check_values(values,ptr);/*Get values from user input*/
                    if(flag) {
                        read_mat(mats[mat_to_use].matrix, values);/*Execute read_mat command*/
                    }
                }
                break;
            }
            case print:
            {
                int flag = RESULT_MAT;
                mat_to_use = check_mat_name(flag);/*Get matrix index*/
                if(mat_to_use < NUM_OF_MATRICES)
                    print_mat(mats[mat_to_use].matrix);/*Execute print_mat command*/
                break;
            }
            case add:
            case sub:
            case mul:
            {
                int mat1,mat2,mat3,mat_name_flag;
                mat_name_flag = FIRST_MAT;
                mat1 = check_mat_name(mat_name_flag);/*Get first matrix index*/
                if(mat1 < NUM_OF_MATRICES) {
                    mat_name_flag = SECOND_MAT;
                    mat2 = check_mat_name(mat_name_flag);/*Get second matrix index*/
                    if(mat2 < NUM_OF_MATRICES){
                        mat_name_flag = RESULT_MAT;
                        mat3 = check_mat_name(mat_name_flag);/*Get result matrix index*/
                        if(mat3 < NUM_OF_MATRICES)
                        {/*execute the given command add/sub/mul*/
                            if(cmd_to_exe == add)
                                add_mat(mats[mat1].matrix,mats[mat2].matrix,mats[mat3].matrix);
                            else if(cmd_to_exe == sub)
                                sub_mat(mats[mat1].matrix,mats[mat2].matrix,mats[mat3].matrix);
                            else
                                mul_mat(mats[mat1].matrix,mats[mat2].matrix,mats[mat3].matrix);
                        }

                    }
                }
                break;
            }
            case scalar:
            {
                int mat1,mat2,mat_name_flag;
                double scalar_val;
                mat_name_flag = FIRST_MAT;
                mat1 = check_mat_name(mat_name_flag);/*Get matrix index*/
                if(mat1 < NUM_OF_MATRICES){
                    scalar_val = get_scalar(ptr);/*Get scalar value*/
                    if(scalar_val) {
                        mat_name_flag = RESULT_MAT;
                        mat2 = check_mat_name(mat_name_flag);/*Get result matrix index*/
                        if(mat2 < NUM_OF_MATRICES)
                            mul_scalar(mats[mat1].matrix,scalar_val,mats[mat2].matrix);/*Execute mul_scalar command*/
                    }
                }

                break;
            }
            case trans:
            {
                int mat1,mat2,mat_name_flag;
                mat_name_flag = FIRST_MAT;
                mat1 = check_mat_name(mat_name_flag);/*Get matrix name index*/
                if(mat1 < NUM_OF_MATRICES){
                    mat_name_flag = RESULT_MAT;
                    mat2 = check_mat_name(mat_name_flag);/*Get result matrix name index*/
                    if(mat2 < NUM_OF_MATRICES)
                        trans_mat(mats[mat1].matrix,mats[mat2].matrix);/*Execute trans_mat command*/
                }
                break;
            }
            case stop_p:
            {
                stop();/*Stop the program only if user ask for.*/
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
