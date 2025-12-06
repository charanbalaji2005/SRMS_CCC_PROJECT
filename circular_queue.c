#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// For storing served customer history
int served[100];
int servedCount = 0;

// ----------------------------------------------------------------------------
// LOGIN SYSTEM
// ----------------------------------------------------------------------------
void login() {
    char username[20], password[20];
    char correctUser[] = "admin";
    char correctPass[] = "1234";

    while (1) {
        printf("\n===== LOGIN REQUIRED =====\n");
        printf("Enter Username: ");
        scanf("%s", username);
        printf("Enter Password: ");
        scanf("%s", password);

        if (strcmp(username, correctUser) == 0 && strcmp(password, correctPass) == 0) {
            printf("\n✔ Login Successful! Welcome %s\n", username);
            break;
        } else {
            printf("\n❌ Incorrect Username or Password. Try Again!\n");
        }
    }
}

// ----------------------------------------------------------------------------
int isFull() {
    return ((rear + 1) % MAX == front);
}

int isEmpty() {
    return (front == -1);
}

// ----------------------------------------------------------------------------
void enqueue(int token) {
    if (isFull()) {
        printf("\n❌ Queue is FULL! No more customers can wait.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = token;

    printf("✔ Customer added → Token %d\n", token);
}

// ----------------------------------------------------------------------------
void dequeue() {
    if (isEmpty()) {
        printf("\n❌ Queue is EMPTY! No customers to serve.\n");
        return;
    }

    printf("\n➡ Serving customer with Token %d\n", queue[front]);
    served[servedCount++] = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// ----------------------------------------------------------------------------
void peek() {
    if (isEmpty()) {
        printf("\n❌ No customers waiting.\n");
        return;
    }
    printf("\n👀 Next customer to serve → Token %d\n", queue[front]);
}

// ----------------------------------------------------------------------------
void displayQueue() {
    if (isEmpty()) {
        printf("\nQueue is EMPTY.\n");
        return;
    }

    printf("\n📌 Current Waiting Queue:\n");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// ----------------------------------------------------------------------------
void displayServed() {
    if (servedCount == 0) {
        printf("\nNo customers served yet.\n");
        return;
    }

    printf("\n📜 Served Customer History:\n");
    for (int i = 0; i < servedCount; i++) {
        printf("%d ", served[i]);
    }
    printf("\n");
}

// ----------------------------------------------------------------------------
void queueSize() {
    if (isEmpty()) {
        printf("\nCurrent Queue Size: 0\n");
        return;
    }

    int size = (rear - front + MAX) % MAX + 1;
    printf("\nCurrent Queue Size: %d\n", size);
}

// ----------------------------------------------------------------------------
void resetQueue() {
    front = rear = -1;
    servedCount = 0;
    printf("\n🔄 Queue system fully reset!\n");
}

// ----------------------------------------------------------------------------
int main() {
    int choice;
    int token = 1;

    login(); // USER MUST LOGIN FIRST

    printf("\n=== ADVANCED CUSTOMER SERVICE SYSTEM USING CIRCULAR QUEUE ===\n");

    while (1) {
        printf("\n---------------- MENU ----------------\n");
        printf("1. New Customer (Enqueue)\n");
        printf("2. Serve Customer (Dequeue)\n");
        printf("3. View Waiting Queue\n");
        printf("4. View Served Customer History\n");
        printf("5. Peek Next Customer\n");
        printf("6. Queue Size\n");
        printf("7. Check if Queue is Full\n");
        printf("8. Check if Queue is Empty\n");
        printf("9. Reset Queue System\n");
        printf("10. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(token++);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                displayServed();
                break;
            case 5:
                peek();
                break;
            case 6:
                queueSize();
                break;
            case 7:
                printf(isFull() ? "\n✔ Queue is FULL\n" : "\nQueue is NOT full\n");
                break;
            case 8:
                printf(isEmpty() ? "\n✔ Queue is EMPTY\n" : "\nQueue is NOT empty\n");
                break;
            case 9:
                resetQueue();
                break;
            case 10:
                printf("\nExiting system...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
