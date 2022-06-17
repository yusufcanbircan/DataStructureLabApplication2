//@yusufcanbircan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char inputStr[15];
    char input;
    int array[15][15];
    int lenghtofstring;

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            scanf(" %c", &input);
            array[i][j] = input;
        }
    }
    
    scanf("%s", inputStr);
    lenghtofstring = strlen(inputStr);
    int breakCounter;
    int wayX, wayY;
    int startX, startY;

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            breakCounter = 0;
            if(array[i][j] == (int)inputStr[0]){
                breakCounter++;
                startX = i, startY = j;
                for(int x = -1; x < 2; x++){
                    for(int y = -1; y < 2; y++){
                        if(array[i+x][j+y] == (int)inputStr[1]){
                            breakCounter++;
                            wayX = x, wayY = y;
                            for(int k = 2; k < lenghtofstring; k++){
                                if(array[i+(k*wayX)][j+(k*wayY)] == (int)inputStr[k]){
                                    breakCounter++;
                                }
                            }
                        }
                        if(breakCounter == lenghtofstring){
                            break;
                        }
                        breakCounter = 1;
                    }
                    if(breakCounter == lenghtofstring){
                        break;
                    }
                }
            }
            if(breakCounter == lenghtofstring){
                break;
            }
        }
        if(breakCounter == lenghtofstring){
            break;
        }
    }
    int noControl = 0;
    if(breakCounter != lenghtofstring){
        noControl = 1;
    }

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            array[i][j] = '*';
        }
    }

    if(noControl == 0){
        for(int i = 0; i < lenghtofstring; i++){
            array[startX][startY] = inputStr[i];
            startX += wayX, startY += wayY;
        }
    }
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}