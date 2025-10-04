#include <string.h>
#include <stdio.h>
#include "random.h"
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

void random_num(int low, int high, int count){
    srand(time(NULL));
    int length = high-low + 1;
    int numbers[length];
    for(int i=0; i<count;i++){
        if(i==0){
            int r = rand()%(length) + low;
            numbers[i] = r;
        }
        //int r = rand()%(high -low+1) +low;
        //numbers[i]= r;
        int temp_r;
        bool unique;
        do{
            unique =true;
            temp_r = rand()%(length) +low;
            for(int j =0; j<i; j++){
                if(numbers[j] == temp_r){
                    unique = false;
                    break;
                }
            }
        }while(!unique);
        numbers[i] = temp_r;
    }
    for(int j=0; j<count; j++){
        printf("%d ", numbers[j]);
    }
    printf("\n");
}

int check_last_three_args(int argc, char *argv[]) {
    if (argc < 4) return 0; // not enough arguments to check

    for (int i = argc - 3; i < argc; i++) {
        char *arg = argv[i];
        for (int j = 0; arg[j] != '\0'; j++) {
            if (!isdigit(arg[j])) {
                return 1; // found a non-digit character
            }
        }
    }
    return 0; // all three args are numeric
}

int input(){
    char buffer[100];
    int num;
    //bool negative_no = false;
    //int count = 0;
    //bool input_is_charactor = false;
    
    bool invalid_input = true;
    //bool input_is_valid_no = false;
    //bool num_state = false;
    //printf("Enter the range that you wish to get the random no\n");
    do{
        if(fgets(buffer, sizeof(buffer), stdin) != NULL){
            //buffer[strcspn(buffer, "\n")] = 0;
            //buffer[strcspn(buffer, "\n")] = 0;
            if (sscanf(buffer, "%d", &num) == 1){
                invalid_input = false;
                if(num<0){
                    printf("Enter a positive no. Enter again: ");
                    invalid_input = true;
                }
                //printf("Invalid input. Enter a number: \n");
            }else{
                printf("Invalid input. Enter again: ");
                invalid_input = true;
            }
        }else{
            printf("Invalid input. Enter again: ");
            invalid_input = true;
        }
    }while(invalid_input);
    return num;
}
