#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nextNode;
    struct Node *previousNode;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = newNode;
    newNode->previousNode = newNode;

    return newNode;
}

struct Node *push(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *ptr;

    if (head == NULL)
    {
        head = newNode;
        newNode->nextNode = head;
        newNode->previousNode = head;
    }
    else
    {
        ptr = head;

        while (ptr->nextNode != head)
        {
            ptr = ptr->nextNode;
        }

        ptr->nextNode = newNode;
        newNode->previousNode = ptr;
        newNode->nextNode = head;
        head->previousNode = newNode;
    }

    return head;
}

void doublyCircularLinkedListForwardTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->nextNode;
    } while (ptr != head);
}

void doublyCircularLinkedListBackwardTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr->nextNode != head)
    {
        ptr = ptr->nextNode;
    }

    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->previousNode;
    } while (ptr != head);

    printf("Element: %d", ptr->data);
}

struct Node *lastNode(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr->nextNode != head)
    {
        ptr = ptr->nextNode;
    }

    return ptr;
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *last = lastNode(head);

    newNode->nextNode = head;
    head->previousNode = newNode;
    newNode->previousNode = last;
    last->nextNode = newNode;

    head = newNode;

    printf("Insertion at Beginning Done Successfully\n");

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    struct Node *last = lastNode(head);

    last->nextNode = newNode;
    newNode->previousNode = last;
    newNode->nextNode = head;
    head->previousNode = newNode;

    last = newNode;

    printf("Insertion at End Done Successfully\n");

    return head;
}

struct Node *insertAtPosition(struct Node *head, int data, int position, int size)
{
    struct Node *newNode = createNode(data);
    struct Node *ptr = head;

    if (position == 1)
    {
        head = insertAtBeginning(head, data);
    }
    else if (position == size)
    {
        head = insertAtEnd(head, data);
    }
    else
    {
        int count = 1;
        while (count < position - 1 && ptr->nextNode != head)
        {
            ptr = ptr->nextNode;
            count++;
        }

        newNode->nextNode = ptr->nextNode;
        ptr->nextNode->previousNode = newNode;
        newNode->previousNode = ptr;
        ptr->nextNode = newNode;
    }

    return head;
}

struct Node *deletionAtBeginning(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *last = lastNode(head);

    head = head->nextNode;
    head->previousNode = last;
    last->nextNode = head;

    printf("%d has been deleted\n", ptr->data);

    free(ptr);

    return head;
}

struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *last = lastNode(head);
    struct Node *temp = last;

    last = last->previousNode;
    last->nextNode = head;
    head->previousNode = last;

    printf("%d has been deleted\n", temp->data);

    free(temp);

    return head;
}

struct Node *deleteAtPosition(struct Node *head, int position, int size)
{

    struct Node *ptr = head;
    struct Node *temp;

    if (position <= 0 || position > size)
    {
        printf("Wrong Position Entered!");
        return NULL;
    }

    else if (position == 1)
    {
        head = deletionAtBeginning(head);
    }
    else if (position == size)
    {
        head = deletionAtEnd(head);
    }
    else
    {
        int count = 1;
        while (ptr->nextNode != head && count < position - 1)
        {
            ptr = ptr->nextNode;
            count++;
        }
        temp = ptr->nextNode;
        ptr->nextNode = ptr->nextNode->nextNode;
        ptr->nextNode->previousNode = ptr;

        printf("%d has been deleted", temp->data);

        free(temp);
    }
    return head;
}

struct Node *deleteByValue(struct Node *head, int value, int size)
{
    struct Node *ptr = head;

    if (head->data == value)
    {
        head = deletionAtBeginning(head);
    }
    else
    {
        while (ptr->data != value && ptr->nextNode != head)
        {
            ptr = ptr->nextNode;
        }
        if (ptr->data == value)
        {
            ptr->nextNode->previousNode = ptr->previousNode;
            ptr->previousNode->nextNode = ptr->nextNode;

            printf("%d has been deleted", ptr->data);

            free(ptr);
        }
        else
        {
            printf("%d not found\n", value);
        }
    }

    return head;
}

struct Node *deleteEntireList(struct Node *head)
{
    if (head != NULL)
    {
        struct Node *temp, *current;
        current = head->nextNode;

        while (current != head)
        {
            temp = current->nextNode;
            free(current);
            current = temp;
        }

        free(head);

        head = NULL;
    }

    printf("All nodes are deleted successfully.\n");

    return head;
}

struct Node *reversal(struct Node *head)
{
    struct Node *prevNode = head;
    struct Node *tempNode = head;
    struct Node *currentNode = head->nextNode;

    prevNode->nextNode = prevNode;
    prevNode->previousNode = prevNode;

