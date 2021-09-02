#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __linux__ 
    #include <unistd.h>
    #define clear "clear"
#elif _WIN32
    #include <windows.h>
    #define clear "cls"
#else
    #error "OS not supported!"
#endif

void introduction();

void diceroll(diceface){
    int dicerollmenu;

    system(clear);

    printf("\t%d-sided dice\n", diceface);
    printf("\t-------------\n");

    srand(time(NULL));

    printf("You rolled a %d of %d\n", 1 + rand() % diceface, diceface);
    do{
        printf("\n[1] Try again\n");
        printf("[2] Back to menu\n");
        printf("[0] Exit\n\n");

        printf("Enter: ");
        scanf("%d", &dicerollmenu);
   }while((dicerollmenu > 2) || (dicerollmenu < 0));

    switch (dicerollmenu){
        case 0:
            exit(0);
            break;
        case 1:
            system(clear);
            diceroll(diceface);
            break;
        case 2:
            system(clear);
            introduction();
            break;
        default:
            printf(".");
            break;
    }
    
}

void introduction(){
    int dice;
    
    printf("Choose a type of dice:\n");
    printf("[4] 4 sided dice\n");
    printf("[6] 6 sided dice\n");
    printf("[8] 8 sided dice\n");
    printf("[10] 10 sided dice\n");
    printf("[12] 12 sided dice\n");
    printf("[20] 20 sided dice\n\n");
    printf("[0] Exit\n\n");

    printf("Enter: ");
    scanf("%d", &dice);

    switch (dice){
        case 0:
            exit(0);
            break;
        case 4:
            diceroll(4);
            break;
        case 6:
            diceroll(6);
            break;
        case 8:
            diceroll(8);
            break;
        case 10:
            diceroll(10);
            break;
        case 12:
            diceroll(12);
            break;
        case 20:
            diceroll(20);
            break;
        default:
            system(clear);
            printf("Choose again...\n\n");
            introduction();
            break;
    }
}

int main(){
    introduction();
    return 0;
}