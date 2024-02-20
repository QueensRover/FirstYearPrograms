#include <stdio.h>
#include <math.h>

int main() {
    //Declare all neede variables as floating point numbers
    float mass, acceleration, force, thrustPerTruster, maxThrusters, minThrusters, actualThrusters, maxEfficiency, realEfficiency;
    //Prompt user to input mass and acceleratoin of the rocket and assign them to their respective variables
    printf("Input the mass (kg), and required acceleration of the rocket (m/s^2):\n");
    scanf("%f %f", &mass, &acceleration);
    //Calculate the required force and print the number to the user
    force = (float) mass * ((float)acceleration + 9.81); //Equation 1
    printf("The rocket needs %0.2fN of force.", force);
    //Prompt the user to input the amount of thrust provided by each thruster and assign it to its respective variable
    printf("\nInput the thrust provided (N) by each thruster:\n");
    scanf("%f", &thrustPerTruster);
    //Calculate the minimum number of thrusters, maximum number of thrusters, most efficient number of thrusters and thruster power, and the real thruster power
    minThrusters = (float) ceil(force/thrustPerTruster);
    maxThrusters = (float) floor(force/(thrustPerTruster/2));
    maxEfficiency = ((float) 100- log2(force)); //Equation 2
    actualThrusters = round((float) force/(((float) maxEfficiency/100)*thrustPerTruster));
    realEfficiency = (float) ((float) force/((float) ceil(actualThrusters)*thrustPerTruster))*100; //Equation 3
    //Print the minimum number of thrusters, maximum number of thrusters, most efficient number of thrusters and thruster power, and the real thruster power to the user
    printf("The rocket needs at least %0.0f thrusters.", minThrusters);
    printf("\nThe rocket can have at most %0.0f thrusters.", maxThrusters);
    printf("\nThrusters are most efficient at %0.2f%%.", maxEfficiency);
    printf("\nThe rocket is most efficient with %0.0f thrusters, using %0.2f%% of its power.\n", actualThrusters, realEfficiency);
    return 0;
}
