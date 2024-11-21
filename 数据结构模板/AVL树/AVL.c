#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    int height; // 我愿称之为 高度因子，而非高度。
} Node;

int myMax(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;
    y->height = myMax(height(y->left), height(y->right)) + 1;
    x->height = myMax(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = myMax(height(x->left), height(x->right)) + 1;
    y->height = myMax(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + myMax(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (root->data < data) {
        return search(root->right, data);
    }

    return search(root->left, data);
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void toString(Node* root, char* output, int* index) {
    if (root == NULL) {
        output[(*index)++] = '*';
        return;
    }

    int length = snprintf(output + *index, 100, "%d", root->data);
    *index += length;
    toString(root->left, output, index);
    toString(root->right, output, index);
}

void view_ori(Node* root, int Tab) {
    if (root == NULL) {
        return;
    }
    view_ori(root->left, Tab + 1);
    for (int i = 0; i < Tab; ++i) {
        printf("        ");
    }
    printf("%d[%d]:", root->data, root->height);
    printf("\n");
    view_ori(root->right, Tab + 1);
}
void view(Node* root, int Tab) {
    view_ori(root, Tab);
    printf("-----\n");
}

void clear(Node* node) {
    if (node->left != NULL) {
        clear(node->left);
    }
    if (node->right != NULL) {
        clear(node->right);
    }
    free(node);
    return;
}

int main() {
    /* TEST */
    srand(time(0));
    Node* root = NULL;

    int a = 0;
    for (int i = 0; i < 20; ++i) {
        a = rand() % 100;
        root = insert(root, a);
    }
    view(root, 0);
    clear(root);

    /*
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    */

/*
    preOrder(root);

    char output[10000] = { 0 };
    int index = 0;
    toString(root, output, &index);
    printf("%s\n", output);

    view(root, 0);
*/
    return 0;
}
