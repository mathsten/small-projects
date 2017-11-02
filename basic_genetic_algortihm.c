//
//  main.c
//  Generisk algoritme
//
//  Created by Mathias Stensrud on 25.10.2016.
//  Copyright © 2016 Mathias Stensrud. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sorter();

int main(int argc, const char * argv[]) {

//Lage målet som skal finnes
    int goal[6] = {3,5,7,9,1};
    printf("Vi skal finne dette tallet: ");

    for(int i = 0; i < 5; i++){
        printf("%d", goal[i]);
    }

    printf("\nTrykk en knapp for å fortsette");
    getchar();

//Lage utgangspunkt-forslag
    int forslag[4][5];
    srand((unsigned int)time(NULL));
    printf("\n4 random løsningsforslag:\n");
    for(int a = 0; a < 4; a++)
    {
        for(int b = 0; b < 5; b++)
        {
            forslag[a][b] = rand() % 9;
            printf("%d", forslag[a][b]);
        }
        printf("\n");
    }

//Opprette fitness array
    int fitness[4][7] = {
        {0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0},
        {2,0,0,0,0,0,0},
        {3,0,0,0,0,0,0}
    };

    //Evaluer fitness
    for(int c = 0; c < 4; c++){
        for(int d = 0; d < 5; d++)
        {
            if(forslag[c][d] == goal[d]){
                fitness[c][d+1] = 1;
            }
            else if(forslag[c][d] != goal[d]){
                fitness[c][d+1] = 0;
            }
        }
    }

while(1){
//Evaluerer, parre og mutere til løsning er funnet


    //printe fitness array
    printf("\nSortert fitness \n");
    for(int g = 0; g < 4; g++){
        for(int h = 0; h < 6; h++){
            printf("%d", fitness[g][h]);
        }
        printf("\n");
    }

    printf("\n");

    //Seleksjon, dvs, forkaste dårligste
    //Pluss sammen fitness
    for(int e = 0; e < 4; e++){
        fitness[e][6] = fitness[e][1] + fitness[e][2] + fitness[e][3] + fitness[e][4] + fitness[e][5];
        printf("karakter forslag %d: %d\n",(e) ,fitness[e][6]);
    }

    int temp[7];

    //Sorter fitness
    for(int f = 0; f < 4-1; f++){
        if(fitness[f][6] > fitness[f+1][6]){
            for(int g = 0; g < 7; g++){
                temp[g] = fitness[f][g];
            }
            for(int h = 0; h < 7; h++){
                fitness[f][h] = fitness[f+1][h];
            }
            for(int i = 0; i< 7; i++){
                fitness[f+1][i] = temp[i];
            }
        }
    }

    //printe sortert fitness array
    printf("\nSortert fitness array\n");
    for(int g = 0; g < 4; g++){
        for(int h = 0; h < 6; h++){
            printf("%d", fitness[g][h]);
        }
        printf("\n");
    }

    //Parre
    int dele = (rand() % 3) + 1;
    printf("\nTilfeldig deling %d\n", dele);

    for(int i = 0; i < dele; i++){
        forslag[fitness[0][0]][i] = forslag[fitness[2][0]][i];
    }

    for(int j = dele; j < 5; j++){
        forslag[fitness[0][0]][j] = forslag[fitness[3][0]][j];
    }

    //Parrede forslag
    printf("\nParrede forslag array\n");
    for(int g = 0; g < 4; g++){
        for(int h = 0; h < 5; h++){
            printf("%d", forslag[g][h]);
        }
        printf("\n");
    }

    //Evaluer fitness igjen
    for(int c = 0; c < 4; c++){
        for(int d = 0; d < 5; d++)
        {
            if(forslag[c][d] == goal[d]){
                fitness[c][d+1] = 1;
            }
            else if(forslag[c][d] != goal[d]){
                fitness[c][d+1] = 0;
            }
        }
    }

    //printe sortert fitness array
    printf("\nSortert fitness array\n");
    for(int g = 0; g < 4; g++){
        for(int h = 0; h < 6; h++){
            printf("%d", fitness[g][h]);
        }
        printf("\n");
    }

    //Mutere
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 6; j++)
        {
            if(fitness[i][j] == 0){
                forslag[fitness[i][0]][j-1] = rand() % 10;
            }
            else if(fitness[i][j] == 1){

            }
        }
    }

    //Muterte forslag
    printf("\nMuterte forslag\n");
    for(int g = 0; g < 4; g++){
        for(int h = 0; h < 5; h++){
            printf("%d", forslag[g][h]);
        }
        printf("\n");
    }

    printf("\nTrykk for å starte neste runde");
    getchar();

    }
    return 0;
}
