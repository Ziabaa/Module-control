#ifndef MODULE_CONTROL_CALCULATOR_H
#define MODULE_CONTROL_CALCULATOR_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int array_digit(char * string, int * array);
int arr_dare(char * string, char * array);
double dare_brackets(int pos1, int pos2, int * arr_int, char * arr_char);
double calculate(int * arr_int, char * arr_char, int x);

#endif //MODULE_CONTROL_CALCULATOR_H
