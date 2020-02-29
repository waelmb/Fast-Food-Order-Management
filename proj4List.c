#include "proj4.h"

//Adds an item to the end of the list
void addToList(node** hd, char* name, int burgers, int salads, int isInRestaurant) {
 node* curr = *hd;
 node* prev = NULL;

 /* find the end of the list */
 while (curr != NULL)
 {
    if(debugMode == TRUE) {
    	printf ("(addToList) Traversing list: current is %s, %d burgers, %d salads, ", curr->name, curr->burgers, curr->salads);
    	if(curr->isInRestaurant == 0) {
    	printf ("isn't in restaurant yet.\n");	
		}
		else {
			printf ("is in restaurant.\n");	
		}
	}
	prev = curr;
    curr = curr->next;
 }

 /* create the new node to be inserted into the list */
 node* ptr = (node*) malloc (sizeof(node));
 ptr->name = name;
 ptr->burgers = burgers;
 ptr->salads = salads;
 ptr->isInRestaurant = isInRestaurant;
 ptr->next = curr;   /* curr is always NULL at this line of code */

 /* if the list is empty the new node goes at the front (update head) */
 if (prev == NULL)
   {
    *hd = ptr;
   }
 else
   {
    prev->next = ptr;
   }
}

//Checks if the name exists
int doesNameExist(node* hd, char* name) {
	while(hd != NULL) {
		if(debugMode == TRUE) {
    		printf ("(doesNameExist) Traversing list: current is %s, %d burgers, %d salads, ", hd->name, hd->burgers, hd->salads);
    		if(hd->isInRestaurant == 0) {
    			printf ("isn't in restaurant yet.\n");	
			}
			else {
				printf ("is in restaurant.\n");	
			}
		}
		if(strcmp(hd->name, name) == 0) {
			return TRUE;
		}
		hd = hd->next;
	}
	return FALSE;
}

//Updates the in-restaurant status
int updateStatus(node** hd, char* name, int isInRestaurant) {
 	node* curr = *hd;

 	/* find the end of correct item in the list */
 	while (strcmp(curr->name, name) != 0 && curr->next != NULL)
    {
		if(debugMode == TRUE) {
    		printf ("(updateStatus) Traversing list: current is %s, %d burgers, %d salads, ", curr->name, curr->burgers, curr->salads);
    		if(curr->isInRestaurant == 0) {
    			printf ("isn't in restaurant yet.\n");	
			}
			else {
			printf ("is in restaurant.\n");	
			}
		}
		curr = curr->next;
    }
    if(strcmp(curr->name, name) == 0) {
    	//Update the status
    	curr->isInRestaurant = isInRestaurant;
		return TRUE;	
	}
	else {
		return FALSE;
	}
    
}

//Removes the first element of the linked list 
char* retrieveAndRemove(node** hd, int burgers, int salads) {
	int counter = 0;
	int isFound = FALSE;
	node* curr = *hd;
	node* prev = NULL;
	char* name; 
	//traverse the list to find the closest matching order
	while(curr != NULL && isFound != TRUE) {
		if(debugMode == TRUE) {
    		printf ("(retrieveAndRemove) Traversing list: current is %s, %d burgers, %d salads, ", curr->name, curr->burgers, curr->salads);
    		if(curr->isInRestaurant == 0) {
    			printf ("isn't in restaurant yet.\n");	
			}
			else {
				printf ("is in restaurant.\n");	
			}
		}
		if(curr->isInRestaurant == TRUE && curr->burgers <= burgers && curr->salads <= salads) {
				isFound = TRUE;
				break;
		}
		counter++;
		prev = curr;
		curr = curr->next;
	}
	
	//return name
	if(isFound == TRUE) {
		name = curr->name;
		free(curr->name);
		//if the elemnt is at the start of the list
		if(counter == 0) {
			*hd = curr->next;
	    	free (curr);
		}
		//if the element is at the end of the list
		else if(counter == countOrders(*hd)-1) {
			prev->next = NULL; 
			free (curr);
		}
		//if the element is at the middle of the list
		else {
			prev->next = curr->next;
			free(curr);
		}
		return name;
	}
	else {
		name = "\0";
		return name;
	}
}

