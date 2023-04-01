#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    printf("Enter the first string: ");
    char firstString[100] = {'\0'};
    scanf_s("%s", firstString, (unsigned)_countof(firstString));
    printf("Enter the second string: ");
    char secondString[100] = {'\0'};
    scanf_s("%s", secondString, (unsigned)_countof(secondString));
    int lengthOfTheFirst = strlen(firstString);
    int lengthOfTheSecond = strlen(secondString);
    int count = 0;

    for (int i = 0; i <= (lengthOfTheFirst - lengthOfTheSecond); i++) {
        if (firstString[i] == secondString[0]) {
            bool isWrongChar = false;
            for (int j = 0; j < lengthOfTheSecond; j++) {
                isWrongChar = !(firstString[i + j] == secondString[j]);
                if (isWrongChar) {
                    continue;
                }
            }

            count += !isWrongChar;
        }
    }
    
    printf("the number of occurrences of the secong string in the first string as substrings is %d", count);
    return 0;
}
