#include<stdio.h>
#include<stdlib.h>

int *queue;
int front = -1, rear = -1;
int size;

int isFull()
{
    return (rear == size - 1);
}

int isEmpty()
{
    return ((front == -1 && rear == -1) || front > rear);
}

void enqueue()
{
    int element;
    
    if(isFull())
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if(front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = rear + 1;
        }

        printf("Enter The Element you want to Enqueue: ");
        scanf("%d", &element);

        queue[rear] = element;

        printf("%d element Enqueued\n", element);
    }
    
}

void dequeue()
{
    int del; 

    if(isEmpty())
    {
        printf("Queue UnderFlow\n");
    }
    else
    {
        del = queue[front++];
        printf("%d is dequeued\n", del);
    }
    
}

void display()
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue ELements: ");
        for(int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
    printf("\n");
    
}

int main(){
    
    printf("Enter The size of the Queue: ");
    scanf("%d", &size);

    queue = (int*)malloc(sizeof(int) * size);

    int choice;

    while(1)
    {
        printf("\n 1 ---> Enqueue Operation \n");

        printf("\n 2 ---> Dequeue Operation \n");

        printf("\n 3 ---> isEmpty() \n");

        printf("\n 4 ---> isFull() \n");

        printf("\n 5 ---> Display() \n");

        printf("\n 6 --> Exit \n");

        printf("\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        
        case 2:
            dequeue();
            break;
        
        case 3:
            if(isEmpty())
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("Queue is not Empty\n");
            }

            break;

        case 4:

            if(isFull())
            {
                printf("Queue is Full\n");
            }
            else
            {
                printf("Queue is not Full\n");
            }

            break;
            
        case 5:
            display();

            break;

        case 6:
            exit(0);
            
        default:

            printf("Incorrect Choice\n");
            break;
        }
    }

    return 0;
}
