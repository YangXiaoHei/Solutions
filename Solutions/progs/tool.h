#ifndef _ARRAY_TOOL_H_
#define _ARRAY_TOOL_H_

#define ___ printf("\n");

void parseArray(int *arr, int *len, char *str);
int *arrayWithSize(int size);
int *arrayWithRange(int size, int lo, int hi);
void printArray(int *array, int size);
int randWithRange(int lo, int hi);

#endif
