#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char * argv[]){
    // Checks to see if the user inputted the arguments properly:
    if (argc != 2) {
        printf("Try running the program in this format: %s <file path>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    // Check if error opening file:
    if (file == NULL) {
        printf("Error opening file.");
        return 1;
    }

    int word_count = 0;
    int ch, previous_ch = ' ';

    // Loop through char by char:
    while ((ch = fgetc(file)) != EOF) {
        if (!isspace(ch) && isspace(previous_ch)) {
            word_count++;
        }
        previous_ch = ch;
    }

    // Check for file read error:
    if (ferror(file)) {
        printf("Error reading file");
        fclose(file);
        return 1;
    }

    // Close the file:
    fclose(file);

    printf("Number of words: %d", word_count);

    return 0;
}