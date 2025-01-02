#include <time.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char * argv[]){
    float timeHoldingBreath;
    char inputKey;
    bool isEnter = false;
    time_t startTime, endTime;

    printf("This program will time how long you can hold your breath.\n"
           "Take a deep breath, then press the 'Enter' key.\n"
           "When you absolutely have to exhale, press the enter key again.\n"
           "The duration will be displayed in minutes and seconds.\n");

    inputKey = getchar();

    // Check if input key is enter:
    if (inputKey == '\n') {
        startTime = time(NULL);
        isEnter = true;
        // Use a while loop to check until enter is pressed next:
        while (isEnter) {
            inputKey = getchar();
            if (inputKey == '\n') {
                endTime = time(NULL);
                isEnter = false;
            }
        }
        // Calculate minutes and seconds:
        double duration = difftime(endTime, startTime);
        int minutes = (int)duration / 60;
        int seconds = (int)duration % 60;
        printf("You held your breath for %d minutes and %d seconds.\n", minutes, seconds);
    } else {
        printf("Press the 'Enter' key to start the timer.");
    }
    return 0;
}
