#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
};

// Printing the elements of the Linked List
void traversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Creating Node of the Linked List
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Inserting Node in the Linked List
struct Node *insertNode(struct Node *head, int data)
{
    struct Node *node = createNode(data);

    if (head == NULL)
    {
        head = node;
    }

    else
    {
        struct Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = node;
    }

    return head;
}

// Insert Node at the beginning of the Linked List
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;

    return head;
}

// Insert Node at the end of the Linked List
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->next = NULL;

    return head;
}

// Insert node at a given Index of the Linkde List
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *newNode = createNode(data);
    struct Node *ptr = head;

    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;

    return head;
}

struct Node *deleteAtBeginning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *ptr = head->next;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    p->next = NULL;

    free(ptr);

    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *ptr = head->next;

    for (int i = 0; i < index - 1, ptr->next != NULL; i++)
    {
        p = p->next;
        ptr = ptr->next;
    }

    p->next = ptr->next;
    free(ptr);

    return head;
}

struct Node *deleteByValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *givenValue = head->next;

    while (givenValue->data != value && givenValue->next != NULL)
    {
        p = p->next;
        givenValue = givenValue->next;
    }

    if (givenValue->data == value)
    {
        p->next = givenValue->next;
        free(givenValue);
    }

    return head;
}

void deleteEntireLinkedList(struct Node *head)
{

    while (head != NULL)
    {
        head = deleteAtBeginning(head);
        // head = head->next;
    }
    if (head == NULL)
        printf("Entire Linked List has been Deleted, no need for traversal!\n");
}


struct Node *swapNodes(struct Node *first, struct Node *second)
{
    struct Node *temp = second->next;
    second->next = first;
    first->next = temp;

    return second;
}

int bubbleSort(struct Node **head, int size)
{
    struct Node **ptr;
    int swapped;

    for (int i = 0; i <= size; i++)
    {
        ptr = head;
        swapped = 0;

        for (int j = 0; j < size - i - 1; j++)
        {
            struct Node *p1 = *ptr;
            struct Node *p2 = p1->next;

            if (p1->data > p2->data)
            {
                *ptr = swapNodes(p1, p2);
                swapped = 1;
            }

            ptr = &(*ptr)->next;
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

struct Node *linkedListReversal(struct Node *head)
{
    struct Node *newHead = NULL;

    while(head != NULL)
    {
        struct Node *nextNode = head->next;
        head->next = newHead;
        newHead = head;
        head = nextNode;
    }

    return newHead;
}

int totalNodes(struct Node *head)
{
    int count = 1;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void binarySearch(struct Node *head, int element)
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
        while (ptr != NULL && count < mid)
        {
            ptr = ptr->next;
            count++;
        }

        if (element < ptr->data)
        {
            high = mid - 1;
        }
        else if (element > ptr->data)
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
        printf("%d found at position %d \n", element, mid);
    }
    else
    {
        printf("%d not found \n", element);
    }
}

int main()
{
    int size;
    printf("Enter the size of the Linked List\n");
    scanf("%d", &size);

    // User Input
    struct Node *head = NULL;
    printf("Enter %d elements in the linked list\n", size);
    for (int i = 0; i < size; i++)
    {
        int element;
        scanf("%d", &element);
        head = insertNode(head, element);
    }

    int choice;
    while (1)
    {
        printf("\n 1 --> Insertion at Beginning \n");

        printf("\n 2 --> Insertion at End \n");

        printf("\n 3 --> Insertion at given Position \n");

        printf("\n 4 --> Deletion at Beginning \n");

        printf("\n 5 --> Deletion at End \n");

        printf("\n 6 --> Deletion at given Index \n");

        printf("\n 7 --> Deletion by Value \n");

        printf("\n 8 --> Delete Entire Linked List \n");

        printf("\n 9 --> Linked List Reversal \n");

        printf("\n 10 --> Bubble Sort \n");

        printf("\n 11 --> Binary Search \n");

        printf("\n 12 --> Linked List Traversal \n");

        printf("\n 0 --> Exit from the program \n");

        printf("\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Insert Element at the beginning\n");
            int beg;
            scanf("%d", &beg);
            head = insertAtBeginning(head, beg);
            size++;

            break;

        case 2:
            printf("Insert Element at the end\n");
            int end;
            scanf("%d", &end);
            head = insertAtEnd(head, end);
            size++;

            break;

        case 3:
            printf("Insert Element at a given Index\n");
            int index, value;
            printf("Position: ");
            scanf("%d", &index);
            printf("Value: ");
            scanf("%d", &value);
            head = insertAtIndex(head, value, index);
            size++;

            break;

        case 4:
            printf("Deletion of Element at the beginning\n");
            head = deleteAtBeginning(head);
            size--;

            break;

        case 5:
            printf("Deletion of Element at the end\n");
            head = deleteAtEnd(head);
            size--;

            break;

        case 6:
            printf("Deletion of Element at a given Index\n");
            int index1;
            printf("Index: ");
            scanf("%d", &index1);
            if (index == 0)
            {
                head = deleteAtBeginning(head);
            }
            else
            {
                head = deleteAtIndex(head, index1);
                size--;
            }
            break;

        case 7:
            printf("Enter the value you want to delete from linked List");
            int value1;
            scanf("%d", &value1);
            head = deleteByValue(head, value1);
            size--;
            break;

        case 8:
            deleteEntireLinkedList(head);
            exit(1);

        case 9:
            head = linkedListReversal(head);
            printf("Reversal Done!...Traverse it again for conformation\n");
            break;

        case 10:
            bubbleSort(&head, size);
            printf("Singly Linked List Sorted!\n");

            break;

        case 11:
            printf("Enter the element you want to search \n");
            int search;
            scanf("%d", &search);

            binarySearch(head, search);

            break;

        case 12:
            traversal(head);
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
