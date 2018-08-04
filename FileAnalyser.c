//
// Created by agnie on 8/4/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include "FileAnalyser.h"

void setFilePath(){
    fileName = "D:\\Fabryka\\Xera.txt";
}

void fillCharTable(){
    for (int i = 0; i<128; i++){
        charTable[i] = 0;
    }
}

void readFile() {
    charCount = 0;
    filePath = fopen(fileName, "r");
    if (filePath == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    fillCharTable();
    while((cursor = fgetc(filePath)) != EOF){
//        printf("%c", cursor);
        charTable[cursor]++;
        charCount++;
    }
    fclose(filePath);
    printf("\n");
    printf("The file contains ");
    printf("%d",charCount);
    printf(" characters.");
    printf("\n");
}

void analyseFile() {
    setFilePath();
    readFile();
    int maxUpperIndex = findMax(charTable, 65, 91);
    printf("Most common capital character: ");
    printf("%c", maxUpperIndex);
    printf("\n");
    int maxLowerIndex = findMax(charTable, 97, 123);
    printf("Most common lowercase character: ");
    printf("%c", maxLowerIndex);
    printf("\n");
    int greater = findGreater(maxUpperIndex, maxLowerIndex);
    printf("Most common overall character: ");
    printf("%c", greater);

}

int findMax(int *array[], int rangeStart, int rangeEnd){
    int *max = 0;
    int maxPosition = 0;
    for (int i=rangeStart; i<rangeEnd; i++){
        if (array[i] > max){
            max = array[i];
            maxPosition = i;
        }
    }
    return maxPosition;
}

int findGreater(int x, int y){
    int greater = x;
    if (charTable[y] > charTable[x]){
        greater = y;
    }
    return greater;
}

