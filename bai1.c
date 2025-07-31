//
// Created by Hikari on 31/07/2025.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employee{
    int id;
    char name[100];
    int age;
    char hometown[100];
    char division[100];
    char phone[100];
}Employee;
typedef struct SingleNode{
    Employee employee;
    struct SingleNode *next;
}SingleNode;
typedef struct DoubleNode{
    Employee employee;
    struct DoubleNode *next;
    struct DoubleNode *prev;
}DoubleNode;
SingleNode *createSingleNode(Employee employee){
    SingleNode *newNode = (SingleNode *)malloc(sizeof(SingleNode));
    newNode -> employee = employee;
    newNode -> next = NULL;
    return newNode;
}
DoubleNode *createDoubleNode(Employee employee){
    DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));
    newNode -> employee = employee;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}
SingleNode *insertAtEnd(SingleNode *head, Employee employee){
    SingleNode *newNode = createSingleNode(employee);
    if(head == NULL){
    return newNode;
    }
    SingleNode *current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    current -> next = newNode;
    return head;
}
void displaySingleNode(SingleNode *head) {
    if(head == NULL) {
        printf("Empty List\n");
        return;
    }
    SingleNode *current = head;
    while (current != NULL) {
        Employee employee = current -> employee;
        printf("Id: %d\n",employee.id);
        printf("Name: %s\n",employee.name);
        printf("Age: %d\n",employee.age);
        printf("Hometown: %s\n",employee.hometown);
        printf("Division: %s\n",employee.division);
        printf("Phone: %s\n",employee.phone);
        printf("==================\n");
        current = current -> next;
    }
}
SingleNode *deleteSingleNode(SingleNode *head, int id) {
    if (head == NULL) {
        return head;
    }
    SingleNode *current = head;
    SingleNode *prev = NULL;
    while (current != NULL && current ->employee.id != id) {
        prev = current;
        current = current -> next;
    }
    if (current == NULL) {
        return head;
    }
    if (prev == NULL) {
        head = current -> next;
    } else {
        prev -> next = current -> next;
    }
    free(current);
    return head;
}
SingleNode *updateSingleNode(SingleNode *head, int id) {
    if (head == NULL) {
        return head;
    }
    Employee employee = head -> employee;
    SingleNode *current = head;
    while (current -> next != NULL) {
       if (current -> employee.id == id) {
           printf("Enter new name: ");
           fgets(current->employee.name, 100, stdin);
           employee.phone[strlen(employee.name)-1] = '\0';
           printf("Enter new age: ");
           scanf("%d", &employee.age);
           printf("Enter new hometown:");
           fgets(employee.hometown, 100, stdin);
           employee.division[strlen(employee.division)-1] = '\0';
           printf("Enter new division:");
           fgets(employee.division, 100, stdin);
           employee.phone[strlen(employee.phone)-1] = '\0';
           printf("Enter new phone:");
           fgets(employee.phone, 100, stdin);
           printf("Upadate sucession!\n");
           return head;
       }
        current = current -> next;
    }
    printf("Dont find id!\n");
    return head;
}
SingleNode *findStudent(SingleNode *head, char *name) {
    SingleNode *current = head;
    if (current == NULL) {
        return head;
    }
    while (current != NULL) {
        if (strcmp(current->employee.name, name) == 0) {
            printf("Id: %d\n",current ->employee.id);
            printf("Name: %s\n", current->employee.name);
            printf("Age: %d\n", current->employee.age);
            printf("Honetown: %s\n", current->employee.hometown);
            printf("Division: %s\n",current->employee.division);
            printf("Phone: %s\n", current->employee.phone);
        }
        current = current -> next;
    }
    return head;
}
void sort(SingleNode *head) {
    if (head == NULL || head -> next == NULL) {
        printf("Empty List\n");
        return;
    }
    int swapped;
    SingleNode *ptr1;
    SingleNode *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1 -> next != lptr) {
            if (strcmp(ptr1 -> employee.division,lptr -> next -> employee.division) > 0) {
                Employee temp = ptr1 -> employee;
                ptr1 -> employee = ptr1 -> employee;
                ptr1 -> next -> employee = temp;
                swapped = 1;
            }
            ptr1 = ptr1 -> next;
        }
        lptr = ptr1;
    }while(swapped);
    printf("Sorted sucessful\n");
}
void menu(void) {
    printf("1. Insert\n");
    printf("2.Display\n");
    printf("3. Delete\n");
    printf("4.Update\n");
    printf("5.Mark\n");
    printf("6.Sort\n");
    printf("7.FindName\n");
    printf("8.Exit\n");
    printf("Choice your: ");
}
int main() {
    int choice;
    SingleNode *SingleHead = NULL;
    SingleNode *DoubleHead = NULL;
    int nextId = 1;
    int x;
    do{
        menu();
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                Employee employee;
                employee.id = nextId++;
                printf("Enter your name: ");
                fgets(employee.name, 100, stdin);
                employee.name[strlen(employee.name)-1] = '\0';
                printf("Enter your age: ");
                scanf("%d", &employee.age);
                while (getchar() != '\n');
                printf("Enter your hometown: ");
                fgets(employee.hometown, 100, stdin);
                employee.hometown[strlen(employee.hometown)-1] = '\0';
                printf("Enter your division: ");
                fgets(employee.division, 100, stdin);
                employee.division[strlen(employee.division)-1] = '\0';
                    printf("Enter your phone: ");
                    fgets(employee.phone, 100, stdin);
                    employee.phone[strlen(employee.phone)-1] = '\0';
                SingleHead = insertAtEnd(SingleHead,employee);
                break;
            case 2:
                printf("----------List----------\n");
                displaySingleNode(SingleHead);
                break;
            case 3:
                printf("Enter id want delete: ");
                scanf("%d", &x);
                SingleHead = deleteSingleNode(SingleHead, x);
                break;
            case 4:
                printf("Enter id want update: ");
                scanf("%d", &x);
                SingleHead = updateSingleNode(SingleHead, x);
                break;
            case 5:
                break;
            case 6:
                sort(SingleHead);
                break;
            case 7:
                char name[1000];
                printf("Enter name you want to find: ");
                fgets(name, 100, stdin);
                SingleHead = findStudent(SingleHead, name);
                break;
            case 8:
                printf("Arigatogozaimasu\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!= 8);
    return 0;
}
