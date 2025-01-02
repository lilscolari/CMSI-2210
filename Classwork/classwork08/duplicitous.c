#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void print_usage() {
    printf("Usage: duplicitous [filename] [copies]\n");
    printf("  filename: the input file\n");
    printf("  copies: the number of times to repeat the first part of the file (between 1 and 10)\n");
}

int main(int argc, char *argv[]) {
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *inputFile, *outputFile;
    int copies = 1, count;
    
    if (argc >= 2) {
        strncpy(filename, argv[1], MAX_LINE_LENGTH);
    } else {
        printf("Enter the filename: ");
        scanf("%s", filename);
    }

    if (argc >= 3) {
        copies = atoi(argv[2]);
    } else {
        printf("Enter the number of copies (between 1 and 10): ");
        scanf("%d", &copies);
        if (copies < 1 || copies > 10) {
            printf("Invalid number of copies. Please enter a number between 1 and 10.\n");
            return 1;
        }
    }

    inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    if (fgets(line, sizeof(line), inputFile) != NULL) {
        count = atoi(line);
        printf("File %s is open, will copy %d lines\n", filename, count);
    } else {
        printf("Error reading the first line of the file.\n");
        fclose(inputFile);
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    for (int i = 0; i < copies; i++) {
        fseek(inputFile, 0, SEEK_SET);
        fgets(line, sizeof(line), inputFile);

        for (int j = 0; j < count; j++) {
            if (fgets(line, sizeof(line), inputFile) != NULL) {
                fputs(line, outputFile);
            } else {
                printf("Error reading line %d from input file.\n", j + 1);
                break;
            }
        }
        fputs("\n", outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);

    printf("File copied successfully to output.txt.\n");
    return 0;
}
