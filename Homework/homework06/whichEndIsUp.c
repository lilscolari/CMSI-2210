#include <stdio.h>

// returns 1 for big endian, 0 for little
int main() {
    // first appearing byte is reassigned for little, not for big
    int first_location = 1;

    // point to the first appearing byte
    char *place_pointer = (char*)&first_location;

    // if the first appearing is unchanged, then its big endian
    if (*place_pointer == 0x00){
        printf("Big endian\n");
        return 1;
    }
    // otherwise, it is little
    printf("Little endian\n");
    return 0;
}