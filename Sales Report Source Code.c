#include <stdio.h>
//defines the funtion for the sales report
void salesreport(float *money) {
    char months[12][20] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("\nMonthly Sales Report for 2022:\n\n");
    printf("%-10s %s\n\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        printf("%-10s $%.2f\n",months[i], money[i]);
    }
}
//defines the function for the sales summary
void salessummary(float *money) {
    char months[12][20] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("\nSales Summary:\n\n");
    float total = 0, min = 0, max = 0;
    int minmonth, maxmonth;
    for (int i = 0; i < 12; i++){
        if (i == 0) min = money[i];
        total += money[i];
        if (money[i] < min) {min = money[i]; minmonth = i;}
        if (money[i] > max) {max = money[i]; maxmonth = i;}
    }
    printf("%-15s %-10.2f (%s)\n", "Minimum Sales:", min, months[minmonth]);
    printf("%-15s %-10.2f (%s)\n", "Maximum Sales:", max, months[maxmonth]);
    printf("%-15s %.2f\n", "Average Sales:", total/12);
}
//defines the function for the moving average
void movingavg(float *money) {
    char months[12][20] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float avg, total = 0;
    printf("\nSix Month Moving Average Report:\n\n");
    for (int i = 0; i + 6 < 12; i++) {
        total = 0;
        for (int j = i; j < i + 6; j++) {
            total += money[j];
        }
        avg = total/6;
        printf("%-10s -    %-10s %.2f\n", months[i],months[i+6], avg);
    }
}
//defines the function for the highest to lowest months
void hightolow(float *money) {
    char months[12][20] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int used[12] = {0};
    printf("\nSales Report (Highest to Lowest)\n\n");
    printf(" Month      Sales\n\n");
    for (int i = 0; i < 12; i++) {
        float max = -1.0;
        int maxindex = -1;
        for (int j = 0; j < 12; j++) {
            if (money[j] > max && !used[j]) {
                max = money[j];
                maxindex = j;
            }
        }
        if (maxindex != -1) {
            printf("%-10s $%.2f\n", months[maxindex], max);
            used[maxindex] = 1;
        }
    }
}
//defines the main function
int main (){
    char filename[50];
    FILE *inputfile;
    float nums[12]; 
    int count = 0;
    char months[12][20] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Enter the name of the input file: ");
    scanf("%s", filename);
    inputfile = fopen(filename, "r");
    while (count < 12 && fscanf(inputfile, "%f\n", &nums[count]) == 1){
        count++;
    }
    fclose(inputfile);
    salesreport(nums);
    salessummary(nums);
    movingavg(nums);
    hightolow(nums);
    return 0;
}