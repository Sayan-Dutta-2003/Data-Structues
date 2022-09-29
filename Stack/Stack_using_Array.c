#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int stack[MAXSIZE], top = -1;

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == MAXSIZE - 1);
}

void push(int data)
{
    if (isFull())
    {
        printf("\nStack overflow\n");
    }
    else
    {
        stack[++top] = data;
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("\nStack underflow\n");
        return -1;
    }
    else
    {
        int data = stack[top--];

        return data;
    }
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("Element: %d\n", stack[i]);
        }
    }
}

int main()
{
    
    int choice;

    while (1)
    {
        printf("\n 1 --> Push() \n");

        printf("\n 2 --> Pop() \n");

        printf("\n 3 --> Peek() \n");

        printf("\n 4 --> isFull() \n");

        printf("\n 5 --> isEmpty() \n");

        printf("\n 6 --> Display() \n");

        printf("\n 0 --> Exit from the program \n");

        printf("\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter any element to push :: ");
            int n;
            scanf("%d", &n);
            push(n);

            break;

        case 2:
            printf("Popped Data is %d", pop());

            break;

        case 3:
            if (peek() != -1)
            {
                printf("Peeked Data is %d", peek());
            }

            break;

        case 4:
            if (isFull())
            {
                printf("\nStack is Full\n");
            }
            else
            {
                printf("Stack is not Full\n");
            }

            break;

        case 5:
            if (isEmpty())
            {
                printf("\nStack is Empty\n");
            }
            else
            {
                printf("Stack is not Empty\n");
            }

            break;

        case 6:
            display();

            break;
        
        case 0:
            printf("Exit from the Program\n");
            exit(0);

        default:
            printf("Incorrect Choice\n");
            break;
        }
    }

    return 0;
}
