//Cat 2
/* Name: Gilberto Amimo Otieno
Course: Bachelor Of Computer Science 
Reg no: CT101/G/26584/25
Description: This program calculates and displays an employee’s gross pay, taxes, and net pay based on the number of hours worked in a week and the hourly wage entered by the user.
*/

#include <stdio.h>

int main() {
    float hours, wage;
    float gross_pay, taxes, net_pay;
    
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);
    
    printf("Enter hourly wage: ");
    scanf("%f", &wage);
    
    // Calculate gross pay
    if (hours > 40)
        gross_pay = (40 * wage) + ((hours - 40) * wage * 1.5);
    else
        gross_pay = hours * wage;
    
    // Calculate taxes
    if (gross_pay <= 600)
        taxes = gross_pay * 0.15;
    else
        taxes = (600 * 0.15) + ((gross_pay - 600) * 0.20);
    
    // Calculate net pay
    net_pay = gross_pay - taxes;
    
    // Display results
    printf("\nGross pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net pay: $%.2f\n", net_pay);
    
    return 0;
}