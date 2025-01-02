#include <stdio.h>

int nbocConverter(int original){
    // first appearing byte is reassigned for little, not for big
    int first_location = 1;

    // point to the first appearing byte
    char *place_pointer = (char*)&first_location;

    // if the first appearing is unchanged, then its big endian
    if (*place_pointer == 0x00){
        // no changes needed if it is already big endian
        return original;
    }
    // otherwise, it is little and needs to be changed
    // int new_int = hton(original);
    return __builtin_bswap32(original);
}
