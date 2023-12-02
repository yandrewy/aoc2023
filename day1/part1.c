#include <stdio.h>
#include <ctype.h>

int main (void)
{
        char c;
        int intsinline;
        int firstint;
        int secondint;
        int total;
        FILE *fptr;

        //open the file
        fptr = fopen("input.txt", "r");

        total = 0;

        while ((c = fgetc(fptr)) != EOF) {
                if (c == '\n') {
                        intsinline = 0;
                        if (secondint == 0) {
                                secondint = firstint;
                        }
                        total = total + (10 * firstint) + secondint;
                        /*
                        printf("%i %i t%i ", firstint, secondint, total);
                        */
                        firstint = 0;
                        secondint = 0;
                        continue;
                }
                if (isalpha(c)) {
                        continue;
                }
                if (intsinline == 0) {
                        firstint = (int)c - '0';
                        intsinline++;
                        continue;
                }
                secondint = (int)c - '0';

        }

        //close the file
        fclose(fptr);

        printf("%i", total);
        return 0;
}
