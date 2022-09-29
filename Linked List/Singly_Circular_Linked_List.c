#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;

    return newNode;
}

struct Node *push(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *ptr;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        ptr = head;

        while (ptr->next != head)
        {
            ptr = ptr->next;
        }

        newNode->next = head;
        ptr->next = newNode;
    }
    return head;
}

struct Node *lastNode(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    return ptr;
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *last = lastNode(head);

    last->next = newNode;
    newNode->next = head;

    head = newNode;

    printf("Insertion at Beginning Done! \n");

    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *last = lastNode(head);

    newNode->next = head;
    last->next = newNode;

    last = newNode;

    printf("Insertion at End Done! \n");

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
        while (count < position - 1 && ptr->next != head)
        {
            ptr = ptr->next;
            count++;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    printf("Insertion At Position Done! \n");
    return head;
}

struct Node *deletionAtBeginning(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *last = lastNode(head);

    last->next = head->next;
    head = head->next;

    printf("%d node has been deleted\n", ptr->data);
    free(ptr);

    return head;
}

struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *last = lastNode(head);

    while (ptr->next != last)
    {
        ptr = ptr->next;
    }

    ptr->next = head;
    printf("%d node has been deleted\n", last->data);
    free(last);
    last = ptr;

    return head;
}

struct Node *deleteAtPosition(struct Node *head, int position, int size)
{
    struct Node *p = head;
    struct Node *q = head->next;

    if (position == 1)
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
        while (count < position - 1 && p->next != head)
        {
            p = p->next;
            q = q->next;
            count++;
        }

        p->next = q->next;
        printf("%d node has been deleted\n", q->data);
        free(q);
    }

    return head;
}

struct Node *deleteByValue(struct Node *head, int value, int size)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != head)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        printf("%d node has been deleted\n", q->data);
        free(q);
    }
    else
    {
        printf("%d not found\n", value);
    }

    return head;
}

struct Node *deleteEntireList(struct Node *head)
{
    if (head != NULL)
    {
        struct Node *temp, *current;
        current = head->next;
        while (current != head)
        {
            temp = current->next;
            free(current);
            current = temp;
        }
        free(head);
        head = NULL;
    }
    printf("All nodes are deleted successfully.\n");
}

struct Node *reversal(struct Node *head)
{
    if (head == NULL)
    {
        printf("Singly Circular Linked List is Empty\n");
    }
    else
    {
        struct Node *previous = NULL;
        struct Node *current = head;
        struct Node *next;

        do
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;

        } while (current != head);

        head->next = previous;
        head = previous;
    }

    printf("Reversal Done Successfully!\n");

    return head;
}

struct Node *sort(struct Node *head, int size)
{
    struct Node *ptr = head;

    struct Node *i, *j;

    int temp;

    for (i = ptr; i->next != head; i = i->next)
    {
        for (j = i->next; j != head; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }

    printf("\n Singly Circular Linked List Successfully Sorted! \n");

    return head;
}

int totalNodes(struct Node *head)
{
    struct Node *ptr = head;
    int count = 1;
    do
    {
        count++;
        ptr = ptr->next;
    } while (ptr != head);

    return count;
}

void binarySearch(struct Node *head, int element)
{
    int size = totalNodes(head);
    int low = 1;
    int high = size;
    int mid;
    int flag = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        struct Node *ptr = head;

        int count = 1;

        while(ptr->next != head && count < mid)
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
    printf("Enter the Size of Circular Linked List\n");
    scanf("%d", &size);

    printf("Enter %d elements in the Circular Linked List\n", size);

    struct Node *head = NULL;

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

        printf("\n 8 --> Delete Entire Singly Circular Linked List \n");

        printf("\n 9 --> Singly Circular Linked List Reversal \n");

        printf("\n 10 --> Sorting of Singly Circular Linked List \n");

        printf("\n 11 --> Binary Search \n");

        printf("\n 12 --> Singly Circular Linked List Traversal \n");

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
            scanf("%d", &value);
            printf("Enter Position you want to Insert\n");
            int pos;
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
            deleteEntireList(head);
            exit(0);

        case 9:
            head = reversal(head);

            break;

        case 10:
            head = sort(head, size);

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
