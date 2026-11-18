
#include "AutoShopQueue.h"

int main(void)
{
    QueueNodePtr frontPtr = NULL;
    QueueNodePtr rearPtr = NULL;
    int choice;

    instructions();

    choice = readInteger("? ");

    while (choice != 7) {

        switch (choice) {

            case 1:
                frontOfQueue(frontPtr);
                break;

            case 2:
                backOfQueue(rearPtr);
                break;

            case 3:
                frontPtr = enqueue(frontPtr, &rearPtr);
                break;

            case 4:
                frontPtr = dequeue(frontPtr, &rearPtr);
                break;

            case 5:
                searchQueue(frontPtr);
                break;

            case 6:
                printQueue(frontPtr);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        } 

        instructions();

        choice = readInteger("? ");
    }

    /* Free remaining nodes before exiting */
    while (!isEmpty(frontPtr)) {
        frontPtr = dequeue(frontPtr, &rearPtr);
    }

    printf("Exiting Auto Shop Parts Service Line.\n");

    return 0;
}
