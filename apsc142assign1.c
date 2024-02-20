#include <stdio.h>
#include <stdbool.h> //Import required libraries
#include <math.h>

int main() { 
    int numOfRocks; //Create a variable to hold the number of rocks the user would like to analyze
    int lowestSG = 0;
    int highestFlowRate = 0; //Create and initialize a variables to signify which rock has certain attributes
    int highestPorosity = 0;
    printf("Enter the number of limestones to compare: "); //Ask the user to give the number of limestones they would like to compare
    scanf("%d", &numOfRocks); //Take the users number and store it in the numOfRocks variable
    float rockData[numOfRocks][4]; //Create a two-dimensional array to hold the required data for the users number of rocks
    for(int i = 0; i < numOfRocks; i++){ //Asking the user to input the required information about the limestone and putting it into its respective spot in the array
        printf("\nEnter the porosity %%, hydraulic conductivity (m/s), and specific gravity for Limestone %d: ", i+1);
        scanf("%f %f %f", &rockData[i][0], &rockData[i][1], &rockData[i][2]);
        rockData[i][3] = (0.725*1200*rockData[i][1])*1000000;
    }
    for(int x = 0; x < numOfRocks; x++){ //Looping through the array and checking to see which rock has the lowest specific gravity, highest flow rate, and highest porosity
        if( rockData[x][2] < rockData[lowestSG][2]){
            lowestSG = x+1;
        }
        if(rockData[x][3] > rockData[highestFlowRate][3]){
            highestFlowRate = x;
        }
        if(rockData[x][0] > rockData[highestPorosity][0]){
            highestPorosity = x;
        }
    }
    if(lowestSG == 0){ //Making sure the lowest specific gravity is in terms of rock number, not index
        lowestSG += 1;
    }
    printf("\nThe limestone with the lowest specific gravity is Limestone %d with a specific gravity of %f\n\nFlow velocities:\n", lowestSG, rockData[lowestSG-1][2]); //Print the rock with the lowest specific gravity and its value
    for(int y = 0; y < numOfRocks; y++){ //Print out all the flow velocities of the rocks, making sure they are all positive
        printf("\nLimestone %d: %.2f cm^3/s\n", y+1, fabsf(rockData[y][3]));
    }
    bool bothEqual = false; //Create a boolean to check if the rock with the highest porosity also has the highest flow rate
    if(highestPorosity == highestFlowRate) //If the rock with the highest flow rate and highest porosity are the same rock, set the boolean equal to true
        bothEqual = true;

    if(bothEqual == true){ //If the rock with the highest flow rate is the rock with the highest porosity, print the first message, if not, print the second
        printf("\nThe rock with the highest porosity has the highest flow velocity.\n");
    }else{
        printf("\nThe rock with the highest porosity does not have the highest flow velocity.\n");
    }
    return 0; //Exit the code
}
