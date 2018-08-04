//
// Created by agnie on 8/4/2018.
//

#ifndef LITHHOMEWORK_FILEANALYSER_H
#define LITHHOMEWORK_FILEANALYSER_H

FILE *filePath;
char *fileName;
int cursor;
int charCount;
int *charTable[128];

void setFilePath();
void readFile();
void analyseFile();
int findMax(int *array[], int rangeStart, int rangeEnd);
int findGreater(int x, int y);
#endif //LITHHOMEWORK_FILEANALYSER_H
