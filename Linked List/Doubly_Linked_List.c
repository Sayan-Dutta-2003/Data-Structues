#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *previousNode;
    struct Node *nextNode;
};

void doublyLinkedListForwardTraversal(struct Node *head)
{
    struct Node *p = head;
    while (p != NULL)
    {
        printf("Element: %d\n", p->data);
        p = p->nextNode;
    }
}

void doublyLinkedListBackwardTraversal(struct Node *head)
{
    struct Node *p = head;

    while (p->nextNode != NULL)
    {
        p = p->nextNode;
    }

    while (p != NULL)
    {
        printf("Element: %d\n", p->data);
        p = p->previousNode;
    }
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->previousNode = NULL;
    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
}

struct Node *insertNode(struct Node *head, int data)
{
    struct Node *n = createNode(data);

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        struct Node *ptr = head;

        while (ptr->nextNode != NULL)
        {
            ptr = ptr->nextNode;
        }
        ptr->nextNode = n;
        n->data = data;
        n->previousNode = ptr;
        n->nextNode = NULL;
    }

    return head;
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    newNode->nextNode = head;
    newNode->data = data;
    newNode->previousNode = NULL;
    head = newNode;

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *ptr = head;

    while (ptr->nextNode != NULL)
    {
        ptr = ptr->nextNode;
    }

    ptr->nextNode = newNode;
    newNode->data = data;
    newNode->previousNode = ptr;
    newNode->nextNode = NULL;

    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int pos, int size)
{
    struct Node *newNode = createNode(data);
    struct Node *ptr = head;

    if (pos == 1)
    {
        head = insertAtBeginning(head, data);
    }
    else if (pos == size)
    {
        head = insertAtEnd(head, data);
    }
    else
    {
        int count = 1;
        while (count < pos - 1 && ptr->nextNode != NULL)
        {
            ptr = ptr->nextNode;
            count++;
        }
        newNode->data = data;
        newNode->nextNode = ptr->nextNode;
        newNode->previousNode = ptr;
        ptr->nextNode = newNode;
        ptr->nextNode->previousNode = newNode;
    }

    return head;
}

struct Node *deletionAtBeginning(struct Node *head)
{
    struct Node *ptr = head;

    if (head == NULL) // If no node is present
    {
        printf("Linked List Empty, nothing to delete\n");
        return head;
    }

    else if (ptr->nextNode == NULL) // If only one node is present
    {
        printf("%d Deleted\n", ptr->data);
        return head;
    }
    else
    {
        head = head->nextNode;
        head->previousNode = NULL;
        free(ptr);
        return head;
    }
}

struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    // If no node is present
    if (head == NULL)
    {
        printf("Linked List Empty, nothing to delete\n");
        return head;
    }
    // If only one node is present
    else if (ptr->nextNode == NULL)
    {
        printf("%d Deleted\n", ptr->data);
        return head;
    }

    else
    {
        while (ptr->nextNode != NULL)
        {
            ptr = ptr->nextNode;
        }
        ptr->previousNode->nextNode = NULL;
        free(ptr);

        return head;
    }
}

struct Node *deletionAtPosition(struct Node *head, int pos)
{
    struct Node *ptr = head;
    int count = 1;
    while (ptr->nextNode != NULL && count < pos)
    {
        ptr = ptr->nextNode;
        count++;
    }
    if (ptr->nextNode != NULL)
    {
        ptr->previousNode->nextNode = ptr->nextNode;
        ptr->nextNode->previousNode = ptr->previousNode;
        free(ptr);
    }
    else
    {
        head = deletionAtEnd(head);
    }

    return head;
}

void deleteEntireDoublyLinkedList(struct Node *head)
{
    while (head != NULL)
    {
        head = deletionAtBeginning(head);
        head = head->nextNode;
    }
    if (head == NULL)
    {
        printf("\n Entire Doubly Linked List has been Deleted \n");
    }
}

struct Node *Reversal(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *temp = NULL;

    while (ptr != NULL)
    {
        temp = ptr->previousNode;
        ptr->previousNode = ptr->nextNode;
        ptr->nextNode = temp;

        ptr = ptr->previousNode;
    }

    if (temp != NULL)
    {
        head = temp->previousNode;
    }

    printf("\nDoubly Linked Successfully Reversed!\n");


    return head;
}



struct Node *sort(struct Node *head)
{
    struct Node *ptr = head;

    struct Node *i, *j;

    int temp;

    for(i = ptr; i->nextNode != NULL; i = i->nextNode)
    {
        for(j = i->nextNode; j != NULL; j = j->nextNode)
        {
            if(i->data > j->data)
            {
                temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }

    printf("\n Doubly Linked Successfully Sorted! \n");

    return head;
}

int totalNode(struct Node *head)
{
    struct Node *ptr = head;
    int count = 1;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->nextNode;
    }

    return count;
    
}

void binarySearch(struct Node *head, int element)
{
    int size = totalNode(head);
    int low = 1;
    int high = size;
    int mid;
    int flag = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        int count = 1;
        struct Node *ptr = head;

        while(ptr != NULL && count < mid)
        {
            count++;
            ptr = ptr->nextNode;
        }

        if(element < ptr->data)
        {
            high = mid - 1;
        }
        else if(element > ptr->data)
        {
            low = mid + 1;
        }
        else
        {
            flag = 1;
            break;
        }
    
    }

    if(flag == 1)
    {
        printf("%d found at position %d\n", element, mid);
    }
    else
    {
        printf("%d not found\n", element);
    }
    
    
}

int main()
{

    int size;

    printf("Enter the size of the Doubly Linked List\n");
    scanf("%d", &size);

    struct Node *head = NULL;

    printf("Enter %d elements to create a linked List\n", size);

    for (int i = 0; i < size; i++)
    {
        int element;
        scanf("%d", &element);
        head = insertNode(head, element);
    }

    doublyLinkedListForwardTraversal(head);

    int choice;
    while (1)
    {
        printf("\n 1 --> Insertion at Beginning \n");

        printf("\n 2 --> Insertion at End \n");

        printf("\n 3 --> Insertion at given Position \n");

        printf("\n 4 --> Deletion at Beginning \n");

        printf("\n 5 --> Deletion at End \n");

        printf("\n 6 --> Deletion at given Position \n");

        printf("\n 7 --> Doubly Linked List Forward Traversal \n");

        printf("\n 8 --> Doubly Linked List Backward Traversal \n");

        printf("\n 9 --> Delete Entire Doubly Linked List \n");

        printf("\n 10 --> Reverse the Doubly Linked List \n");

        printf("\n 11 --> Sort the Doubly Linked List \n");

        printf("\n 12 --> Binary Serach \n");

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
            int position, value;
            printf("Position: ");
            scanf("%d", &position);
            printf("Value: ");
            scanf("%d", &value);
            head = insertAtIndex(head, value, position, size);
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
            printf("Enter the Position\n");
            int pos;
            scanf("%d", &pos);
            
            if(pos == 1)
            {
                head = deletionAtBeginning(head);
            }
            else
            {
                head = deletionAtPosition(head, pos);
            }
            size--;
            break;

        case 7:
            doublyLinkedListForwardTraversal(head);

            break;

        case 8:
            doublyLinkedListBackwardTraversal(head);

            break;

        case 9:
            deleteEntireDoublyLinkedList(head);
            exit(1);

        case 10:
            head = Reversal(head);

            break;

        case 11:
            head = sort(head);

            break;
        
        case 12:
            printf("Enter the element you want to search \n");
            int element;
            scanf("%d", &element);
            binarySearch(head, element);

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
