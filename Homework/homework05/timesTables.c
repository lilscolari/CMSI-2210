#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    int val1;
    int val2;
    char input[3];
    printf( "Enter the size of table you want: " );

    // replace this with the fgets and val2 assignment for 2 parameters
    // scanf("%d %d", &val1, &val2);
    val1 = atoi(fgets(input, 3, stdin));
    val2 = val1;

    printf("\n");
    for (int i = 2; i <= val1; i++){
        for (int j = 2; j <= val2; j++){
            int temp = i * j;
            printf("%d\t", temp);
        }
        printf("\n");
    }
    printf("\n");
    exit(0);

}