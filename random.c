#include <stdio.h>
#include "random.h"
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void random_num(int low, int high){
    srand(time(NULL));
    int length = high-low + 1;
    int numbers[length];
    for(int i=0; i<length;i++){
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
    for(int j=0; j<length; j++){
        printf("%d ", numbers[j]);
    }
    printf("\n");
}

int input(){
    char buffer[100];
    int num;
    //bool negative_no = false;
    //int count = 0;
    //bool input_is_charactor = false;
    bool invalid_input = false;
    //bool input_is_valid_no = false;
    //bool num_state = false;
    //printf("Enter the range that you wish to get the random no\n");
    do{
        if (invalid_input){
            printf("Enter valid no: ");
        }
        //printf("Enter the range: ");
        if(fgets(buffer, sizeof(buffer), stdin) != NULL){
            if (sscanf(buffer, "%d", &num) == 1){
                invalid_input = false;
                if(num<0){
                    printf("You entered negative no\n");
                    invalid_input = true;
                    //negative_no = true;
                }
            }
            else{
                invalid_input = true;
            }
        }
    }while(invalid_input);
    return num;
}
