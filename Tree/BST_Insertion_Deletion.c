#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} tree;

tree *createNode(int data)
{
    tree *newNode = (tree *)malloc(sizeof(tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

tree *insertion(tree *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertion(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertion(root->right, data);
    }

    return root;
}

int getMin(tree *root)
{
    tree *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

tree *deletion(tree *root, int data)
{
    if (root != NULL)
    {
        if (root->data > data)
        {
            root->left = deletion(root->left, data);
        }
        else if (root->data < data)
        {
            root->right = deletion(root->right, data);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            else if (root->right == NULL)
            {
                tree *temp = root->left;
                free(root);
                return temp;
            }
            else if (root->left == NULL)
            {
                tree *temp = root->right;
                free(root);
                return temp;
            }
            else
            {
                int leftMaxSubtree = getMin(root->left);
                root->data = leftMaxSubtree;
                root->left = deletion(root->right, leftMaxSubtree);
            }
        }
    }

    return root;
}

void inOrderTraversal(tree *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d\t", root->data);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(tree *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d\t", root->data);
    }
}

void preOrderTraversal(tree *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main()
{
    tree *root = NULL;

    int n;
    printf("Enter the number of nodes you want to insertion\n");
    scanf("%d", &n);

    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        root = insertion(root, value);
    }

    printf("\nInorder Traversal:\t");
    inOrderTraversal(root);

    printf("\n");

    printf("Preorder Traversal:\t");
    preOrderTraversal(root);

    printf("\n");

    printf("Postorder Traversal:\t");
    postOrderTraversal(root);

    printf("\n");

    printf("\nEnter the value ypu want to delete\n");
    int val;
    scanf("%d", &val);
    root = deletion(root, val);

    printf("\n");

    printf("\nInorder Traversal:\t");
    inOrderTraversal(root);

    printf("\n");

    printf("Preorder Traversal:\t");
    preOrderTraversal(root);

    printf("\n");

    printf("Postorder Traversal:\t");
    postOrderTraversal(root);


    return 0;
}
