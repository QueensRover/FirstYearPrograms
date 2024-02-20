#include <stdio.h> //Include necessary libraries for input/ output and file reading/writing
#include <stdlib.h>

int main() {
    FILE* fp = fopen("payloads.txt", "r"); //Create pointers to the read and write files
    FILE* fpw = fopen("ores.txt", "w");
    int numOfPayloads; //Create a variable to store the number of payloads being calculated
    if(fp == NULL){ //If the file pointer is pointing to nothing, tell the user, and stop the program
        printf("File not found.\n");
        return 0;
    }else{ //If the file pointer is correct, take the number of payloads from the text file and store it in the appropriate variable
        fscanf(fp, "%d", &numOfPayloads); 
    }
    if(numOfPayloads == 0){ //If there are no payloads to evaluate, tell the user and stop the program
        printf("No payloads in file.\n");
        return 0;
    }
    float* pNumPointers[numOfPayloads]; //Create an array of pointers for all the payloads
    int mass; //Create variables to take the mass and ore grade of the payloads
    float grade;
    for(int i = 0; i < numOfPayloads; i++){ //Loop through the pointer array for however manh payloads there are
        pNumPointers[i] = (float *) calloc(3, sizeof(float)); //Set each pointer in the array to accept three float values, creating a 2d array
        if(pNumPointers[i] == NULL){ //If the memory could not be allocated, tell the user and stop the program
            printf("Memory could not be allocated.");
            return 0;
         }
        fscanf(fp, "\n%d %f", &mass, &grade); //take the mass and ore grade values from the text file and store them in their respective spots in the 2d pointer array
        pNumPointers[i][0] = mass;
        pNumPointers[i][1] = grade;
    }
    float mOre[numOfPayloads]; //Create an array to store the mass of ore in each payload
    float pOre = 8500; //Create a variable to represent the price of the ore per kg
    for(int i = 0; i < numOfPayloads; i++){ //Loop through the pointer array for however manh payloads there are
        mOre[i] = pNumPointers[i][0]*pNumPointers[i][1]; //Calculate the mass of ore using the equation More = Gore * Mtotal
        pNumPointers[i][2] = mOre[i]*pOre; //Set the third value of each payload data set to the price of the load using the equation Vore = More * Pore
    }
    printf("Payload Data:\nTotal Mass/ Grade / Ore Value\n"); //Print out the unsorted list of values to the console
    for(int i = 0; i < numOfPayloads; i++){
        printf("   %.0f      %.2f    $%.0f\n", pNumPointers[i][0], pNumPointers[i][1], pNumPointers[i][2]);
    }
    float insertionElement, insertionElementTwo, insertionElementThree; //Create three insertion elements for all three values of the payload
    int j;
    for(int i = 0; i < numOfPayloads; i++){ //Loop through the pointer array for however manh payloads there are
        insertionElement = pNumPointers[i][2]; //Set three insertion elements to their respective values
        insertionElementTwo = pNumPointers[i][0];
        insertionElementThree = pNumPointers[i][1];
        for(j = i-1; j > -1; j--){ //Traverse through the array
            if(insertionElement < pNumPointers[j][2]){ //Find where the value belongs by moving elements back
                pNumPointers[j+1][2] = pNumPointers[j][2];
                pNumPointers[j+1][0] = pNumPointers[j][0];
                pNumPointers[j+1][1] = pNumPointers[j][1];
            }else{
                break;
            }
        }
        pNumPointers[j+1][2] = insertionElement; //Set the sorted value to the insertion elements from earlier
        pNumPointers[j+1][0] = insertionElementTwo;
        pNumPointers[j+1][1] = insertionElementThree;
    }
    if(fpw == NULL){ //If the file pointer is pointing to nothing, tell the user, and stop the program
        printf("File not found.\n");
        return 0;
    }else{ //If the file pointer is valid, print the sorted values to the writing text file
        fprintf(fpw, "Sorted Payload Data:\nTotal Mass / Grade / Ore Value\n");
        for(int i = numOfPayloads-1; i > -1; i--){
            fprintf(fpw, "   %.0f      %.2f    $%.0f\n", pNumPointers[i][0], pNumPointers[i][1], pNumPointers[i][2]);
        }
    }
    fclose(fp); //Close the file pointers
    fclose(fpw);
    return 0;
}