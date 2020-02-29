// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants
#define MAX_NAME 30
#define TRUE 1
#define FALSE 0
#define BURGERS_TIME 10
#define SALADS_TIME 5

// Structs
//typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

typedef struct nodeStruct 
{
 char* name;
 int burgers;
 int salads;
 int isInRestaurant;
 struct nodeStruct*  next;
} node;

int debugMode;

//Function prototypes
void clearToEoln();

int getNextNWSChar ();

int getPosInt ();

char *getName();

void clearToEoln();

void printCommands();

void doAdd (node** hd);

void doCallAhead (node** hd);

void doWaiting (node** hd);

void doRetrieve (node** hd);

void doList (node* hd);

void doDisplay (node* hd);

void doEstimateTime(node* hd);

void addToList(node** hd, char* name, int burgers, int salads, int isInRestaurant);

int doesNameExist(node* hd, char* name);

int updateStatus(node** hd, char* name, int isInRestaurant);

char* retrieveAndRemove(node** hd, int burgers, int salads) ;

int countOrdersAhead(node* hd, char* name);

int countOrders(node* hd);

void displayOrdersAhead (node* hd, char* name);

void displayListInformation (node* hd);


