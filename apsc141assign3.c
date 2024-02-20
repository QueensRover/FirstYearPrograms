#include <stdio.h>
#include <stdbool.h> //Include the stdbool library to be able to create a boolean to check if the student has failed or not

int main() {
    //Create variables for the grades, the average, the failed boolean, and a char for the letter grade
    bool failed = false;
    char letterGrade;
    float modeling, design, teamwork, reflection, professionalism, communication, average;
    //Prompt the user to input the grades and store the input in their respective variables
    printf("Please input grades for all six CLOs, separated by spaces:\n");
    scanf("%f %f %f %f %f %f", &modeling, &design, &teamwork, &reflection, &professionalism, &communication);
    //Create an array for the first four grades to easily iterate through them using a for loop
    float requiredCLOS[] = {modeling, design, teamwork, reflection};
    //Use a for loop to check for any grades under 50.00% in the required CLOS
    for(int x = 3; x>-1; x--){
        //If a grade is under 50.00%, set failed equal to true
        if(requiredCLOS[x] < 50.00){
            failed = true;
            x = -1;
        }
    }
    //If failed was set to true, tell the student that they failed a required CLO
    if(failed){
        printf("You failed a required CLO!\n");
    }
    //Calculate the students average grade
    average = (float) (modeling+design+teamwork+reflection+professionalism+communication)/6;
    //if the students average grade is below 50.00%, tell them that they failed and set the failed boolean to true
    if(average < 50.00){
        printf("You failed by overall grade!\n");
        failed = true;
    }
    //Print the average grade to the user and check to see which grade range it falls in and assign the corresponding letter
    printf("Your average was %0.2f%%.\n", average);
    if(average>= 50.00 && average<60.00){
        letterGrade = 'D';
    }else if(average>= 60.00 && average < 70.00){
        letterGrade = 'C';
    }else if(average>= 70.00 && average<80.00){
        letterGrade = 'B';
    }else if(average>= 80.00){
        letterGrade = 'A';
    }
    //If the student failed the course due to overall grade or a failed required CLO, print this statement to the student
    if(failed){
        printf("You failed the course!\n");
    }else{ //Only runs if the student didn't fail the course; tell the student that they passed and tell them their letter grade
        printf("You passed the course!\n");
        printf("Your grade is %c!\n", letterGrade);
    }
    return 0;
}
