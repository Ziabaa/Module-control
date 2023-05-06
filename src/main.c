#include "calculator.h"



int main(void){
    char * input_expression = "(50*2*5 / 10)/2";
    int my_int_array[20];
    char * my_char_array = malloc(30 * sizeof (char));
    int size_value = array_digit(input_expression, my_int_array);
    int size_dare = arr_dare(input_expression, my_char_array);

    int i = 0;
    while (i < size_value){
        printf("%d\n", my_int_array[i]);
        i++;
    }
    i = 0;
    while (i < size_dare){
        printf("%c\n", my_char_array[i]);
        i++;
    }
    double res = calculate(my_int_array, my_char_array, size_dare);
    printf("RESULT---->%f\n", res);
    free(my_char_array);
    return 0;
}
