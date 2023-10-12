#include <stdio.h>
//defines the main function
int main() {
    int target;
    int go = 1;
    while (go == 1) {
        printf("Enter 1 or 0 to STOP\nEnter the NFL score: ");
        scanf("%d", &target);
        int scoringplays = 0;
        if (target == 0 || target == 1) {go = 0;}
        else {
            printf("Possible combinations of scoring plays:\n");
            for (int num2 = 0; num2 <= target/2; num2++){
                for (int num3 = 0; num3 <= target/3; num3++){
                    for (int num6 = 0; num6 <= target/6; num6++){
                        for (int num7 = 0; num7 <= target/7; num7++){
                            for (int num8 = 0; num8 <= target/8; num8++){
                                int sum = num2*2 + num3*3 + num6*6 + num7+7 +num8*8;
                                if (sum == target) {
                                    printf("%d TD + 2pt,", num8);
                                    printf("%d TD + FG,", num7);
                                    printf("%d TD,", num6);
                                    printf("%d FG,", num3);
                                    printf("%d Saftey\n", num2);
                                    scoringplays++;
                                }
                            }
                        }
                    }
                }
            }
            if (scoringplays == 0){
                printf("No possible combinations found.\n");
            }    
        }
    }
    return 0;
}