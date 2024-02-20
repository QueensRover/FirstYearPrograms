#include <stdio.h>
#include <math.h>

int main() {
    float cost1, cost2, cost3, maintenance1, maintenance2, maintenance3, totalMaintenance1, totalMaintenance2, totalMaintenance3, projectLifespan;
    printf("Please input the initial costs of the three trucks:\n");
    scanf("%f %f %f", &cost1, &cost2, &cost3);
    printf("Please input the initial yearly maintenance costs of the three trucks:\n");
    scanf("%f %f %f", &maintenance1, &maintenance2, &maintenance3);
    printf("Please input the project lifespan in years:\n");
    scanf("%f", &projectLifespan);
    totalMaintenance1 = maintenance1;
    totalMaintenance2 = maintenance2;
    totalMaintenance3 = maintenance3;
    for(int x = 1; x < projectLifespan; x++){
        maintenance1 *= 1.1;
        maintenance2 *= 1.1;
        maintenance3 *= 1.1;
        totalMaintenance1 += maintenance1;
        totalMaintenance2 += maintenance2;
        totalMaintenance3 += maintenance3;
    }
    printf("The cost of truck 1 after %0.0f years is $%0.2f.\nNext year's maintenance will be $%0.2f.\n", floor(projectLifespan/2), totalMaintenance1+cost1, maintenance1*1.1);
    printf("The cost of truck 2 after %0.0f years is $%0.2f.\nNext year's maintenance will be $%0.2f.\n", floor(projectLifespan/2), totalMaintenance2+cost2, maintenance2*1.1);
    printf("The cost of truck 3 after %0.0f years is $%0.2f.\nNext year's maintenance will be $%0.2f.\n", floor(projectLifespan/2), totalMaintenance3+cost3, maintenance3*1.1);
    if(cost1+totalMaintenance1 < cost2+totalMaintenance2 && cost1+totalMaintenance1 < cost3+totalMaintenance3){
        printf("\nAt $%0.2f, truck 1 is the best investment after %0.0f years.\n", cost1+totalMaintenance1, floor(projectLifespan/2));
    }else if(cost2+totalMaintenance2 < cost1+totalMaintenance1 && cost2+totalMaintenance2 < cost3+totalMaintenance3){
        printf("\nAt $%0.2f, truck 2 is the best investment after %0.0f years.\n", cost2+totalMaintenance2, floor(projectLifespan/2));
    }else{
        printf("\nAt $%0.2f, truck 3 is the best investment after %0.0f years.\n", cost3+totalMaintenance3, floor(projectLifespan/2));
    }
    for(int x = 0; x < projectLifespan - floor(projectLifespan/2); x++){
        maintenance1 *= 1.1;
        maintenance2 *= 1.1;
        maintenance3 *= 1.1;
        totalMaintenance1 += maintenance1;
        totalMaintenance2 += maintenance2;
        totalMaintenance3 += maintenance3;
    }
    printf("\nThe cost of truck 1 after %0.0f years is $%0.2f.\nNext year's maintenance will be $%0.2f.\n", projectLifespan, totalMaintenance1+cost1, maintenance1*1.1);
    printf("The cost of truck 2 after %0.0f years is $%0.2f.\nNext year's maintenance will be $%0.2f.\n", projectLifespan, totalMaintenance2+cost2, maintenance2*1.1);
    printf("The cost of truck 1 after %0.0f years is $%0.2f.\nNext year's maintenance will be $%0.2f.\n", projectLifespan, totalMaintenance3+cost3, maintenance3*1.1);
    if(cost1+totalMaintenance1 < cost2+totalMaintenance2 && cost1+totalMaintenance1 < cost3+totalMaintenance3){
        printf("\nAt $%0.2f, truck 1 is the best investment after %0.0f years.\n", cost1+totalMaintenance1, projectLifespan);
    }else if(cost2+totalMaintenance2 < cost1+totalMaintenance1 && cost2+totalMaintenance2 < cost3+totalMaintenance3){
        printf("\nAt $%0.2f, truck 2 is the best investment after %0.0f years.\n", cost2+totalMaintenance2, projectLifespan);
    }else{
        printf("\nAt $%0.2f, truck 3 is the best investment after %0.0f years.\n", cost3+totalMaintenance3, projectLifespan);
    }
}
