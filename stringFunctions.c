/*
Author: Yogeshwaran
Date: 31/07/2025
FileName: stringFunctions.c
FileDetails: Detailed definitions of the declared string functions
*/

#include "main.h"

int isOnlyWhitespace(char *input){
    while (*input) {
        if (!isspace((unsigned char)*input))
            return 0;
        input++;
    }
    return 1;
}

//Function to reverse a given string
char *stringreverse(char *input){
    int start = 0, end = (stringLength(input)) - 1;
    char temp;
    while(start < end){
        temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
    return input;
}

//Function to compare the given strings
int stringCompare(char *firstString, char *secondString) {
    int index = 0;
    while (firstString[index] != '\0' && secondString[index] != '\0') {
        if (firstString[index] != secondString[index]) {
            if (firstString[index] < secondString[index])
                return -1;
            else
                return 1;
        }
        index++;
    }
    if (firstString[index] == '\0' && secondString[index] == '\0')
        return 0;
    else if (firstString[index] == '\0')
        return -1;
    else
        return 1;
}

//Function to concatenate two strings
char *stringConcatenation(char *oldInput, char *newInput){
    int endIndexOfOldInput = stringLength(oldInput), startIndexOfNewInput = 0;
    while(newInput[startIndexOfNewInput] != '\0'){
        oldInput[endIndexOfOldInput++] = newInput[startIndexOfNewInput++];
    }
    oldInput[endIndexOfOldInput] = '\0';
    return oldInput;
}

//Function to replace a string
char *stringCopy(char *destination, char *source){
    int index = 0;
    while(source[index] != '\0'){
        destination[index] = source[index];
        index++;
    }
    destination[index] = '\0';
    return destination;
}

//Function to get the length of the string
int stringLength(char *input){
    int count = 0, index = 0;
    while(input[index++] != '\0')
        count++;
    return count;
}

//Function to convert a string to uppercase
void toUpperCase(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - 32;
        }
    }
}

//Function to convert a string to lowercase
void toLowerCase(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + 32;
        }
    }
}