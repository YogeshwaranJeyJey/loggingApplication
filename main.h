/*
Author: Yogeshwaran
Date: 31/07/2025
FileName: main.h
FileDetails: Includes all the necessary library files, macro definitions and Function declarations
*/

#ifndef MAIN_H
#define MAIN_H

#define LIMIT 100
#define INITIAL_MESSAGE "LOG DETAILS!\n"
#define INPUT_MESSAGE   "The User Entered input string is: "
#define USER_CHOICE_MESSAGE "\nThe User selected option "

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *stringreverse(char *input);
int stringCompare(char *firstString, char *secondString);
char *stringConcatenation(char *oldInput, char *newInput);
char *stringCopy(char *destination, char *source);
int stringLength(char *input);
void toUpperCase(char *input);
void toLowerCase(char *input);

#endif