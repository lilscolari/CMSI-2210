#include <assert.h>
#include <stdio.h>

extern int findGCDfunc(int num1, int num2);

int main() {
    int num1 = 33;
    int num2 = 99;

    int result = findGCDfunc(num1, num2);

    assert(result == 33);

    printf("The GCD of %d and %d is: %d\n", num1, num2, result);
    
    return 0;
}