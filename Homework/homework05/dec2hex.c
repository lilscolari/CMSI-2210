#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    // Checks to see if the user inputted the arguments properly:
    if (argc < 2) {
        printf("Try running the program in this format: %s <decimal number> [8 or 16]\n", argv[0]);
        return 1;
    }

    unsigned long long decimal = strtoull(argv[1], NULL, 10);
    int hexDigits = 8;

    // Ensures the second argument is a proper input:
    if (argc >= 3) {
        hexDigits = atoi(argv[2]);
        if (hexDigits != 8 && hexDigits != 16) {
            printf("The second argument must be 8 or 16.");
            return 1;
        }
    }

    // Returns the hexademical representation according to second argument:
    if (hexDigits == 8) {
        printf("0x%08X\n", (unsigned int)decimal);
    } else if (hexDigits == 16) {
        printf("0x%016llX\n", decimal);
    }
    return 0;
}