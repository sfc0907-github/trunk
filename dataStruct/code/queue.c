#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE;

typedef struct queue
{
    int num;
    NODE* front;
    NODE* rear;
}QUEUE;

QUEUE* init_queue()
{
    QUEUE* pQueue = NULL;
    pQueue = (QUEUE*)malloc(sizeof(QUEUE));
    if(NULL == pQueue)
    {
        printf("malloc error\n");
        return NULL;
    }

    memset(pQueue,0,sizeof(pQueue));
    pQueue->rear = NULL;
    pQueue->front = NULL;
    return pQueue;
}

int get_queue_num(QUEUE* pQueue)
{
    return (NULL == pQueue)?0:pQueue->num;
}

void queue_push(QUEUE* pQueue,int data)
{
    if(NULL == pQueue)
    {
        printf("para is null\n");
        return;
    }

    NODE* pNode = (NODE*)malloc(sizeof(NODE));
    if(NULL == pNode)
    {
        printf("malloc error\n");
        return;
    }
    pNode->data = data;
    pNode->next = NULL;

    if(NULL == pQueue->rear)
    {       
        pQueue->front = pNode;
    }
    else
    {
        pQueue->rear->next = pNode;
    }
    pQueue->num++;
    pQueue->rear = pNode;

    return;
}

void queue_pop(QUEUE* pQueue)
{
    if(NULL == pQueue  || NULL == pQueue->front)
    {
        printf("Queue is empty\n");
        return;
    }

    NODE* pNode = pQueue->front;
    printf("pop data is %d\n",pNode->data);
    pQueue->front = pNode->next;
    if(NULL == pQueue->front)
    {
        pQueue->rear = NULL;
    }
    free(pNode);
    pQueue->num--;

    return;
}


void print_queue_data(QUEUE* pQueue)
{
    if(NULL == pQueue)
    {
        printf("para error\n");
        return;
    }
    
    NODE* pNode = pQueue->front;
    while (NULL != pNode)
    {
        printf("data in queue is %d\n",pNode->data);
        pNode = pNode->next;
    }
    
}

