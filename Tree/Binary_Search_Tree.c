#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}tree;

tree *createNode(int data)
{
    tree *newNode = (tree *)malloc(sizeof(tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
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

tree *insert(tree *root, int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }
    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    
    return root;
    

}

int main()
{
    tree *root = NULL;

    int n;
    printf("Enter the number of nodes you want to insert\n");
    scanf("%d", &n);

    printf("Enter the elements\n");
    for(int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }

    // tree *p1 = createNode(10);
    // tree *p2 = createNode(30);
    // tree *p3 = createNode(20);
    // tree *p4 = createNode(50);
    // tree *p5 = createNode(60);

    // p1->left = p2;
    // p1->right = p3;
    // p2->left = p4;
    // p3->right = p5;

    printf("Inorder Traversal:\t");
    inOrderTraversal(root);

    printf("\n");

    printf("Preorder Traversal:\t");
    preOrderTraversal(root);

    printf("\n");

    printf("Postorder Traversal:\t");
    postOrderTraversal(root);

    return 0;
}
