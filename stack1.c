// include stack header-file
#include "stack.h"

int main(void) 
{
	
	StackNodePtr stackPtr = NULL;	// create stack pointer
	
	int choice;
	int value;
	
	instructions();
	printf("? ");
	scanf("%d", &choice);
	
	while(choice != 7) {
	   switch(choice) {
		case 1:
			printf("Enter an integer: ");
			scanf("%d", &value);
			stackPtr = push(stackPtr, value); //push node onto stack
			printStack(stackPtr); 		  //print the stack nodes
			break;
		case 2:
			if(!isEmpty(stackPtr)) {
			  stackPtr = pop(stackPtr);//	pop node from stack
			}
			printStack(stackPtr);	   //print the current stack nodes
			break;

                case 3: 
                        if(!isEmpty(stackPtr)) {
			   topOfStack(stackPtr);//print node at the top of the stack
			}
                        else{
                           	puts("The Stack is Empty");
                        }
                        break;
                case 4: 
                        bottomOfStack(stackPtr);//print node at bottom of the stack
			break;
                case 5: 
                        printf("Enter search-key: ");
			scanf("%d", &value);
                        searchOfStack(stackPtr, value);//Search the stack
			break;
                case 6: 
                        printStack(stackPtr);//print the stack
			break;
		default:
			printf("Invalid choice.\n\n");
			break;
		}
		instructions();
	        printf("? ");
		scanf("%d", &choice);
	}
	
	printf("End of run.\n");
	
}





