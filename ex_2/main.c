#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "random.h"
//#include <string.h>
//#include <stdio.h>

int main(int argc, char *argv[]){
    //char buffer[100];
    int low;
    int high;
    //bool high_ok = false;
    //bool low_state = false;
    //bool high_state = true;
    int count;
    //bool valid_input = false;

    if (argc == 4) {
        // Command-line arguments provided
        //char low_char[100];
        //char high_char[100];
        //char count_char[100];
        if(check_last_three_args(argc, argv)){
            printf("Error! last three arguments must be numbers and positive\n");
            return 1;

        }
        low = atoi(argv[1]);
        high = atoi(argv[2]);
        count = atoi(argv[3]);
        if(low<0 || high<0 || count <0){
            printf("Error! Should be a positive number \n");
            return 1;
        }
        if (low >= high) {
            printf("Error! High should be greateerr than low.\n");
            return 1;
        }

        if (count > (high - low + 1)) {
            printf("Error! Count cannot exceed range size.\n");
            return 1;
        }
        printf("Generating %d unique random numbers between %d and %d:\n", count, low, high);
        random_num(low, high, count);
    } else if(argc == 1){
        // No command-line arguments, prompt user
        printf("Enter the range that you wish to get random numbers\n");

        printf("Enter low: ");
        low = input();

        do {
            printf("Enter high: ");
            high = input();
            if (high < low) {
                printf("High must be greater than low.\n");
            } 
        }while(high<=low);

        int range_size = high - low + 1;

        do {
            printf("Enter how many unique random numbers you want: ");
            count = input();
            if (count > range_size) {
                printf("Error: Count cannot exceed range size.\n");
            }
        } while (count > range_size);
        printf("Generating %d unique random numbers between %d and %d:\n", count, low, high);
        random_num(low, high, count);
    }

    return 0;

    /*
    printf("Enter the range that you wish to get the random no\n");
    printf("Enter the range low: ");
    low = input();
    do{
        if(count==0){
            printf("Enter the range high: ");
        }else{
            printf("Enter high again: ");    
        }
        high = input();
        if(high<low){
            high_ok = false;
        }else{
            high_ok = true;
        }
        count++;
    }while(!high_ok);

    printf("Low: %d High: %d\n", low, high);
    random_num(low, high);
    return 0;
    */
}
