/*
 *  File:  check_input.c  analyze and validate user input.
 */
#include "input.h"

static char *matrices[NUM_OF_MATRICES] = {"MAT_A","MAT_B","MAT_C","MAT_D","MAT_E","MAT_F"};/*Array with matrices names for compare*/
static char token[] ="  \t\n";/*Token for strtok function*/
static char token_with_comma[] =" ,\t";/*Token for strtok function with comma delimiter*/

int get_command(char *input){/*The function validate the given command and return integer value represent command index to main*/
    int i;
    /*Array with commands for compare*/
    char *commands[NUM_OF_COMMANDS] = {"read_mat","print_mat","add_mat","sub_mat","mul_mat","mul_scalar","trans_mat","stop"};
    char *command;

    command = strtok(input,token);/*Get command */

    if(*input == '\n') {/*If user didn't enter input*/
        printf("\nERROR:Missing input\n");
        return NUM_OF_COMMANDS;/*Return integer value to main, the value will send main switch to default case*/
    }

    if(command[strlen(command)- 1] == ','){/*Check for illegal comma*/
        printf("\nERROR:Illegal Comma.\n");
        return NUM_OF_COMMANDS;/*Return integer value to main, the value will send main switch to default case*/
    }

    for(i = 0;i<NUM_OF_COMMANDS;i++){
        if(strcmp(command,commands[i])==0) {/*Compare the given command with the commands array, return the command index if found*/
            if (i == NUM_OF_COMMANDS - 1) {
                if(strtok(NULL,token) != NULL) {
                    printf("\nERROR:Extraneous text after end of command.\n");
                    return NUM_OF_COMMANDS;/*Return integer value to main, the value will send main switch to default case*/
                }
            }
            return i;/*Return the command index to main switch*/
        }
    }

    if(i == NUM_OF_COMMANDS){/*If not found*/
        printf("\nERROR:Undefined command name\n");
        return NUM_OF_COMMANDS;/*Return integer value to main, the value will send main switch to default case*/
    }
	return NUM_OF_COMMANDS;/*if reach here return error index*/


}/*End of get_command*/

int check_mat_name(int flag) {/*The function use flags to validate the matrix name*/
    int i;
    char *matrix;

    matrix = strtok(NULL, "\n");

    if (matrix == NULL) {/*If there's no matrix name in the input*/
        printf("\nERROR:Missing argument\n");
        return NUM_OF_MATRICES;/*Return integer value to main, if this value returned main will ask for new input*/
    }

    if (flag == FIRST_MAT || flag == SECOND_MAT) {/*If the matrix we search is the first or second matrix*/
        if (flag == FIRST_MAT)/*If we need first matrix name*/
            if (matrix[0] == ',') {/*Check for illegal comma after command*/
                printf("\nERROR:Illegal Comma.\n");
                return NUM_OF_MATRICES;/*Return integer value to main, if this value returned main will ask for new input*/
            }
        if (flag == SECOND_MAT) {/*If we need second matrix name */
            if ((matrix[0] == ' ' && matrix[1] == ',') || (matrix[0] == ',' && matrix[1] == ',')) {/*Check for illegal comma*/
                printf("\nERROR:Multiple consecutive commas.\n");
                return NUM_OF_MATRICES;/*Return integer value to main, if this value returned main will ask for new input*/
            }
        }

        matrix = strtok(matrix, token_with_comma);/*cut the Matrix name*/
        if (matrix[0] == 'M' && (matrix[4] <= 'F' && matrix[4] >= 'A')){/*If comma is missing after matrix name*/
			if(NAME_LEN < strlen(matrix)){
        	    printf("\nERROR:Missing comma\n");
        	    return NUM_OF_MATRICES;/*Return integer value to main, if this value returned main will ask for new input*/
			}
        }
    }

    if (flag == RESULT_MAT) {/*If we need the result matrix*/
        if (*matrix == ' ') /*Ignore space char*/
            matrix = matrix + 1;

        if(matrix[strlen(matrix)-1] != ' ')/*Ignore space char*/
            matrix = strtok(matrix,token);

        if (matrix[0] == 'M' && !(matrix[strlen(matrix) - 1] >= 'A' && matrix[strlen(matrix) -1] <= 'F')) {/*Check extraneous text after last matrix name*/
            printf("\nERROR:Extraneous text after end of command.\n");
            return NUM_OF_MATRICES; /*Return integer value to main, if this value returned main will ask for new input*/
        }

    }

    for (i = 0; i < NUM_OF_MATRICES; i++) /*scan until find mat name, if found return index, else check errors*/
        if (strcmp(matrix, matrices[i]) == 0) {/*if Matrix name matches*/
            return i;/*Return index to main struct with the matrix name*/
        }


    if (i == NUM_OF_MATRICES) {/*If didn't find matrix*/
        printf("\nERROR:Undefined matrix name\n");
        return NUM_OF_MATRICES;/*Return integer value to main, if this value returned main will ask for new input*/
    }

	return NUM_OF_MATRICES; /*If reach here return error index*/
}/*End of check_mat_name*/

