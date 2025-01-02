//#include "makeNBOC.c"
#include <stdio.h>

int nbocConverter(int original);

int main(){
    printf("Taking \"1\" as an input: ");
    int j = nbocConverter(1);
    printf("%d\n", j);
}
