/*
 * Application Name: Logging application
 * Date: 31/07/2025
 * Author: Yogeshwaran
 * Filename: main.c
 * File Details: Starting of the program, contains display menu and their handlers
 */

#include "main.h"

int main(){
    char *inputString = (char*)malloc(LIMIT); 
    char *tempInputString = (char*)malloc(LIMIT);  
    bool flag = true, firstTimeDisplayFlag = true, deleteLogFile = true;
    int exitChoice, userChoice;
    FILE *filePointer = fopen("LogFile.txt", "w");
    if(filePointer == NULL){
        perror("fopen");
        return 1;
    }
    do{
        if(firstTimeDisplayFlag){
            printf("----------WELCOME TO LOGGING SYSTEM!----------\n");
            printf("Enter a string that does not exceed 100 characters: ");
            scanf("\n%[^\n]", inputString);
            if(stringLength(inputString) > 100){
            printf("Character limit exceeds! Please enter a string within 100 characters!\n");
            free(tempInputString);
            free(inputString);
            return 1;
            } 
            fprintf(filePointer, "%s", INITIAL_MESSAGE);
            fprintf(filePointer, "%s",INPUT_MESSAGE);
            fprintf(filePointer, "%s\n", inputString);
        }
        stringCopy(tempInputString, inputString);
        printf("----------STRING MANIPULATION FUNCTIONS----------\n");
        printf("1. String reversal\n");
        printf("2. String compare\n");
        printf("3. String concatenation\n");
        printf("4. String copy\n");
        printf("5. Get String length\n");
        printf("6. Change to Uppercase\n");
        printf("7. Change to Lowercase\n");
        printf("8. Save and Export Logs\n");
        printf("9. Change input string\n");
        printf("0. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        switch(userChoice){
            case 1:
                fprintf(filePointer, "%s", USER_CHOICE_MESSAGE);
                fprintf(filePointer, "%d.",userChoice);
                fprintf(filePointer, "%s\n", "String reversal");
                char *reversedString = stringreverse(tempInputString);
                printf("The string after reversing is: %s", reversedString);
                fprintf(filePointer, "The string after reversing is: %s\n\n", reversedString);
                break;
            case 2:
                fprintf(filePointer, "%s", USER_CHOICE_MESSAGE);
                fprintf(filePointer, "%d.",userChoice);
                fprintf(filePointer, "%s\n", "String compare");
                char *newInputStringForComparing = (char*)malloc(LIMIT);
                printf("Enter the string to compare: ");
                scanf("\n%[^\n]", newInputStringForComparing);
                fprintf(filePointer, "User entered %s\n", newInputStringForComparing);
                int resultString = stringCompare(tempInputString, newInputStringForComparing);
                if(resultString == 0){
                    printf("Both Strings are equal!\n");
                    fprintf(filePointer, "%s\n\n", "Both Strings are equal!");
                }
                else if(resultString < 0){
                    printf("%s is greater!", newInputStringForComparing);
                    fprintf(filePointer, "%s\n\n is greater!", newInputStringForComparing);
                }
                else{
                    printf("%s is greater!",  tempInputString);
                    fprintf(filePointer, "%s is greater!\n\n",  tempInputString);
                }
                free(newInputStringForComparing);
                break;
            case 3:
                fprintf(filePointer, "%s", USER_CHOICE_MESSAGE);
                fprintf(filePointer, "%d.",userChoice);
                fprintf(filePointer, "%s\n", "String concatenation");
                char *newInputStringForConcatenation = (char*)malloc(LIMIT);
                printf("Enter the string to concatenate: ");
                scanf("\n%[^\n]", newInputStringForConcatenation);
                fprintf(filePointer, "User entered %s\n", newInputStringForConcatenation);
                char *concatenatedString = stringConcatenation(tempInputString, newInputStringForConcatenation);
                printf("The conacated string is: %s", concatenatedString);
                fprintf(filePointer, "The conacated string is: %s\n\n", concatenatedString);
                free(newInputStringForConcatenation);
                break;
            case 4:
                fprintf(filePointer, "%s", USER_CHOICE_MESSAGE);
                fprintf(filePointer, "%d.",userChoice);
                fprintf(filePointer, "%s\n", "String copy");
                char *newInputStringForCopy = (char*)malloc(LIMIT); 
                printf("Enter the replacing string: ");
                scanf("\n%[^\n]", newInputStringForCopy);
                fprintf(filePointer, "User entered %s\n", newInputStringForCopy);
                char *replacingString = stringCopy(tempInputString, newInputStringForCopy);
                printf("String %s is replaced by string %s", inputString, replacingString);
                fprintf(filePointer, "String %s is replaced by string %s\n\n", inputString, replacingString);
                free(newInputStringForCopy);
                break;
            case 5:
                fprintf(filePointer, "%s", USER_CHOICE_MESSAGE);
                fprintf(filePointer, "%d.",userChoice);
                fprintf(filePointer, "%s\n", "Get String length");
                int strLength = stringLength(inputString);
                printf("The Length of the string is: %d", strLength);
                fprintf(filePointer, "The Length of the string is: %d\n\n", strLength);
                break;
            case 6:
                fprintf(filePointer, "%s", USER_CHOICE_MESSAGE);
                fprintf(filePointer, "%d.",userChoice);
                fprintf(filePointer, "%s\n", "Change to Uppercase");
                toUpperCase(tempInputString);
                printf("String after changing to uppercase: %s", tempInputString);
                fprintf(filePointer, "String after changing to uppercase: %s\n\n", tempInputString);
                break;
            case 7:
                fprintf(filePointer, "%s", USER_CHOICE_MESSAGE);
                fprintf(filePointer, "%d.",userChoice);
                fprintf(filePointer, "%s\n", "Change to Lowercase");
                toLowerCase(tempInputString);
                printf("String after changing to lowercase: %s", tempInputString);
                fprintf(filePointer, "String after changing to lowercase: %s\n\n", tempInputString);
                break;
            case 8:
                fprintf(filePointer, "%s", USER_CHOICE_MESSAGE);
                fprintf(filePointer, "%d.",userChoice);
                fprintf(filePointer, "%s\n", "Save and Export Logs");
                printf("Data saved and log file exported successfully!");
                fprintf(filePointer, "Data saved and log file exported successfully!\n\n");
                deleteLogFile = false;
                break;
            case 9:
                fprintf(filePointer, "%s", USER_CHOICE_MESSAGE);
                fprintf(filePointer, "%d.",userChoice);
                fprintf(filePointer, "%s\n", "Change input string");
                char *newInput = (char*)malloc(LIMIT);
                printf("Enter a new input string: ");
                scanf("\n%[^\n]", newInput);
                stringCopy(inputString, newInput);
                stringCopy(tempInputString, newInput);
                printf("The new input string is: %s", inputString);
                fprintf(filePointer, "The user changed the input string to %s\n\n", newInput);
                break;
            case 0:
                fprintf(filePointer, "%s\n", "User exited by pressing '0'");
                printf("Exiting!!!");
                free(tempInputString);
                free(inputString);
                fclose(filePointer);
                if(deleteLogFile)
                    remove("LogFile.txt");
                return 0;
            default:
                printf("Please enter a correct option!\n");
        }
        printf("\nPress '1' to continue, press '0' to exit! ");
        firstTimeDisplayFlag = false;
        scanf("%d", &exitChoice);
        if(!exitChoice){
            flag = false;
            fprintf(filePointer, "%s\n", "User exited by pressing '0'");
            printf("Exiting!!!");
            free(tempInputString);
            free(inputString);
            fclose(filePointer);
            if(deleteLogFile)
                remove("LogFile.txt");
            return 0;
        }
        fprintf(filePointer, "%s\n", "User continued by pressing '1'");
    }while(flag);
}