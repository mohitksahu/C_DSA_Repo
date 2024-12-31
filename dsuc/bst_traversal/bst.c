#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insertnode(struct node* root, int data) {
    if (root == NULL) {
        return createnode(data);
    }

    if (data < root->data) {
        root->left =  insert(root->left, data);
    }

    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;

}

struct node* inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}

struct node* preorder(struct node* root) {
    if(root!= NULL) {
        printf("%d->", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct node* postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d->", root->data);
    }
}

int main() {

}