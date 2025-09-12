#include <stdio.h>
#include <stdbool.h>
#include "random.h"

int main(){
    //char buffer[100];
    int low;
    int high;
    bool high_ok = false;
    //bool low_state = false;
    //bool high_state = true;
    int count = 0;
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
}
