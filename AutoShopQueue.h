
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure definition */
struct queueNode {
    char partID[20];
    char partName[100];
    char category;
    int quantity;
    double price;
    struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef struct queueNode *QueueNodePtr;

/* Function prototypes */
QueueNodePtr enqueue(QueueNodePtr frontPtr, QueueNodePtr *rearPtr);
QueueNodePtr dequeue(QueueNodePtr frontPtr, QueueNodePtr *rearPtr);
int isEmpty(QueueNodePtr frontPtr);
void frontOfQueue(QueueNodePtr frontPtr);
void backOfQueue(QueueNodePtr rearPtr);
void searchQueue(QueueNodePtr frontPtr);
void printQueue(QueueNodePtr frontPtr);
void instructions(void);
int readInteger(const char prompt[]);
double readDouble(const char prompt[]);


/* Read an integer */
int readInteger(const char prompt[])
{
    char input[100];
    char *end;
    int value;

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        value = (int)strtol(input, &end, 10);

        while (*end == ' ' || *end == '\t') {
            end++;
        }

        if (end != input && (*end == '\n' || *end == '\0')) {
            return value;
        }

        printf("Invalid integer. Try again.\n");
    }
}


/* Read a double */
double readDouble(const char prompt[])
{
    char input[100];
    char *end;
    double value;

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        value = strtod(input, &end);

        while (*end == ' ' || *end == '\t') {
            end++;
        }

        if (end != input && (*end == '\n' || *end == '\0')) {
            return value;
        }

        printf("Invalid number. Try again.\n");
    }
}


/* Check if queue is empty */
int isEmpty(QueueNodePtr frontPtr)
{
    return frontPtr == NULL;
}


/* Add a new part to the back of the queue */
QueueNodePtr enqueue(QueueNodePtr frontPtr, QueueNodePtr *rearPtr)
{
    QueueNodePtr newPtr;
    QueueNodePtr currentPtr;
    QueueNode newPart;
    int valid;
    int i;

    /* Get and validate Part ID */
    do {
        valid = 1;

        printf("Enter Part ID (letters and numbers only): ");
        fgets(newPart.partID, sizeof(newPart.partID), stdin);
        newPart.partID[strcspn(newPart.partID, "\n")] = '\0';

        if (strlen(newPart.partID) == 0) {
            valid = 0;
        }

        /* Check for letters and numbers only */
        for (i = 0; newPart.partID[i] != '\0'; i++) {
            if (!((newPart.partID[i] >= 'A' && newPart.partID[i] <= 'Z') ||
                  (newPart.partID[i] >= 'a' && newPart.partID[i] <= 'z') ||
                  (newPart.partID[i] >= '0' && newPart.partID[i] <= '9'))) {
                valid = 0;
            }
        }

        if (!valid) {
            printf("Invalid ID. Use letters and numbers only.\n");
        }

        /* Check for duplicate Part ID */
        currentPtr = frontPtr;

        while (currentPtr != NULL && valid) {
            if (strcmp(currentPtr->partID, newPart.partID) == 0) {
                printf("This Part ID already exists.\n");
                valid = 0;
            }

            currentPtr = currentPtr->nextPtr;
        }

    } while (!valid);


    /* Get part name */
    printf("Enter Part Name: ");
    fgets(newPart.partName, sizeof(newPart.partName), stdin);
    newPart.partName[strcspn(newPart.partName, "\n")] = '\0';


    /* Get category */
    {
        char categoryInput[100];

        printf("Enter Category (one character): ");
        fgets(categoryInput, sizeof(categoryInput), stdin);
        newPart.category = categoryInput[0];
    }


    /* Get quantity */
    do {
        newPart.quantity = readInteger("Enter Quantity: ");

        if (newPart.quantity <= 0) {
            printf("Quantity must be greater than zero.\n");
        }

    } while (newPart.quantity <= 0);


    /* Get price */
    do {
        newPart.price = readDouble("Enter Price: $");

        if (newPart.price <= 0) {
            printf("Price must be greater than zero.\n");
        }

    } while (newPart.price <= 0);


    /* Allocate memory */
    newPtr = malloc(sizeof(QueueNode));

    if (newPtr != NULL) {
        strcpy(newPtr->partID, newPart.partID);
        strcpy(newPtr->partName, newPart.partName);
        newPtr->category = newPart.category;
        newPtr->quantity = newPart.quantity;
        newPtr->price = newPart.price;

        newPtr->nextPtr = NULL;

        /* If queue is empty, new part is both front and rear */
        if (frontPtr == NULL) {
            frontPtr = newPtr;
            *rearPtr = newPtr;
        }
        else {
            (*rearPtr)->nextPtr = newPtr;
            *rearPtr = newPtr;
        }

        printf("Part successfully added to the service line.\n");
    }
    else {
        printf("Memory allocation failed.\n");
    }

    return frontPtr;
}


