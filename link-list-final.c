//Activity 1: include the link-list header file
#include "link-list-final.h"
 
int main () 
{
  //Activity 2: creating list pointer
  ItemPtr startPtr;
  
  //Activity 3: initialising the start of the list
  startPtr = NULL;
     
  int id=0, choice;
  char name[20];
  char code;
  float price = 0.0;
  menu ();
  scanf ("%d", &choice);
  while (choice != 6)
  {
    switch (choice) //Activity 4: Test your link list tasks
    {
       case 1: printf ("\nEnter ID Name Code Price: ");
               scanf ("%d%s %c%f", &id, name, &code, &price);
	       startPtr = addItem (startPtr, id, name, code, price);
	       printList (startPtr);
	       printf ("\n");
	       break;
       case 2: printf ("\nEnter Item-Id for deletion : ");
	       scanf ("%d", &id);
	       startPtr = removeItem (startPtr, id);
	       printList (startPtr);
	       printf ("\n");
               break;
       case 3: printf ("\nEnter Item-ID : ");
	       scanf ("%d", &id);
	       viewItem (startPtr, id);
	       printf ("\n");
	       break;
       case 4: printList (startPtr);
	       printf ("\n");
	       break;
       case 5: printf ("\nEnter (ID) (New-Name) (New-Code) (New-Price): ");
               scanf ("%d%s %c%f", &id, name, &code, &price);
	       updateItem (startPtr, id, name, code, price);
	       printf ("\n");
	       break;
       default:
	       printf ("Invalid Option... Please Try Again \n");
	       break;
    }
      
    menu ();
    scanf ("%d", &choice);
  }
  
}// end of main


