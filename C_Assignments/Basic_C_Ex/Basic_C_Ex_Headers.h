#ifndef BASIC_C_EX_HEADERS_H
#define BASIC_C_EX_HEADERS_H

#define OK                    0
#define SIZE_ERROR            -1
#define CHAR_TO_PRINT_ERROR   -2




/*
Description -
Generic parameter validation function for all triangle and pyramid print functions.
Checks whether the number of lines and the character to print are valid.

Input -
lines     : Number of lines to print.
ch2print  : Character to print.

Output -
OK if all parameters are valid.

Error -
SIZE_ERROR            : lines is out of allowed range.
CHAR_TO_PRINT_ERROR   : ch2print is not a valid printable character.
*/
int Check_Parameters(int lines, char ch2print);



/*
Description - *
              **
              ***
              ****
              *****
              ******

Input -
n  : Number of lines.
ch : Character to print.

Output -
OK or ERROR

Error -
SIZE_ERROR or CHAR_TO_PRINT_ERROR
*/
int Print_LeftBottom_Aligend_Triag(int n, char ch);

/*
Description - ******
              *****
              ****
              ***
              **
              *

Input -
n  : Number of lines.
ch : Character to print.

Output -
OK or ERROR

Error -
SIZE_ERROR or CHAR_TO_PRINT_ERROR
*/
int Print_LeftTop_Aligend_Triag(int n, char ch);

/*
Description - *
              **
              ***
              ****
              ***
              **
              *

Input -
n  : Base height.
ch : Character to print.

Output -
OK or ERROR

Error -
SIZE_ERROR or CHAR_TO_PRINT_ERROR
*/
int Print_RightSide_Diamond(int n, char ch);

/*
Description -     *
                 * *
                * * *
                * * * *
               * * * * *
              * * * * * *

Input -
n  : Number of lines.
ch : Character to print.

Output -
OK or ERROR

Error -
SIZE_ERROR or CHAR_TO_PRINT_ERROR
*/
int Print_Pyramid(int n, char ch);

/*
Description - * * * *
               * * *
                * *
                 *

Input -
n  : Number of lines.
ch : Character to print.

Output -
OK or ERROR

Error -
SIZE_ERROR or CHAR_TO_PRINT_ERROR
*/
int Print_UpSideDown_Pyramid(int baseWidth, int n, char ch);

/*
Description -       *
                   * *
                  * * *
                 * * * *
                * * * * *
               * * * * * *
                * * * * *
                 * * * *
                  * * *
                   * *
                    *
Input -
n  : Base height.
ch : Character to print.

Output -
OK or ERROR

Error -
SIZE_ERROR or CHAR_TO_PRINT_ERROR
*/
int Print_Diamond(int n, char ch);

#endif