/* Remove the next part from the front of the queue */
QueueNodePtr dequeue(QueueNodePtr frontPtr, QueueNodePtr *rearPtr)
{
    QueueNodePtr tempPtr;

    if (isEmpty(frontPtr)) {
        printf("There are no parts waiting for service.\n");
    }
    else {
        tempPtr = frontPtr;

        printf("Removed Part: %s - %s\n",
               tempPtr->partID, tempPtr->partName);

        frontPtr = frontPtr->nextPtr;

        /* If queue becomes empty, rear must also be NULL */
        if (frontPtr == NULL) {
            *rearPtr = NULL;
        }

        free(tempPtr);
    }

    return frontPtr;
}


/* Display the next part waiting for service */
void frontOfQueue(QueueNodePtr frontPtr)
{
    if (isEmpty(frontPtr)) {
        printf("There are no parts waiting for service.\n");
    }
    else {
        printf("\nNext Part for Service:\n");
        printf("Part ID: %s\n", frontPtr->partID);
        printf("Part Name: %s\n", frontPtr->partName);
        printf("Category: %c\n", frontPtr->category);
        printf("Quantity: %d\n", frontPtr->quantity);
        printf("Price: $%.2f\n", frontPtr->price);
    }
}


/* Display the last part in the service line */
void backOfQueue(QueueNodePtr rearPtr)
{
    if (rearPtr == NULL) {
        printf("There are no parts waiting for service.\n");
    }
    else {
        printf("\nLast Part in Service Line:\n");
        printf("Part ID: %s\n", rearPtr->partID);
        printf("Part Name: %s\n", rearPtr->partName);
        printf("Category: %c\n", rearPtr->category);
        printf("Quantity: %d\n", rearPtr->quantity);
        printf("Price: $%.2f\n", rearPtr->price);
    }
}


/* Search for a part using its ID */
void searchQueue(QueueNodePtr frontPtr)
{
    char searchID[20];
    int found = 0;

    printf("Enter Part ID to search: ");
    fgets(searchID, sizeof(searchID), stdin);
    searchID[strcspn(searchID, "\n")] = '\0';

    while (frontPtr != NULL) {
        if (strcmp(frontPtr->partID, searchID) == 0) {
            printf("\nPart Found:\n");
            printf("Part ID: %s\n", frontPtr->partID);
            printf("Part Name: %s\n", frontPtr->partName);
            printf("Category: %c\n", frontPtr->category);
            printf("Quantity: %d\n", frontPtr->quantity);
            printf("Price: $%.2f\n", frontPtr->price);

            found = 1;
            break;
        }

        frontPtr = frontPtr->nextPtr;
    }

    if (!found) {
        printf("Part not found.\n");
    }
}


/* Display all parts waiting for service */
void printQueue(QueueNodePtr frontPtr)
{
    if (isEmpty(frontPtr)) {
        printf("There are no parts waiting for service.\n");
    }
    else {
        printf("\nParts Waiting for Service:\n");

        while (frontPtr != NULL) {
            printf("\nPart ID: %s\n", frontPtr->partID);
            printf("Part Name: %s\n", frontPtr->partName);
            printf("Category: %c\n", frontPtr->category);
            printf("Quantity: %d\n", frontPtr->quantity);
            printf("Price: $%.2f\n", frontPtr->price);

            frontPtr = frontPtr->nextPtr;
        }
    }
}


/* Display menu instructions */
void instructions(void)
{
    printf("\nAUTO SHOP PARTS SERVICE LINE\n");
    printf("1. View Next Part for Service\n");
    printf("2. View Last Part in Line\n");
    printf("3. Add Part to Service Line\n");
    printf("4. Remove Next Part from Service Line\n");
    printf("5. Find a Part\n");
    printf("6. Display All Parts Waiting for Service\n");
    printf("7. Exit\n");
}

