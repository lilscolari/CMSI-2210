#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    unsigned int dec;
    char input[11];
    printf( "Enter a number: " );
    dec = atoi(fgets(input, 11, stdin));
    // The value at the 32nd bit, which will be halved every loop to get the value at the next bit
    unsigned int value_at_bit = 2147483648;
    for (int i = 0; i < 32; i++){
        if (value_at_bit <= dec){
            // when the bit is less or equal to the current number, subtract it
            // even though not apart of the question, the for loop can be replaced with while to make the function work on any length int
            dec -= value_at_bit;
            printf("1");
        }else{
            printf("0");
        }
        value_at_bit /= 2;
    }
    printf("\n");
    exit(0);

}
