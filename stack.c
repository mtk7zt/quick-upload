
// include stack header-file

int main(void) {
	
	// create stack pointer
	
	int choice;
	int value;
	
	instructions();
	printf("? ");
	scanf("%d", &choice);
	
	while(choice != 4) {
	   switch(choice) {
		case 1:
			//printf("Enter an integer: ");
			//scanf("%d", &value);
			//push node onto stack
			//print the stack nodes
			break;
		case 2:
			//if(!isEmpty(stackPtr)) {
			//	pop node from stack
			//}
			//print the current stack nodes
			break;

                case 3: 
                        //if(!isEmpty(stackPtr)) {
			//	print node at the top of the stack
			//}
                        //else{
                        //   	puts("The Stack is Empty");
                        //}
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