//returns the number of orders ahead
int countOrdersAhead(node* hd, char* name) {
	int length = 0;
 	while (hd != NULL && strcmp(hd->name, name) != 0 )
   	{
    	if(debugMode == TRUE) {
    		printf ("(countOrdersAhead) Traversing list: current is %s, %d burgers, %d salads, ", hd->name, hd->burgers, hd->salads);
    		if(hd->isInRestaurant == 0) {
    			printf ("isn't in restaurant yet.\n");	
			}
			else {
				printf ("is in restaurant.\n");	
			}
		}
		length++;
    	hd = hd->next;
   	}
 	return length;
}

//returns the number of total orders
int countOrders(node* hd) {
	int length = 0;
 	while (hd != NULL)
   	{
    	if(debugMode == TRUE) {
    		printf ("(cound orders) Traversing list: current is %s, %d burgers, %d salads, ", hd->name, hd->burgers, hd->salads);
    		if(hd->isInRestaurant == 0) {
    			printf ("isn't in restaurant yet.\n");	
			}
			else {
				printf ("is in restaurant.\n");	
			}
		}
		length++;
    	hd = hd->next;
   	}
 	return length;
}

// display waiting time for a specific order
int displayWaitingTime(node* hd, char* name) {
	int time = 0;
 	while (strcmp(hd->name, name) != 0 && hd->next != NULL)
   	{
    	if(debugMode == TRUE) {
    		printf ("(displayWaitingTime) Traversing list: current is %s, %d burgers, %d salads, ", hd->name, hd->burgers, hd->salads);
    		if(hd->isInRestaurant == 0) {
    			printf ("isn't in restaurant yet.\n");	
			}
			else {
				printf ("is in restaurant.\n");	
			}
		}
		time = time + (BURGERS_TIME * hd->burgers) + (SALADS_TIME * hd->salads);
    	hd = hd->next;
   	}
 	return time;
}

// display orders ahead of a specific order
void displayOrdersAhead (node* hd, char* name) {
	int orderExists = doesNameExist(hd, name);
	
	//traverse the list
	while (strcmp(hd->name, name) != 0 && hd->next != NULL && orderExists == TRUE)
    {
		if(debugMode == TRUE) {
    		printf ("(displayOrdersAhead) Traversing list: current is %s, %d burgers, %d salads, ", hd->name, hd->burgers, hd->salads);
    		if(hd->isInRestaurant == 0) {
    			printf ("isn't in restaurant yet.\n");	
			}
			else {
				printf ("is in restaurant.\n");	
			}
		}
		printf ("%s, %d burgers, %d salads, ", hd->name, hd->burgers, hd->salads);
	    if(hd->isInRestaurant == 0) {
	    	printf ("isn't in restaurant yet.\n");	
		}
		else {
			printf ("is in restaurant.\n");	
		}
	    hd = hd->next;
    }
}

// displays the entire list
void displayListInformation (node* hd) {
	int length = 0;
	while (hd != NULL)
   {
    	if(debugMode == TRUE) {
    		printf ("(displayListInformation) Traversing list: current is %s, %d burgers, %d salads, ", hd->name, hd->burgers, hd->salads);
    		if(hd->isInRestaurant == 0) {
    			printf ("isn't in restaurant yet.\n");	
			}
			else {
				printf ("is in restaurant.\n");	
			}
		}
		printf ("%d burgers, %d salads, for %s, ", hd->burgers, hd->salads, hd->name);
	    if(hd->isInRestaurant == 0) {
	    	printf ("isn't in restaurant yet.\n");	
		}
		else {
			printf ("is in restaurant.\n");	
		}
	    hd = hd->next;
	    length++;
   }
 	printf ("Number of orders: %d\n", length);
}
