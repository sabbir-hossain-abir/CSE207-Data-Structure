#include <stdio.h>
#include <conio.h>

int main(){
    int secretNumber;
    int guessedNumber;
    int guessLimit=3;
    int guessCount=0;
    int outOfGuesses=0;

    printf("Enter a secret Number: ");
    scanf("%d", &secretNumber);
    
    while (guessedNumber!=secretNumber && outOfGuesses==0)
    {
        if(guessCount<guessLimit){
            printf("Enter a guess: ");
            scanf("%d", &guessedNumber);
            guessCount++;
        }
        else{
            outOfGuesses=1;
        } 
    }
    if (outOfGuesses == 1)
    {
        printf("You are out of guesses");
    }
    else
    {
        printf("You win");
    }
}