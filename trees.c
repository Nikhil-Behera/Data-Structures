#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderRecursive(struct Node* root) {
    if (root == NULL)
        return;
    inorderRecursive(root->left);
    printf("%d ", root->data);
    inorderRecursive(root->right);
}


void preorderRecursive(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}


void postorderRecursive(struct Node* root) {
    if (root == NULL)
        return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    printf("%d ", root->data);
}

#define MAX_STACK_SIZE 100


struct Stack {
    int top;
    struct Node* items[MAX_STACK_SIZE];
};


struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}


bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, struct Node* node) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = node;
}


struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack->items[stack->top--];
}

struct Node* peek(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->items[stack->top];
}


void inorderNonRecursive(struct Node* root) {
    struct Stack* stack = createStack();
    struct Node* current = root;

    while (current != NULL || !isEmpty(stack)) {
       
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        
        current = pop(stack);
        printf("%d ", current->data);

        
        current = current->right;
    }
}


void preorderNonRecursive(struct Node* root) {
    if (root == NULL) return;

    struct Stack* stack = createStack();
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* current = pop(stack);
        printf("%d ", current->data);

        
        if (current->right != NULL)
            push(stack, current->right);
        if (current->left != NULL)
            push(stack, current->left);
    }
}


void postorderNonRecursive(struct Node* root) {
    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();

    if (root == NULL) return;

    push(stack1, root);

    
    while (!isEmpty(stack1)) {
        struct Node* current = pop(stack1);
        push(stack2, current);

        if (current->left != NULL)
            push(stack1, current->left);
        if (current->right != NULL)
            push(stack1, current->right);
    }

   
    while (!isEmpty(stack2)) {
        struct Node* current = pop(stack2);
        printf("%d ", current->data);
    }
}

int main() {
    struct Node* root = createNode(5);
    root->left = createNode(8);
    root->right = createNode(3);
    root->left->left = createNode(2);
    root->left->right = createNode(9);
    root->right->left = createNode(4);
    root->right->right = createNode(1);

    printf("Inorder Traversal (Recursive): ");
    inorderRecursive(root);
    printf("\n");

    printf("Inorder Traversal (Non-Recursive): ");
    inorderNonRecursive(root);
    printf("\n");

    printf("Preorder Traversal (Recursive): ");
    preorderRecursive(root);
    printf("\n");

    printf("Preorder Traversal (Non-Recursive): ");
    preorderNonRecursive(root);
    printf("\n");

    printf("Postorder Traversal (Recursive): ");
    postorderRecursive(root);
    printf("\n");

    printf("Postorder Traversal (Non-Recursive): ");
    postorderNonRecursive(root);
    printf("\n");

    return 0;
}