    while (currentNode != head)
    {
        tempNode = currentNode->nextNode;

        currentNode->nextNode = prevNode;
        prevNode->previousNode = currentNode;
        head->nextNode = currentNode;
        currentNode->previousNode = head;

        prevNode = currentNode;
        currentNode = tempNode;
    }

    head = prevNode;

    printf("Reversal Done Successfully!\n");

    return head;
}

struct Node *sort(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *i, *j;

    int temp;

    for (i = ptr; i->nextNode != head; i = i->nextNode)
    {
        for (j = i->nextNode; j != head; j = j->nextNode)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("\n Doubly Circular Linked List Successfully Sorted! \n");

    return head;
}

int totalNodes(struct Node *head)
{
    struct Node *ptr = head;
    int count = 1;
    do
    {
        count++;
        ptr = ptr->nextNode;
    } while (ptr != head);

    return count;
}

void binarySearch(struct Node *head, int value)
{
    int size = totalNodes(head);
    int low = 1;
    int high = size;
    int flag = 0;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        struct Node *ptr = head;
        int count = 1;

        while(ptr->nextNode != head && count < mid)
        {
            ptr = ptr->nextNode;
            count++;
        }

        if(value < ptr->data)
        {
            high = mid - 1;
        }
        else if (value > ptr->data)
        {
            low = mid + 1;
        }
        else
        {
            flag = 1;
            break;
        }   
    }

    if (flag == 1)
    {
        printf("%d found at position %d \n", value, mid);
    }
    else
    {
        printf("%d not found \n", value);
    }
    
}

int main()
{
    int size;
    printf("Enter the size of the Doubly Circular Linked List\n");
    scanf("%d", &size);

    struct Node *head = NULL;

    printf("Enter %d elements in Doubly Circular Linked List\n", size);

    for (int i = 0; i < size; i++)
    {
        int element;
        scanf("%d", &element);
        head = push(head, element);
    }

    int choice;

    while (1)
    {
        printf("\n 1 --> Insertion at Beginning \n");

        printf("\n 2 --> Insertion at End \n");

        printf("\n 3 --> Insertion at given Position \n");

        printf("\n 4 --> Deletion at Beginning \n");

        printf("\n 5 --> Deletion at End \n");

        printf("\n 6 --> Deletion at Specific Position \n");

        printf("\n 7 --> Deletion by Value \n");

        printf("\n 8 --> Delete Entire Doubly Circular Linked List \n");

        printf("\n 9 --> Doubly Circular Linked List Reversal \n");

        printf("\n 10 --> Sorting of Doubly Circular Linked List \n");

        printf("\n 11 --> Binary Search \n");

        printf("\n 12 --> Forward Traversal \n");

        printf("\n 13 --> Backward Traversal \n");

        printf("\n 0 --> Exit from the program \n");

        printf("\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element for Insertion at Beginning\n");
            int beg;
            scanf("%d", &beg);
            head = insertAtBeginning(head, beg);
            size++;

            break;

        case 2:
            printf("Enter element for Insertion at End\n");
            int end;
            scanf("%d", &end);
            head = insertAtEnd(head, end);
            size++;

            break;

        case 3:
            printf("Enter element for Insertion at Given Position\n");
            int value;
            printf("Data: ");
            scanf("%d", &value);
            printf("Enter Position you want to Insert\n");
            int pos;
            printf("Position: ");
            scanf("%d", &pos);

            head = insertAtPosition(head, value, pos, size);
            size++;

            break;

        case 4:
            head = deletionAtBeginning(head);
            size--;

            break;

        case 5:
            head = deletionAtEnd(head);
            size--;

            break;

        case 6:
            printf("Enter The Position you want to delete \n");
            int posDel;
            scanf("%d", &posDel);

            head = deleteAtPosition(head, posDel, size);
            size--;

            break;

        case 7:
            printf("Enter the Node Value you want to delete \n");
            int val;
            scanf("%d", &val);

            head = deleteByValue(head, val, size);
            size--;

            break;

        case 8:
            head = deleteEntireList(head);
            exit(0);

        case 9:
            head = reversal(head);

            break;

        case 10:
            head = sort(head);

            break;

        case 11:
            printf("Enter the element you want to search \n");
            int search;
            scanf("%d", &search);

            binarySearch(head, search);

            break;

        case 12:
            doublyCircularLinkedListForwardTraversal(head);

            break;

        case 13:
            doublyCircularLinkedListBackwardTraversal(head);

            break;

        case 0:
            printf("Exiting From The Program");
            exit(1);
            break;

        default:
            printf("Incorrect Choice\n");
        }
    }

    return 0;
}
