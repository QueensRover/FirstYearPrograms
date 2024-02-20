#include <stdio.h>
#include <string.h> //Include the string.h library

int main() {
    int numOfStrings; //Create a variable to hold the number of strings the user wants to have
    printf("Enter number of acronyms to add to the database: "); //Ask the user how many acronyms they want to make and store that in the appropriate variable
    scanf("%d", &numOfStrings);
    scanf("%*c"); //Clear the input stream for fgets
    char userString[numOfStrings+1][50]; //Create necessary arrays for the users strings and corresponding acronyms
    char capChar[2];
    char acronyms[numOfStrings+1][50];
    for(int i = 0; i < numOfStrings; i++){ //Loop will run for the number of acronyms needed
        printf("\n\nEnter the string to convert into an acronym: "); //Asking the user to input what they would like to turn into an acronym and storing that in the appropriate array
        fgets(userString[i], 50, stdin);
        if(userString[i][strlen(userString[i])-1] == '\n'){ //Make sure the string ends with a null character, not a newline
            userString[i][strlen(userString[i])-1] = '\0';
        }
        capChar[0] = userString[i][0]; //Since the loop does not account for the first letter in the string, make the first letter in the string the first letter of the acronym, if it is capital
        capChar[1] = '\0';
        if(userString[i][0]  > 64 && userString[i][0] < 91){
            strcat(acronyms[i], capChar);
        }
        for(int j = 0; j < (int) strlen(userString[i]); j++){ //Loop that will run for the length of the string inputted
            if(userString[i][j] > 64 && userString[i][j] < 91 && userString[i][j-1] == ' '){ //If the string being checked is a capital letter and comes after a space, add that letter onto the acronym
                capChar[0] = userString[i][j];
                capChar[1] = '\0'; //Making sure the string ends in a null character
                strcat(acronyms[i], capChar); //Add capital letter to acronym
            }
        }
        printf("\nAcronym of \"%s\" is \"%s\".", userString[i], acronyms[i]); //Print the string that was turned into an acronym
    }
    int x = 0; //Initialize variable to loop and array to get and use the users answer
    char userAnswer[50];
    while(x == 0){ //Start to loop indefinitely
        int isFound = 0; //Flag to check if the acronym is found or not
        printf("\n\nEnter the acronym of the string you would like to see, or enter 0 to exit:\n "); //Ask the user to enter the acronym they would like to see the string of and put that input into the appropriate variable
        fgets(userAnswer, 50, stdin);
        if(userAnswer[strlen(userAnswer)-1] == '\n'){ //Make sure the string ends in a null character, not a newline
            userAnswer[strlen(userAnswer)-1] = '\0';
        }
        if(strcmp(userAnswer, "0") == 0){ //If the user inputted a 0, stop the loop
            x++;
        }
        for(int i = 0; i < numOfStrings; i++){ //Loop through all the different strings
            if(strcmp(userAnswer, acronyms[i]) == 0){ //Check if the users acronym is the same as any acronyms in the database
                printf("\nThe corresponding string to \"%s\" is \"%s\".", userAnswer, userString[i]); //If a match is found, print that to the user
                isFound = 1; //Flag that a match was found
            }
        }
        if(isFound == 0 && x == 0){ //If no match was found and the loop is not stopping, send this message to the user
            printf("\nNo match found.");
        }
    }
    return 0;
}