int check_values(mat values, char *ptr){/*Function to validate the values given by user*/
    int i = 0,row,col;
    char *val;
    char *check = ptr;/*pointer to user input*/

    while(*check != ',' && *ptr != ',')/*Keep forward in the string until we meet comma*/
    {
        check++;
        ptr++;
	i++;
        if(check[1] == '\n' || (check[i] == ',' && check[i+1] == '\n')){/*Check values existent*/
            printf("\nERROR:Missing argument.\n");
            return ERROR;/*Return 0 to main,if 0 is returned main will ask for new input*/
        }
    }
    i =0;
    while (*check != '\n') {/*Keep forward until end of the string*/
        if (*check == '.') {/*If encounter dot*/
            if (check[1] == '.') {/*Check if input include too many dots*/
                printf("\nERROR:Multiple consecutive dots.\n");
                return ERROR;/*Return 0 to main,if 0 is returned main will ask for new input*/
            }
        }
        if (*check == ',') {/*If encounter comma*/
            if (check[1] == ',') {/*Check if input include to manny commas*/
                printf("\nERROR:Multiple consecutive commas.\n");
                return ERROR;/*Return 0 to main,if 0 is returned main will ask for new input*/
            }
        }

        if ((*check >= '0' && *check <= '9') || *check == ' ' || *check == ',' || *check == '.' || *check == '\n' || *check == '-');/*comma and number afterwards, bypassing spaces*/
        else /*no number argument after the comma*/
        {
            printf("\nERROR:Argument is not a real number.\n");
            return ERROR;/*Return 0 to main,if 0 is returned main will ask for new input*/
        }
        i++;
        check++;
    }
    if(!(ptr[strlen(ptr) - 2] >= '0' && ptr[strlen(ptr)-2] <= '9')){/*Check if there's extraneous text after last value*/
        printf("\nExtraneous text after end of command\n");
        return ERROR;/*Return 0 to main,if 0 is returned main will ask for new input*/
    }

    val = strtok(ptr, token_with_comma);/*Get first value from input*/
    for (row = 0; row < MAT_SIZE; row++)
        for (col = 0; col < MAT_SIZE && val; ++col) {
            values[row][col] = strtod(val, &ptr); /*transport text value to double value*/
            val = strtok(NULL, token_with_comma);/*Get next value*/
        }
    return OK;/*if reached here values were entered to temp matrix, return 1 to main*/
}/*End of check_values*/


double get_scalar(char *ptr){/*Get scalar value from user input,ptr is pointer to copy of the given input*/
    double scalar;
    char *scalar_str;
    char *sPtr;

    while(!(*ptr >= '0' && *ptr <= '9')) {/*Keep going forward on input chars until encounter digit*/
        ptr++;

        if (ptr == NULL) {/*If reach to end of input and did not find digits*/
            printf("\nArgument is not a scalar\n");
            return ERROR;/*Return 0 to main,if 0 is returned main will ask for new input*/
        }
    }
    scalar_str = strtok(ptr,token_with_comma);/*if reach here digit is found, cut the digits value*/
    ptr = scalar_str;/*point to the digits*/
    while(*ptr != '.'){/*Keep going from first digit until dot is found*/
        if(*ptr == '\0') {/*If dot is not found*/
            break;
        }
        if(!((*(ptr) + 1) >= '0' && (*(ptr)+1) <= '9')){/*check if the next char is digit*/
            if(*ptr == '.');/*If dot found, ignore and move to next digit*/
            else {
                printf("\nArgument is not a scalar\n");
                return ERROR;/*Return 0 to main,if 0 is returned main will ask for new input*/
            }
        }
        ptr++;
    }

    scalar = strtod(scalar_str,&sPtr);/*trans string input to double*/
    return scalar;
}/*End of get_scalar*/
