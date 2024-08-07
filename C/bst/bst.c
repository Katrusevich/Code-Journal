#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
typedef struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Structure for a queue node
typedef struct QueueNode 
{
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

// Structure for the queue
typedef struct Queue 
{
    QueueNode* front;
    QueueNode* rear;
} Queue;

/**
 * Creates a new tree node.
 * @param data Value for the node.
 * @return Pointer to the created node.
 */
Node* create(int data);

/**
 * Creates a new empty queue.
 * @return Pointer to the created queue.
 */
Queue* createQueue();

/**
 * Adds a node to the tree.
 * @param root The root node of the tree.
 * @param data Value to add.
 * @return Pointer to the root node.
 */
Node* add(Node* root, int data);

/**
 * Adds a tree node to the queue.
 * @param queue Pointer to the queue.
 * @param treeNode Pointer to the tree node to be added to the queue.
 */
void enqueue(Queue* queue, Node* treeNode);

/**
 * Searches for a node in the tree.
 * @param root The root node of the tree.
 * @param data The value to search for.
 * @param parent Pointer to the pointer of the parent node.
 * @return Pointer to the found node or NULL.
 */
Node* search(Node* root, int data, Node** parent);

/**
 * Prints the binary tree in a visually structured format.
 * @param root Pointer to the root node of the tree.
 * @param level Current level of the node being printed.
 */
void print(Node* root, int level);

/**
 * Prints information about the found node.
 * @param node Pointer to the found node.
 * @param parent Pointer to the parent node.
 */
void printNodeInfo(Node* node, Node* parent);

/**
 * Finds the minimum node in the tree.
 * @param node The node to start the search from.
 * @return Pointer to the minimum node.
 */
Node* findMin(Node* node);

/**
 * Removes a node from the tree.
 * @param root The root node of the tree.
 * @param data Value to delete.
 * @return Pointer to the root node.
 */
Node* deleteNode(Node* root, int data);

/**
 * Adds a tree node to the queue.
 * 
 * @param queue Pointer to the queue.
 * @param treeNode Pointer to the tree node to be added to the queue.
 */
Node* dequeue(Queue* queue);

/**
 * Replaces a node with a specified key with a new node with a new key.
 * @param root Pointer to the root node of the tree.
 * @param oldKey The key of the node to be replaced.
 * @param newKey The key of the new node.
 */
void replace(Node** root, int oldKey, int newKey);

/**
 * Performs pre-order tree traversal.
 * @param root The root node of the tree.
 */
void preOrder(Node* root);

/**
 * Performs symmetric (in-order) traversal of the tree.
 * @param root The root node of the tree.
 */
void inOrder(Node* root);

/**
 * Performs a reverse (post-order) traversal of the tree.
 * @param root The root node of the tree.
 */
void postOrder(Node* root);

/**
 * Performs a level-order traversal of the tree.
 * @param root The root node of the tree.
 */
void levelOrder(Node* root);

/**
 * Counts the number of nodes at each level of the tree.
 * @param root The root node of the tree.
 */
void countNodesAtEachLevel(Node* root);

/**
 * Frees all nodes in the queue and the queue itself.
 * @param queue Pointer to the queue to be freed.
 */
void freeQueue(Queue* queue);

int main() 
{
    // Initializing the root of the tree
    Node* root = NULL;

    int choice, value, oldkey, newkey;

    // Initializing the parent node
    Node* parent = NULL;

    while (1) 
	{
        printf("\nMenu:\n");
        printf("1. Add node\n");
        printf("2. Search node\n");
        printf("3. Delete node\n");
        printf("4. Replace node\n");
        printf("5. Print tree\n");
        printf("6. Count nodes at each level\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                root = add(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                Node* node = search(root, value, &parent);
                printNodeInfo(node, parent);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 4:
                printf("Enter oldkey: \n");
                scanf("%d", &oldkey);
                printf("Enter newkey: \n");
                scanf("%d", &newkey);
                replace(&root, oldkey, newkey);
                break;
            case 5:
                print(root, 0);
                printf("Pre-order traversal: ");
                preOrder(root);
                printf("\nIn-order traversal: ");
                inOrder(root);
                printf("\nPost-order traversal: ");
                postOrder(root);
                printf("\nLevel-order traversal: ");
                levelOrder(root);
                printf("\n");
                break;
            case 6:
                countNodesAtEachLevel(root);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}


Node* create(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) 
    {
        // Checking for memory allocation error
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

Queue* createQueue() 
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    if (queue == NULL) 
    {
        // Checking for memory allocation error
        printf("Memory allocation failed\n");
        exit(1);
    }

    queue->front = queue->rear = NULL;
    return queue;
}

Node* add(Node* root, int data) 
{
    if (root == NULL) 
	{
        // If the tree is empty, create a new node
        return create(data);
    }

    // Add a node to the left subtree
    if (data < root->data) 
	{
        root->left = add(root->left, data);
    } 
    
    // Add a node to the right subtree
    else if (data > root->data) 
	{
        root->right = add(root->right, data);  
    } 
    
    else 
	{
        // A node with this value already exists
        printf("Value %d already exists in the tree.\n", data);
    }

    return root;
}

void enqueue(Queue* queue, Node* treeNode) 
{
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));

    if (newNode == NULL) 
    {
        // Checking for memory allocation error
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Initialize the new node
    newNode->treeNode = treeNode;
    newNode->next = NULL;

    if (queue->rear == NULL) 
    {
        // If the queue is empty, new node is both front and rear
        queue->front = queue->rear = newNode;
        return;
    }

    // Add the new node to the end of the queue
    queue->rear->next = newNode;
    queue->rear = newNode;
}


Node* search(Node* root, int data, Node** parent) 
{
    Node* current = root;
    *parent = NULL;

    while (current != NULL && current->data != data) 
	{
        // Update the parent node
        *parent = current;
        
        // Move left or right depending on the value
        if (data < current->data) 
		{
            current = current->left;
        } 
        
        else 
		{
            current = current->right;
        }
    }

    return current;
}

void print(Node* root, int level) 
{
    if (root != NULL) 
    {
        // Print the right subtree first to create a right-aligned view
        print(root->right, level + 1);

        // Print the current node with indentation based on its level
        printf("%*s%d\n", 4 * level, "", root->data);

        // Print the left subtree
        print(root->left, level + 1);
    }
}

void printNodeInfo(Node* node, Node* parent) 
{
    if (node == NULL) 
    {
        printf("Node not found.\n");
        return;
    }

    printf("Node - %d\n", node->data);

    if (parent)
        printf("Parent - %d\n", parent->data);
    else
        printf("Parent - NULL\n");

    if (node->left)
        printf("Left child - %d\n", node->left->data);
    else
        printf("Left child - NULL\n");

    if (node->right)
        printf("Right child - %d\n", node->right->data);
    else
        printf("Right child - NULL\n");
}


Node* findMin(Node* node) 
{
    while (node->left != NULL) 
	{
        node = node->left;
    }
    
    return node;
}

Node* deleteNode(Node* root, int data) 
{
    // Base case: If the tree is empty, return NULL
    if (root == NULL) return root;

    // Recursively find the node to be deleted
    if (data < root->data) 
	{
        root->left = deleteNode(root->left, data);
    } 
    
    else if (data > root->data) 
	{
        root->right = deleteNode(root->right, data);  
    } 
    
    else 
	{
        // Node with the data found
        if (root->left == NULL) 
		{
            Node* temp = root->right;
            free(root);
            return temp;
        } 
        
        else if (root->right == NULL) 
		{
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

Node* dequeue(Queue* queue) 
{
    // If the queue is empty, return NULL
    if (queue->front == NULL) return NULL;

    // Remove the front node from the queue and update the front pointer
    QueueNode* temp = queue->front;
    Node* treeNode = temp->treeNode;
    queue->front = queue->front->next;

    // If the queue is empty now, update the rear pointer to NULL
    if (queue->front == NULL) queue->rear = NULL;

    free(temp);
    return treeNode;
}

void replace(Node** root, int oldKey, int newKey) 
{
    // Delete the node with oldKey
    *root = deleteNode(*root, oldKey);

    // Add a new node with newKey
    *root = add(*root, newKey);
}

void preOrder(Node* root) 
{
    // Traverse the tree in pre-order: visit root, then left subtree, then right subtree
    if (root != NULL) 
	{
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) 
{
    // Traverse the tree in in-order: visit left subtree, then root, then right subtree
    if (root != NULL) 
	{
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Node* root) 
{
    // Traverse the tree in post-order: visit left subtree, then right subtree, then root
    if (root != NULL) 
	{
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void levelOrder(Node* root) 
{
    // Perform level-order traversal using a queue
    if (root == NULL) return;

    Queue* queue = createQueue();
    enqueue(queue, root);

    while (queue->front != NULL) 
    {
        Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL) enqueue(queue, current->left);
        if (current->right != NULL) enqueue(queue, current->right);
    }

    freeQueue(queue);
}


void countNodesAtEachLevel(Node* root) 
{
    // Count and print the number of nodes at each level of the tree
    if (root == NULL) return;

    Queue* queue = createQueue();
    enqueue(queue, root);
    int currentLevel = 0;

    while (queue->front != NULL) 
    {
        int nodeCount = 0;
        Queue* levelQueue = createQueue();

        while (queue->front != NULL) 
        {
            Node* current = dequeue(queue);
            nodeCount++;

            if (current->left != NULL) enqueue(levelQueue, current->left);
            if (current->right != NULL) enqueue(levelQueue, current->right);
        }

        printf("Level %d: %d nodes\n", currentLevel++, nodeCount);
        freeQueue(queue);
        queue = levelQueue;
    }

    freeQueue(queue);
}


void freeQueue(Queue* queue) 
{
    // Dequeue all elements and free the queue itself
    while (queue->front != NULL) 
    {
        dequeue(queue);
    }

    free(queue);
}
