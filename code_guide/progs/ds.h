#ifndef _DS_TOOL_H_
#define _DS_TOOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

/*********** queue ****************/
typedef struct deque_node {
    long val;
    struct deque_node *next;
    struct deque_node *prev;
} deque_node;
typedef struct queue {
    int size;
    deque_node *header;
    deque_node *tailer;
} queue;

deque_node *deque_node_create(long val);
queue *queue_create(void);
int queue_empty(queue *q);
void queue_enqueue(queue *q, long val);
long queue_dequeue(queue *q);
void queue_print(queue *q);
/*********************************/

/*********** stack ****************/
typedef struct stknode {
    long val;
    struct stknode *next;
} stknode;
typedef struct stack {
    long size;
    stknode *top;
} stack;

stknode *stknode_create(long val);
stack *stack_create(void);
void stack_push(stack *s, long val);
int stack_empty(stack *s);
long stack_pop(stack *s);
long stack_peek(stack *s);
void stack_print(stack *s);
/**********************************/

void sort(int *arr, int size);
int is_sorted(int *arr, int size);
void swap(int *a, int *b);
long getCurTime(void);
void parseArray(int *arr, int *len, char *str);
int randWithRange(int lo, int hi);
void printArray(int *array, int size);
int *copyArray(int *arr, int size);
int *array(int size);
int *arrayWithRange(int size, int lo, int hi);
int *arrayWithSize(int size);


#endif