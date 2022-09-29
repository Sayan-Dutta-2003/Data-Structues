#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} myStack;

myStack *top = NULL;

void displayStack(myStack *top)
{
    while (top != NULL)
    {
        printf("Element: %d\n", top->data);

        top = top->next;
    }
}

int size = 0;

int maxSize;

void MaxSize()
{
    printf("Enter Maximum Size for Stack\n");
    scanf("%d", &maxSize);
}

void push(int data)
{
    if (size < maxSize)
    {
        myStack *newNode = (myStack *)malloc(sizeof(myStack));
        newNode->data = data;

        if (top == NULL)
        {
            newNode->next = NULL;
            top = newNode;
            size++;
        }
        else
        {
            newNode->next = top;
            top = newNode;
            size++;
        }
    }
    else
    {
        printf("Stack OverFlow! Cannot push to the stack.\n");
    }
}

void pop()
{
    myStack *topStack = top;
    if (top == NULL)
    {
        printf("Stack UnderFlow! Cannot pop from the stack.\n");
    }
    else
    {
        top = top->next;
        printf("Popped Element: %d\n", topStack->data);
        free(topStack);
        size--;
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Top Element: %d", top->data);
    }
}


int main()
{
    int choice;
    
    MaxSize();

    while (1)
    {

        printf("\n 1 --> Push() element in the Stack \n");

        printf("\n 2 --> Pop() Element from the Stack \n");

        printf("\n 3 --> Peek() element from the stack \n");

        printf("\n 4 --> Display() \n");

        printf("\n 5 --> Exit From the Program \n");

        printf("\n");

        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Enter data to push ");
            int data;
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();

            break;

        case 4:
            displayStack(top);

            break;

        case 5:
            exit(0);

        default:
            printf("Incorrect Choice");
            
            break;
        }
    }

    return 0;
}
