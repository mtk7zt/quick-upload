// Queue routine definitions (Using array implementation) header file
#include <stdio.h>
#include <stdlib.h>

// Set Predefined Constant for Queue size
#define MaxQ 10
#define EmptyValue -9999

// Define queue structure
typedef struct queueType{
  int head;
  int tail;
  int QA[MaxQ];
}QueueType, *QueueTypePtr;
   
// Function Prototypes
QueueTypePtr initQueue();	 		   	/*Initialise queue       */
int isEmpty(QueueTypePtr qPtr);	                     	/*Check if queue is empty*/
void enqueue(QueueTypePtr qPtr, int value);            	/*Add to queue           */
int dequeue(QueueTypePtr qPtr);		                /*Remove from Queue      */
void front(QueueTypePtr qPtr);
void back(QueueTypePtr qPtr);

// Function Definitions
void front(QueueTypePtr qPtr)
{
  if(isEmpty(qPtr)){
     puts("Queue is Empty... Nothing at front");
  }else{
     printf("%d is Front of Queue\n", qPtr->QA[qPtr->head + 1]);
  }
}

void back(QueueTypePtr qPtr)
{
  if(isEmpty(qPtr)){
     puts("Queue is Empty... Nothing at back");
  }else{
     printf("%d is Back of Queue\n", qPtr->QA[qPtr->tail]);
  }
}

QueueTypePtr initQueue() 		        /*Initialise queue       */
{
  QueueTypePtr qPtr;				// declare Q pointer
  qPtr = malloc(sizeof(QueueType));		// create memory for queue
  if(qPtr != NULL){
      qPtr->head = 0;				// initialise Q indexes head , tail
      qPtr->tail = 0;
  }else{
     puts("Memory Issues... Queue not created");
  }
  return qPtr;					// return pointer to Q
}


int isEmpty(QueueTypePtr qPtr)                 /*Check if queue is empty*/
{
   // return true is head == tail;
   return (qPtr->head == qPtr->tail);
}

void enqueue(QueueTypePtr qPtr, int value)		/*Add to queue           */
{
   if(qPtr->tail == MaxQ-1){		// check if tail is MaxQ before incrementing tail
      qPtr->tail = 0;	// set to zero since it is a circular array implementation
   }
   else{
      ++(qPtr->tail);			// otherwise do a normal increment
   }
   if(qPtr->head == qPtr->tail){	// check if queue is full after the increment
      puts("Overflow: Queue is full... "); 
      if(qPtr->tail == 0){// condition to undoing the circular increment since queue is full
         qPtr->tail = MaxQ-1;		// undo circular increment
      }
      else{
         --(qPtr->tail);		// otherwise undo regular increment
      }
      return;
   }
   qPtr->QA[qPtr->tail] = value;	//store value into Q array at tail index
}


int dequeue(QueueTypePtr qPtr)	                /*Remove from Queue      */
{
   if (isEmpty(qPtr)){  // check if queue is empty
      puts("Queue is empty... nothing to dequeue");
      return EmptyValue;
   }
   
   if(qPtr->head == MaxQ-1){		// condition increment head index for circular array
      qPtr->head = 0;			// set index to zero
   }
   else{
      ++(qPtr->head);			// otherwise do a regular increment
   }
   return qPtr->QA[qPtr->head];		// return dequeued value
}







