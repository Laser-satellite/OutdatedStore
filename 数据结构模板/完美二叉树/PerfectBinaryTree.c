#include <stdio.h>
#include <stdlib.h>

typedef int T;
int cmp(T a, T b) { 
    return (a > b) ? 1 : ((a < b) ? -1 : 0); 
}

typedef struct treeNode {
    T data;
    struct treeNode* left;
    struct treeNode* right;
} TreeNode;

TreeNode* createNode(T data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

// TODO: change int to T;
TreeNode* createPerfectBinaryTree(T* array, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    TreeNode* node = createNode(array[mid]);
    node->left = createPerfectBinaryTree(array, start, mid - 1);
    node->right = createPerfectBinaryTree(array, mid + 1, end);

    return node;
}

void preOrderTraversal(TreeNode* root, int Tab) {
    if (root == NULL) {
        return;
    }
    preOrderTraversal(root->left, Tab + 1);
    for (int i = 0; i < Tab; ++i) { printf("  "); }
    printf("%d:\n", (int)root->data);
    preOrderTraversal(root->right, Tab + 1);
}

int main(int argc, char const* argv[]) {
    int array[] = { 81,2,63,4,45,6,27,8 };
    int size = sizeof(array) / sizeof(int);
    TreeNode* root = createPerfectBinaryTree(array, 0, size - 1);
    preOrderTraversal(root, 0);
    return 0;
}