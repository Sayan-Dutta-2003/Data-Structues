#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} queue;

queue *front = NULL;
queue *rear = NULL;

int MAXSIZE;
int size = 0;

void maxsize()
{
    printf("Enter the maximum size of the Queue\n");
    scanf("%d", &MAXSIZE);
}

int isFull()
{
    return (size >= MAXSIZE);
}

int isEmpty()
{
    return (front == NULL && rear == NULL);
}

void enqueue()
{
    int element;

    if (isFull())
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        printf("Enter The Element you want to Enqueue: ");
        scanf("%d", &element);

        queue *newNode = (queue *)malloc(sizeof(queue));
        newNode->data = element;
        newNode->next = newNode;

        if (front == NULL && rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }

        printf("%d Node Enqueued\n", element);

        size++;
    }
}

void dequeue()
{
    if (isEmpty() && size == 0)
    {
        printf("Queue UnderFlow\n");
    }
    else if (rear == front)
    {
        int value = front->data;
        printf("%d Node Dequeued\n", front->data);
        free(front);
        front = NULL;
        rear = NULL;
        size = 0;
    }
    else
    {
        queue *temp = front;

        rear->next = front->next;

        front = front->next;

        printf("%d Node Dequeued\n", temp->data);

        free(temp);

        size--;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        queue *ptr = front;

        printf("Queue Elements: ");
        while (ptr != rear)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d", ptr->data);
    }
}

int main()
{
    maxsize();

    int choice;

    while (1)
    {
        printf("\n 1 ---> Enqueue Operation \n");

        printf("\n 2 ---> Dequeue Operation \n");

        printf("\n 3 ---> isEmpty() \n");

        printf("\n 4 ---> isFull() \n");

        printf("\n 5 ---> Display() \n");

        printf("\n 0 --> Exit \n");

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

        case 0:
            exit(0);

        default:

            printf("Incorrect Choice\n");
            break;
        }
    }

    return 0;
}
