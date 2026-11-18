// Queue implemented using an array
#include "queueArrays.h"

int main(void)
{
  QueueTypePtr qPtr = initQueue();		// define Queue Pointer & Initialize Queue
  
  int value; 
  int n;
  printf("Enter some values, zero to quit ");
  scanf("%d",&value);
  while(value != 0)
  {
     enqueue(qPtr, value % 10);
     value = value / 10
     printf("Enter some values, zero to quit ");
     scanf("%d",&value);
  }
  front(qPtr);
  back(qPtr);
  puts("The values in the queue are: ");
  while(!isEmpty(qPtr)) {   			/* queue not empty*/
    printf("%d->", dequeue(qPtr));		//dequeue() and print values
  }
  puts("");
  free(qPtr);					//de-allocate queue memory
}




