#include <stdio.h>
#include <stdlib.h>

#define SIZE 12  // Number of months

// Function to display the monthly sales
void displayMonthlySales(float sales[], const char *months[]) {
    printf("%-12s %10s\n", "Month", "Sales");
    printf("-------------------------\n");
    for (int i = 0; i < SIZE; i++) { //loops through all of the values in the file
        printf("%-12s %10.2f\n", months[i], sales[i]); 
    }
}

// Function to display the sales summary (min, max, and average sales)
void displaySalesSummary(float sales[]) {
    float min = sales[0], max = sales[0], sum = 0;
    for (int i = 0; i < SIZE; i++) { //loops through all of the sales
        if (sales[i] < min) min = sales[i]; //updates the min value by comparing to the previous one
        if (sales[i] > max) max = sales[i]; //updates the max value
        sum += sales[i]; //adds all the values together
    }
    printf("Minimum Sales: %.2f\n", min);
    printf("Maximum Sales: %.2f\n", max);
    printf("Average Sales: %.2f\n", sum / SIZE);
}

// Function to display the six-month moving average
void displaySixMonthMovingAverage(float sales[]) {
    for (int i = 0; i <= SIZE - 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) { //lloks at a particular month, and goes through the next 6
            sum += sales[j]; //adds the sales for 6 months together
        }
        printf("Months %d - %d: %.2f\n", i + 1, i + 6, sum / 6);
    }
}

// Function to display the sales sorted from highest to lowest
void displaySalesSorted(float sales[]) {
    float sortedSales[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sortedSales[i] = sales[i]; //coppies the list
    }
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (sortedSales[j] < sortedSales[j + 1]) {
                float temp = sortedSales[j]; //if the left pointer is less than the right they swap places in the list
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = temp;
            }
        }
    }
    printf("%-12s\n", "Sales");
    printf("------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%10.2f\n", sortedSales[i]);
    }
}

int main() {
    const char *months[SIZE] = { 
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December" 
    };
    float sales[SIZE];
    char filename[100];

    printf("Enter the filename containing the sales data: ");
    scanf("%99s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open %s\n", filename);
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        if (fscanf(file, "%f", &sales[i]) != 1) {
            printf("Error: Invalid data in file\n");
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    printf("\n1. Monthly Sales Report:\n");
    displayMonthlySales(sales, months);

    printf("\n2. Sales Summary Report:\n");
    displaySalesSummary(sales);

    printf("\n3. Six-Month Moving Average Report:\n");
    displaySixMonthMovingAverage(sales);

    printf("\n4. Sales Report (Highest to Lowest):\n");
    displaySalesSorted(sales);

    return 0;
}