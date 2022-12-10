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
    printf("Enter Maximum Size for queue\n");
    scanf("%d", &maxsize);
}

int isFull()
{
    return (size >= maxsize);
}

int isEmpty()
{
    return (front == NULL && rear == NULL);
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
        printf("Enter The Element you want to Enqueue: ");
        scanf("%d", &element);

        queue *newNode = (queue*)malloc(sizeof(queue));
        newNode->data = element;
        newNode->next = NULL;

        if(front == NULL && rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        printf("%d Node Enqueued\n", element);

        size++;
    }
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue UnderFlow\n");
    }
    else
    {
        queue *temp = front;

        front = front->next;

        printf("%d Node Dequeued\n", temp->data);

        free(temp);

        size--;
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
        queue *ptr = front;

        printf("Queue Elements: ");
        while(ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    MaxSize();

    int choice;

    while (1)
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
            if (isEmpty())
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("Queue is not Empty\n");
            }

            break;

        case 4:

            if (isFull())
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
