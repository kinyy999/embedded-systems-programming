#include <stdio.h>
#include "Basic_C_Ex_Headers.h"

static void PrintStatus(int status)
{
    if (status == OK)
    {
        printf("Status: OK\n");
    }
    else if (status == SIZE_ERROR)
    {
        printf("Status: SIZE_ERROR\n");
    }
    else if (status == CHAR_TO_PRINT_ERROR)
    {
        printf("Status: CHAR_TO_PRINT_ERROR\n");
    }
    else
    {
        printf("Status: UNKNOWN_ERROR (%d)\n", status);
    }
}

int main(void)
{
    int status;

    /* -------------------- VALID CASE -------------------- */
    printf("=== VALID CASE (lines=6, ch='*') ===\n");

    printf("\n-- Print_LeftBottom_Aligend_Triag --\n");
    status = Print_LeftBottom_Aligend_Triag(6, '*');
    PrintStatus(status);

    printf("\n-- Print_LeftTop_Aligend_Triag --\n");
    status = Print_LeftTop_Aligend_Triag(6, '*');
    PrintStatus(status);

    printf("\n-- Print_Pyramid --\n");
    status = Print_Pyramid(6, '*');
    PrintStatus(status);

    printf("\n-- Print_UpSideDown_Pyramid --\n");
    status = Print_UpSideDown_Pyramid(6, 6, '*');
    PrintStatus(status);

    printf("\n-- Print_RightSide_Diamond --\n");
    status = Print_RightSide_Diamond(6, '*');
    PrintStatus(status);

    printf("\n-- Print_Diamond --\n");
    status = Print_Diamond(6, '*');
    PrintStatus(status);

    /* -------------------- ERROR CASE: SIZE_ERROR -------------------- */
    printf("\n\n=== ERROR CASE: SIZE_ERROR (lines=0) ===\n");
    status = Print_LeftBottom_Aligend_Triag(0, '*');
    PrintStatus(status);

    /* -------------------- ERROR CASE: CHAR_TO_PRINT_ERROR -------------------- */
    printf("\n=== ERROR CASE: CHAR_TO_PRINT_ERROR (ch not printable) ===\n");
    status = Print_LeftBottom_Aligend_Triag(6, '\n');
    PrintStatus(status);

    return 0;
}
