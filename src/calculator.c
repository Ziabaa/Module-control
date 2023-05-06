
#include "calculator.h"

int array_digit(char * string, int * array){
    int size = 0;
    for (int i = 0; i < (int)strlen(string); ++i) {
        if (isdigit(string[i])) {
            if (isdigit(string[i + 1])) {
                array[size] = ((int)string[i] - 48) * 10 + (string[i + 1] - 48);
                i++;
            }else if((int)string[i] - 48 == 0){
                array[size] = 0;
            }else array[size] = (int)string[i] - 48;
            i++;
            size++;
        }
    }
    return size;
}

int arr_dare(char * string, char * array) {
    int size = 0;
    for (int i = 0; i < (int)strlen(string); ++i) {
        if (string[i] == '(' || string[i] == ')' || string[i] == '+' || string[i] == '-' ||
            string[i] == '*' || string[i] == '/' || string[i] == '%' || string[i] == '^'){
            array[size] = string[i];
            size++;
        }
    }
    return size;
}

double dare_brackets(int pos1, int pos2, int * arr_int, char * arr_char){
    printf("Pos1= %d, Pos2 = %d\n", pos1, pos2);
    double res = 0;
    int flag = 0;
    for (int i = 0; i < pos2-pos1; ++i) {
        if (arr_char[i] == '^') {
            res += pow((double)arr_int[pos1 + i - 1], (double)arr_int[pos1 + i]);
            flag = 1;
        }
    }
    for (int i = 0; i < pos2-pos1; ++i) {
        if (arr_char[i] == '*' && flag ==1){
            res *= arr_int[pos1 + i];
        } else if (arr_char[i] == '*' && flag == 0) {
            res = arr_int[pos1 + i - 1] * arr_int[pos1 + i];
            flag = 1;
        }
    }

    for (int i = 0; i < pos2-pos1; ++i) {
        if (arr_char[i] == '/' && flag == 1) {
            res /= arr_int[pos1 + i];
        }else  if (arr_char[i] == '/' && flag ==0) {
            res = arr_int[pos1 + i - 1] / arr_int[pos1 + i];
            flag = 1;
        }

    }
    for (int i = 0; i < pos2-pos1; ++i) {
        if (arr_char[i] == '%' && flag == 1) {
            res = (int)res % arr_int[pos1 + i];
        }else  if (arr_char[i] == '%' && flag ==0) {
            res = arr_int[pos1 + i - 1] % arr_int[pos1 + i];
            flag = 1;
        }

    }
    for (int i = 0; i < pos2-pos1; ++i) {
        if (arr_char[i] == '+'){
            res += arr_int[pos1 + i];
        }
    }
    for (int i = 0; i < pos2-pos1; ++i) {
        if (arr_char[i] == '-'){
            res -= arr_int[pos1 + i];
        }
    }

    return res;
}

double calculate(int * arr_int, char * arr_char, int x) {
    double res;
    int flag = 0;
    int pos1 = 0, pos2 = 0;
    for (int i = 0; i < x; ++i) {
        if (arr_char[i] == '(') {
            pos1 = i;
        }else if (arr_char[i] == ')'){
            pos2 = i;
        }
    }
    if (pos2 != 0) {
        res = dare_brackets(pos1, pos2, arr_int, arr_char);
        flag=1;
    }

    for (int i = pos2; i < x; ++i) {
        if (arr_char[i+1] == '^') {
            res += pow((double)arr_int[i], (double)arr_int[i + 1]);
            flag = 1;
        }
    }

    for (int i = pos2; i < x; ++i) {
        if (arr_char[i+1] == '*' && flag == 1) {
            res *= arr_int[i];
        }else if((arr_char[i] == '*' && flag ==0)){
            res = arr_int[i] * arr_int[i + 1];
            flag = 1;
        }
    }
    for (int i = pos2; i < x; ++i) {
        if (arr_char[i+1] == '/' && flag == 1) {
            res /= arr_int[i];
        }else if((arr_char[i+1] == '/' && flag ==0)){
            res = arr_int[i] / arr_int[i + 1];
            flag = 1;
        }
    }
    for (int i = pos2; i < x; ++i) {
        if (arr_char[i+1] == '%' && flag == 1) {
            res = (int)res % arr_int[i];
        }else if((arr_char[i+1] == '%' && flag ==0)){
            res = arr_int[i] % arr_int[i + 1];
            flag = 1;
        }
    }

    for (int i = pos2; i < x; ++i) {
        if (arr_char[i + 1] == '+' && flag == 1) {
            res += arr_int[i];
        }else if(arr_char[i + 1] == '+' && flag ==0){
            res = arr_int[i] + arr_int[i +1];
            flag = 1;
        }
    }

    for (int i = pos2; i < x; ++i) {
        if (arr_char[i+1] == '-' && flag == 1) {
            res -= arr_int[i];
        }else if(arr_char[i+1] == '-' && flag ==0){
            res = arr_int[i] - arr_int[i +1];
            flag = 1;
        }
    }


    return res;

}

