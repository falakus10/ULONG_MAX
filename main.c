#include <stdio.h>
#include <limits.h>

int is_answer_moreThan_ulongmax(unsigned short int number);



unsigned long long int factorialCalculation(unsigned short int number);

int main() {
    printf("%d", USHRT_MAX);
    for (int i=0; i < USHRT_MAX; ++i){
        if(is_answer_moreThan_ulongmax(i)){
            break;
        }else{
            printf("%hu! = %llu\n",i, factorialCalculation(i));
        }
    }
}
unsigned long long int factorialCalculation(unsigned short int number){
    if (number==0 || number ==1)
        return 1;
    return (number * factorialCalculation(number - 1));
}

// Function that looks for is answer bigger than ulong max
//ULLONG_MAX = 184467440737095511615
int is_answer_moreThan_ulongmax(unsigned short int number){
    unsigned long long int answer = 1;
    for(unsigned short int i = 1; i < number ; ++i){
        if(ULLONG_MAX / i < answer){
            return 1; // if answer is bigger than ulong max
        }
        else {
            answer*=i; // if answer is not bigger than ulong max

        }
    }
    return 0;
}