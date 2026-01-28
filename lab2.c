/*
 ============================================================================
 Name        : Lab2.c
 Author      : Austin Tian
 Version     :
 Copyright   : Copyright 2020
 Description : Signed number and unsigned numbers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 32   // maximum size of the binary number is 32 bit. 
#define number1 "11000001010010000000000000000000"
#define number2 "01000001010101000000000000000000"
void convert_binary_to_signed(const char *binary);
void convert_binary_to_float(const char *binary);
char *menu =    "\n" \
                "\n" \
                "===================================================================\n" \
                "************Please select the following options********************\n" \              
                " *    1. Binary number to signed decimal number conversion.(Lab 2) *\n" \
                " *    2. Binary number to Floating number conversion (Lab 2)       *\n" \
                " *******************************************************************\n" \
                " *    e. To Exit, Type 'e'                                         *\n" \
                " *******************************************************************\n";

int main(void) {
	    char options;  // the option should only be a byte
        char inputs[33] = {0};  // 32-bit string plus a ending indicator.         
        do{
            puts(menu); /* prints Memory Simulation */
            fflush(stdin);  // clear the input buffer before getchar. 
            options = getchar();
            switch (options)
            {             
                case '1': /* lab 2. Convert binary number into a SIGNED decimal
                           number and display */
                    puts("Please input your BINARY number, "\
                            "I will convert it to signed decimal:");
                    scanf("%s", &inputs[0]);  // Input must be a string with 0/1
                    // Finish function convert_binary_to_signed to convert the 8-bit binary inputs to signed decimal number.
                     convert_binary_to_signed(inputs);
                    continue;
                case '2':/* lab 2. Convert 32-bit binary number into a floating 
                          *  point number number and display */
                    puts("Please input your 32-bit floating point number " \
                            "in binary, I will convert it to decimal");
                    scanf("%s", &inputs[0]);  // Input must be a string with 0/1
                    // Finish function convert_binary_to_float to convert the 32-bit binary inputs to floating point number. 
                     convert_binary_to_float(inputs);
                    continue;  
                case 'e':
                    puts("Code finished, exit now");
                    return EXIT_SUCCESS;
                default:
                    puts("Not a valid entry, exit now");
                    continue;                  
            } 
        }while (1);
}
//Option 1 convert binary to signed
void convert_binary_to_signed(const char *binary)
{
    int value = 0;
    // Converting an 8-bit binary string to integer using for loop
    for (int i = 0; i < 8; i++) {
        value = value * 2 + (binary[i] - '0');
    }
    // If MSB is 1, interpret as negative
    if (binary[0] == '1') {
        value -= 256;  // 2^8
    }
    printf("Signed decimal value: %d\n", value);
}
//Option 2 convert binary to float
void convert_binary_to_float(const char *binary) {
    int sign = binary[0] - '0';
    int exponent = 0;
    for (int i = 1; i <= 8; i++) {
        exponent = exponent * 2 + (binary[i] - '0');
    }
    exponent -= 127;
    float mantissa = 1.0f;
    float factor = 0.5f;
    for (int i = 9; i < 32; i++) {
        if (binary[i] == '1') {
            mantissa += factor;
        }
        factor /= 2.0f;
    }
    float result = (sign ? -1.0f : 1.0f) * mantissa * powf(2.0f, exponent);
    printf("Floating-point value: %f\n", result);
}
