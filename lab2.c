/*
 ============================================================================
 Name        : Lab2.c
 Author      : Jonathan Sobers
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

// Option 1: Convert 8-bit binary string to signed decimal
void convert_binary_to_signed(const char *binary)
{
    int value = 0; //Takes a base value of 0 until entered

    // Basic for loop to increment value entered
    for (int i = 0; i < 8; i++) {
        value = value * 2 + (binary[i] - '0');
    }

    // Apply two's complement if Most Significant Bit is 1 
    if (binary[0] == '1') {
        value -= 256;  // Subtract 2 to the power of 8 to get signed value
    }

    // Display results
    printf("Signed decimal value: %d\n", value);
}

// Option 2: Convert 32-bit binary string to floating-point value
void convert_binary_to_float(const char *binary) {
    // Extract sign bit (0 = positive, 1 = negative)
    int sign = binary[0] - '0';

    //  For loop to increment again but this time it extracts exponent bits then removes the bias
    int exponent = 0;
    for (int i = 1; i <= 8; i++) {
        exponent = exponent * 2 + (binary[i] - '0');
    }
    exponent -= 127;

    // This part I reference w3 schools mantissa topic due to not knowing specifics of mantissa
    float mantissa = 1.0f;
    float factor = 0.5f;
    for (int i = 9; i < 32; i++) {
        if (binary[i] == '1') {
            mantissa += factor;
        }
        factor /= 2.0f;
    }

    // After running the above I believe you combine sign, mantissa, and exponent to get the final float value
    float result = (sign ? -1.0f : 1.0f) * mantissa * powf(2.0f, exponent);

    // Print results
    printf("Floating-point value: %f\n", result);
}
