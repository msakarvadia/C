#include <stdio.h>
#include <math.h>

int main(void){
    double principle = 1000, rate = .05;
    printf("%4s %21s\n", "year", "amount on deposit");
    for (unsigned char year =1; year <=10; ++year){
        double amount = principle*pow(1+rate,year);
        if(year%2 ==0)
            continue;
        printf("%4u%21.2f\n", year, amount);
    }
    return 0;
}
