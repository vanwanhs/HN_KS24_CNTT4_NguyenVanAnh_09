#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    int id;
    char name[100];
    int age;
    char hometown[100];
    char division[100];
    char phone[100];
} Employee;

typedef struct SingleNode {
    Employee employee;
    struct SingleNode *next;
} SingleNode;

SingleNode *createSingleNode(Employee employee) {
    SingleNode *newNode = (SingleNode *)malloc(sizeof(SingleNode));
    newNode->employee = employee;
    newNode->next = NULL;
    return newNode;
}

SingleNode *insertAtEnd(SingleNode *head, Employee employee) {
    SingleNode *newNode = createSingleNode(employee);
    if (head == NULL) return newNode;
    SingleNode *current = head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    return head;
}

void displaySingleNode(SingleNode *head) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    SingleNode *current = head;
    while (current != NULL) {
        Employee e = current->employee;
        printf("Id: %d\n", e.id);
        printf("Name: %s\n", e.name);
        printf("Age: %d\n", e.age);
        printf("Hometown: %s\n", e.hometown);
        printf("Division: %s\n", e.division);
        printf("Phone: %s\n", e.phone);
        printf("==================\n");
        current = current->next;
    }
}

SingleNode *deleteSingleNode(SingleNode *head, int id) {
    if (head == NULL) return head;
    SingleNode *current = head;
    SingleNode *prev = NULL;
    while (current != NULL && current->employee.id != id) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("ID not found!\n");
        return head;
    }
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Deleted successfully!\n");
    return head;
}

SingleNode *updateSingleNode(SingleNode *head, int id) {
    if (head == NULL) return head;
    SingleNode *current = head;
    while (current != NULL) {
        if (current->employee.id == id) {
            printf("Enter new name: ");
            fgets(current->employee.name, 100, stdin);
            current->employee.name[strlen(current->employee.name)-1] = '\0';

            printf("Enter new age: ");
            scanf("%d", &current->employee.age);
            while (getchar() != '\n');

            printf("Enter new hometown: ");
            fgets(current->employee.hometown, 100, stdin);
            current->employee.hometown[strlen(current->employee.hometown)-1] = '\0';

            printf("Enter new division: ");
            fgets(current->employee.division, 100, stdin);
            current->employee.division[strlen(current->employee.division)-1] = '\0';

            printf("Enter new phone: ");
            fgets(current->employee.phone, 100, stdin);
            current->employee.phone[strlen(current->employee.phone)-1] = '\0';

            printf("Update success!\n");
            return head;
        }
        current = current->next;
    }
    printf("ID not found!\n");
    return head;
}

void sortByDivision(SingleNode *head) {
    if (head == NULL || head->next == NULL) {
        printf("List too short to sort!\n");
        return;
    }

    for (SingleNode *i = head; i != NULL; i = i->next) {
        for (SingleNode *j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->employee.division, j->employee.division) > 0) {
                Employee temp = i->employee;
                i->employee = j->employee;
                j->employee = temp;
            }
        }
    }

    printf("Sorted by division successfully!\n");
}

void findEmployee(SingleNode *head, char *name) {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    int found = 0;
    SingleNode *current = head;
    while (current != NULL) {
        if (strcmp(current->employee.name, name) == 0) {
            Employee e = current->employee;
            printf("Id: %d\n", e.id);
            printf("Name: %s\n", e.name);
            printf("Age: %d\n", e.age);
            printf("Hometown: %s\n", e.hometown);
            printf("Division: %s\n", e.division);
            printf("Phone: %s\n", e.phone);
            printf("==================\n");
            found = 1;
        }
        current = current->next;
    }
    if (!found) printf("Name not found!\n");
}


void menu(void) {
    printf("\n===== EMPLOYEE MANAGER =====\n");
    printf("1. Insert\n");
    printf("2. Display\n");
    printf("3. Delete\n");
    printf("4. Update\n");
    printf("5. Sort by Division\n");
    printf("6. Find by Name\n");
    printf("7. Save to File\n");
    printf("8. Exit\n");
    printf("Choice: ");
}

int main() {
    int choice;
    SingleNode *head = NULL;
    int nextId = 1;
    do {
        menu();
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1: {
                Employee e;
                e.id = nextId++;
                printf("Enter name: ");
                fgets(e.name, 100, stdin);
                e.name[strlen(e.name)-1] = '\0';

                printf("Enter age: ");
                scanf("%d", &e.age);
                while (getchar() != '\n');

                printf("Enter hometown: ");
                fgets(e.hometown, 100, stdin);
                e.hometown[strlen(e.hometown)-1] = '\0';

                printf("Enter division: ");
                fgets(e.division, 100, stdin);
                e.division[strlen(e.division)-1] = '\0';

                printf("Enter phone: ");
                fgets(e.phone, 100, stdin);
                e.phone[strlen(e.phone)-1] = '\0';

                head = insertAtEnd(head, e);
                break;
            }
            case 2:
                displaySingleNode(head);
                break;
            case 3: {
                int id;
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                while (getchar() != '\n');
                head = deleteSingleNode(head, id);
                break;
            }
            case 4: {
                int id;
                printf("Enter ID to update: ");
                scanf("%d", &id);
                while (getchar() != '\n');
                head = updateSingleNode(head, id);
                break;
            }
            case 5:
                break;
            case 6:
                sortByDivision(head);
                break;
            case 7:
                char name[100];
                printf("Enter name to find: ");
                fgets(name, 100, stdin);
                name[strlen(name)-1] = '\0';
                findEmployee(head, name);
                break;
                break;
            case 8:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);
    return 0;
}