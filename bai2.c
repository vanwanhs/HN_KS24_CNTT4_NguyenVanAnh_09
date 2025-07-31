//
// Created by Hikari on 31/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct node *left;
    struct node *right;
}Node;
typedef struct QueueNode {
    Node **arr;
    int capacity;
    int front;
    int rear;
}Queue;
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
int main() {
    int choice;
    do {
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 7:
                printf("exit...\n");
                break;
            default:
                printf("Validate choice\n");
        }

    }while (choice != 7);
    return 0;
}
