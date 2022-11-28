#include<stdio.h>
#include<stdlib.h>

int *queue;
int front = -1, rear = -1;
int size;

void addFront(int data)
{
    if((rear + 1) % size == front)
    {
        printf("Deque is full");3
    }
    else if(front == -1 && rear == -1)
    {
        queue[++front] = data;
        rear = front;
    }
    else
    {
        if(front = 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        queue[front] = data;
    }
    printf("%d element Enqueued from Front\n", data);
}

void deleteFront()
{
    int del = queue[front];
    if(front == -1 && rear == -1)
    {
        printf("Deque is Empty");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    printf("%d element dequeued from Front\n", del);

}

void addRear(int data)
{
    if((rear + 1) % size  == front)
    {
        printf("Deque is Full");
    }
    else if(front == -1 && rear == -1)
    {
        queue[++rear] = data;
        front = rear;
    }
    else
    {
        rear = (rear + 1) % size;
        queue[rear] = data;
    }

    printf("%d element Enqueued from Rear\n", data);
}

void deleteRear()
{
    int del = queue[rear];
    if(front == -1 && rear == -1)
    {
        printf("Deque is Empty");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if(rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }
    printf("%d element dequeued from Rear\n", del);
}

int main(){

    printf("Enter The size of the Queue: ");
    scanf("%d", &size);

    queue = (int *)malloc(sizeof(int) * size);

    int choice, data;

    while (1)
    {
        printf("\n 1 ---> Enqueue Operation at Front\n");

        printf("\n 2 ---> Dequeue Operation at Front\n");

        printf("\n 3 ---> Enqueue Operation at Rear\n");

        printf("\n 4 ---> Dequeue Operation at Rear\n");

        printf("\n 0 --> Exit \n");

        printf("\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data you want to Enqueue at front: ");
            scanf("%d", &data);
            addFront(data);
            break;

        case 2:
            deleteFront();
            break;

        case 3:
            printf("Enter the data you want to Enqueue at rear: ");
            scanf("%d", &data);
            addRear(data);
            break;

        case 4:
            deleteRear();
            break;
        
        case 0:
            exit(0);

        default:

            printf("Incorrect Choice\n");
            break;
        }
    }

    return 0;
}
