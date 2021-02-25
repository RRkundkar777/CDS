// Binary Search Tree ADT for multiple Data Types

// Change the typedef for different data types
typedef int infi;

// Node of a Tree
typedef struct node
{
    infi data;
    struct node* left;
    struct node* right;
}node;

//Greater Sizes
typedef long long INT;

//Node pointer as tree
typedef node* tree;

// Functions on Binary Search Tree

// Function to initialise the tree
void initTree(tree *T1);

// Recursive Function for InOrder Traversal
void inOrder(tree T1);

// Recursive Function for PreOrder Traversal
void preOrder(tree T1);

// Recursive Function for PostOrder Traversal
void postOrder(tree T1);

// Function to Iteratively insert an element into BST
void insertI(tree *T1, infi data);

// Recursive function to insert a node into BST
node* insertR(tree T1, infi data);

// Function for Level Order Traversal using Queue
void levelOrder(tree T1);

// Iterative Function for PreOrder Traversal using Stack
void preOrderI(tree T1);

// Iterative Function for InOrder Traversal using Stack
void inOrderI(tree T1);

// Iterative Function for postOrder Traversal using Stack
void postOrderI(tree T1);

// Recursive Function to Delete a Node of a BST
node* deleteNode(tree T1, infi data);

// Recursive Function for Constructing a BST from a Post Order Array
tree constructFromPostOrder(infi array[], int *Index, int data, int min, int max, int size);