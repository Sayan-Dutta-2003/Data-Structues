#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} queue;

queue *front = NULL;
queue *rear = NULL;

int size = 0;
int maxsize;

void MaxSize()
{
    printf("Enter Maximum Size for Deque\n");
    scanf("%d", &maxsize);
}

void addRear(int data)
{
    if (size == maxsize)
    {
        printf("DEque is full");
    }
    else
    {
        queue *newNode = (queue *)malloc(sizeof(queue));
        newNode->data = data;
        newNode->next = NULL;
        if (front == NULL && rear == NULL)
        {
            size++;
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            size++;
        }
    }
    printf("%d element Enqueued from Rear\n", data);
}

void addFront(int data)
{
    if (size == maxsize)
    {
        printf("Deque is Full");
    }
    else
    {
        if (front == NULL && rear == NULL)
        {
            addRear(data);
        }
        else
        {
            queue *newNode = (queue *)malloc(sizeof(queue));
            newNode->data = data;
            newNode->next = front;
            front = newNode;
            size++;
        }
    }
    printf("%d element Enqueued from Front\n", data);
}

void deleteFront()
{
    if (front == NULL && rear == NULL)
    {
        printf("DEque is Empty");
    }
    else if (front == rear)
    {
        printf("%d element dequeued from Front\n", front->data);
        free(front);
        front = NULL;
        rear = NULL;
        size--;
    }
    else
    {
        printf("%d element dequeued from Front\n", front->data);
        queue *del = front;
        front = front->next;
        free(del);
        size--;
    }
}

void deleteRear()
{
    if ((!front) && (!rear))
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("%d element dequeued from Rear\n", rear->data);
        free(rear);
        rear = NULL;
        front = NULL;
        --size;
    }
    else
    {
        printf("%d element dequeued from Rear\n", rear->data);
        queue *currentRear = rear;
        queue *currentFront = front;
        while (currentFront->next != currentRear)
        {
            currentFront = currentFront->next;
        }
        currentFront->next = NULL;
        rear = currentFront;
        free(currentRear);
        --size;
    }
}

int main()
{
    MaxSize();

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
