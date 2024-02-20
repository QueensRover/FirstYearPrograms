#include <stdio.h>
#include <math.h> //Include the math library for math functions

//Create function to compute the Riemann Sum using the LEFT method
double lRiemannSum(double lowerBound, double upperBound, double intervals){ //Take the bounds and the intervals as the parameters
    double width = (upperBound - lowerBound)/intervals; //Calculate the width of the rectangles according to the number of intervals
    double sum = 0.0;
    double x = lowerBound;
    for(int i = 0; i < intervals; i++){ //Calculate the sum
        sum += width*exp(x*x);
        x += width;
    }
    return sum; //Return the sum
}
//Create a function to compute the factorial of a number
double factorial(double n){
    double fact = 1.0; //Create the variable to store the factorial each iteration
    for(int i = 1; i <= n; i++){ //Calculate the factorial
        fact *= i;
    }
    return fact; //Return the factorial
}
//Create a function to compute the taylor series
double taylorSeries(double lowerBound, double terms){ //Take in the lower bound and number of terms as the parameters
    double sum = 0.0;
    for(int i = 0; i < terms; i++){ //Calculate the taylor series approximation
        sum += (pow(pow(lowerBound, 2),i))/factorial(i);
    }
    return sum; //Return the value given by the approximation
}
//Create a function to compute the taylor riemann sum
double taylorRiemannSum(double lowerBound, double upperBound, double intervals){ //Take in the bounds and number of intervals as the parameters
    double width = (upperBound - lowerBound)/intervals; //Calculate the width of the rectangles according to the number of intervals
    double sum = 0.0;
    double x = lowerBound;
    for(int i = 0; i < intervals; i++){ //Now using the taylor series approximation, calculate the riemann sum
        sum += taylorSeries(x, 10) * width;
        x += width;
    }
    return sum; //Return the value given by the sum
}
//Create a function to calculate error
double error(double sum1, double sum2){ //Take two different sums as the parameters
    return (1-(sum1/sum2))*100; //Return the percentage of error between the two sums
}
int main() {
    float lowerBound, upperBound; //Create variables for the upper and lower bounds
    printf("Enter the bounds to compute the Riemann Sum:"); //Ask the user to enter the desired bounds
    scanf("%f %f", &lowerBound, &upperBound); //Take the user input and store it in the appropriate bound variables
    //Print out the 3 different intervals of the riemann sum
    printf("Riemann Sum with 5 intervals: %.2f\n",lRiemannSum(lowerBound, upperBound, 5));
    printf("Riemann Sum with 25 intervals: %.2f\n", lRiemannSum(lowerBound, upperBound, 25));
    printf("Riemann Sum with 100 intervals: %.2f\n", lRiemannSum(lowerBound, upperBound, 100));
    printf("--------------------------------------------------------\n");
    //Print out the 3 different term values for the taylor series
    printf("Taylor Series Approximation at x = %.2f with 3 terms: %.2f\n", lowerBound, taylorSeries(lowerBound, 3));
    printf("Taylor Series Approximation at x = %.2f with 5 terms: %.2f\n", lowerBound, taylorSeries(lowerBound, 5));
    printf("Taylor Series Approximation at x = %.2f with 10 terms: %.2f\n", lowerBound, taylorSeries(lowerBound, 10));
    printf("--------------------------------------------------------\n");
    //Print out the 3 different intervals for the taylor series riemann sum
    printf("Taylor Series Riemann Sum with 5 intervals: %.2f\n", taylorRiemannSum(lowerBound, upperBound, 5));
    printf("Taylor Series Riemann Sum with 25 intervals: %.2f\n", taylorRiemannSum(lowerBound, upperBound, 25));
    printf("Taylor Series Riemann Sum with 100 intervals: %.2f\n", taylorRiemannSum(lowerBound, upperBound, 100));
    printf("--------------------------------------------------------\n");
    //Print out the error in the 3 different intervals of riemann sums 
    printf("Error in Riemann Sums with 5 intervals: %.2f%%\n", error(lRiemannSum(lowerBound, upperBound, 5),taylorRiemannSum(lowerBound, upperBound, 5)));
    printf("Error in Riemann Sums with 25 intervals: %.2f%%\n", error(lRiemannSum(lowerBound, upperBound, 25),taylorRiemannSum(lowerBound, upperBound, 25)));
    printf("Error in Riemann Sums with 100 intervals: %.2f%%\n", error(lRiemannSum(lowerBound, upperBound, 100),taylorRiemannSum(lowerBound, upperBound, 100)));
    return 0;
}