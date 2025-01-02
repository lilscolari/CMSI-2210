#include <stdio.h>
#include <string.h>

int main() {
    int numbers[25];
    int count = 0; 
    int input;
    int sum = 0;
    double average;
    char concatenatedString[1000] = "";
    int sevenCount = 0;

    printf("Enter numbers (enter -9999 to stop):\n");
    while (count < 25) {
        printf("Enter number %d: ", count + 1);
        scanf("%d", &input);

        if (input == -9999) {
            break;
        }
        numbers[count] = input;
        count++;
    }

    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    printf("Sum of numbers: %d\n", sum);

    if (count > 0) {
        average = (double)sum / count;
        printf("Average of numbers: %.2f\n", average);
    } else {
        printf("No numbers were entered.\n");
    }

    for (int i = 0; i < count; i++) {
        char temporaryString[20];
        sprintf(temporaryString, "%d", numbers[i]);
        strcat(concatenatedString, temporaryString);
    }
    printf("Concatenated numbers: %s\n", concatenatedString);

    for (int i = 0; concatenatedString[i] != '\0'; i++) {
        if (concatenatedString[i] == '7') {
            sevenCount++;
        }
    }
    printf("Number of '7's in the string: %d\n", sevenCount);

    return 0;
}
