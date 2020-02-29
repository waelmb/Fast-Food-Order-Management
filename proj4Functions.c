#include "proj4.h"

void doAdd (node** hd)
{
 /* get number of burgers ordered from input */
 int NumBurgers = getPosInt();
 if (NumBurgers < 0)
   {
    printf ("Error: Add command requires an integer value of at least 0\n");
    printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
    printf ("  where:<# burgers> is the number of ordered burgers\n");
    printf ("        <# salads> is the number of ordered salads\n");
    printf ("        <name> is the name of the person putting the order\n");
    return;
   }

  /* get number of salads ordered from input */
 int NumSalads = getPosInt(); 
 if (NumSalads < 0)
   {
    printf ("Error: Add command requires an integer value of at least 0\n");
    printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
    printf ("  where:<# burgers> is the number of ordered burgers\n");
    printf ("        <# salads> is the number of ordered salads\n");
    printf ("        <name> is the name of the person putting the order\n");
    return;
   }  

 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Add command requires a name to be given\n");
    printf ("Add command is of form: a <# burgers> <# salads> <name>\n");
    printf ("  where:<# burgers> is the number of ordered burgers\n");
    printf ("        <# salads> is the number of ordered salads\n");
    printf ("        <name> is the name of the person putting the order\n");
    return;
   }

 printf ("Adding In-restaurant order for \"%s\": %d burgers and %d salads\n", name, NumBurgers ,NumSalads);

 // add code to perform this operation here
 int orderExists = doesNameExist(*hd, name);
 if(orderExists == TRUE) {
 	printf ("Order for \"%s\" already exists\n", name);
 }
 else {
 	addToList(hd, name, NumBurgers, NumSalads, TRUE);
 }
 
}


void doCallAhead (node** hd)
{
   /* get number of burgers ordered from input */
 int NumBurgers = getPosInt();
 if (NumBurgers < 0)
   {
    printf ("Error: Call-ahead command requires an integer value of at least 0\n");
    printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
    printf ("  where:<# burgers> is the number of ordered burgers\n");
    printf ("        <# salads> is the number of ordered salads\n");
    printf ("        <name> is the name of the person putting the order\n");
    return;
   }

  /* get number of salads ordered from input */
 int NumSalads = getPosInt(); 
 if (NumSalads < 0)
   {
    printf ("Error: Call-ahead command requires an integer value of at least 0\n");
    printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
    printf ("  where:<# burgers> is the number of ordered burgers\n");
    printf ("        <# salads> is the number of ordered salads\n");
    printf ("        <name> is the name of the person putting the order\n");
    return;
   }  


 /* get group name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Call-ahead command requires a name to be given\n");
    printf ("Call-ahead command is of form: c <# burgers> <# salads> <name>\n");
    printf ("  where:<# burgers> is the number of ordered burgers\n");
    printf ("        <# salads> is the number of ordered salads\n");
    printf ("        <name> is the name of the person putting the order\n");
    return;
   }

 printf ("Adding Call-ahead order for \"%s\": %d burgers and %d salads\n", name,NumBurgers ,NumSalads);

 // add code to perform this operation here
 int orderExists = doesNameExist(*hd, name);
 if(orderExists == TRUE) {
 	printf ("Order for \"%s\" already exists\n", name);
 }
 else {
 	addToList(hd, name, NumBurgers, NumSalads, FALSE);
 }
}

void doWaiting (node** hd)
{
 /* get order name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: Waiting command requires a name to be given\n");
    printf ("Waiting command is of form: w <name>\n");
    printf ("  where: <name> is the name of the group that is now waiting\n");
    return;
   }

 // add code to perform this operation here
 int status = updateStatus(hd, name, TRUE);
 if(status == FALSE) {
 	printf ("Call-ahead order \"%s\" didn't place an order\n", name);
 }
 else if(status == TRUE) {
 	printf ("Call-ahead order \"%s\" is now waiting in the restaurant\n", name);
 }

}

void doRetrieve (node** hd)
{
 /* get info of prepared food ready on the counter from input */
 int PreparedBurgers = getPosInt();
 if (PreparedBurgers < 0)
   {
    printf ("Error: Retrieve command requires an integer value of at least 0\n");
    printf ("Retrieve command is of form: r <# burgers> <# salads>\n");
    printf ("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
    printf ("         <# saladss> is the number of salads waiting on the counter for pick up\n");
    return;
   }

 int PreparedSalads = getPosInt();
 if (PreparedSalads < 0)
   {
    printf ("Error: Retrieve command requires an integer value of at least 0\n");
    printf ("Retrieve command is of form: r <# burgers> <# salads>\n");
    printf ("  where: <# burgers> is the number of burgers waiting on the counter for pick up\n");
    printf ("         <# saladss> is the number of salads waiting on the counter for pick up\n");
    return;
   }   

 clearToEoln();
 printf ("Retrieve (and remove) the first group that can pick up the order of %d burgers and %d salads\n", PreparedBurgers ,PreparedSalads);

 // add code to perform this operation here
 char* name = retrieveAndRemove(hd, PreparedBurgers, PreparedSalads);
 if(strcmp(name, "\0") == 0) {
 	printf ("There isn't an order that can be retreived at the moment.");
 } else {
 	printf ("Order %s has been retrieved.", name);
 }
 
}

void doList (node* hd)
{
 /* get order name from input */
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command is of form: l <name>\n");
    printf ("  where: <name> is the name of the order to inquire about\n");
    return;
   }

 printf ("Order for \"%s\" is behind the following orders\n", name);

 // add code to perform this operation here
 int orderExists = doesNameExist(hd, name);
 if(orderExists == FALSE) {
 	printf ("Order for \"%s\" doesn't exist\n", name);
 }
 else {
 	displayOrdersAhead(hd, name);
 	printf ("Number of orders: %d\n", countOrdersAhead(hd, name));
 }
}
 
void doDisplay (node* hd)
{
 clearToEoln();
 printf ("Display information about all orders\n");

 // add code to perform this operation here
 displayListInformation(hd);
}


void doEstimateTime(node* hd)
{
  /* get order name from input */
 
 char *name = getName();
 if (NULL == name)
   {
    printf ("Error: List command requires a name to be given\n");
    printf ("List command is of form: t <name>\n");
    printf ("  where: <name> is the name of the order to inquire about\n");
    return;
   }


  // add code to perform this operation here
  int orderExists = doesNameExist(hd, name);
	 if(orderExists == TRUE) {
	 	int time = displayWaitingTime(hd, name);
  		printf ("Waiting time is %d minutes.\n", time); 
	 }
	 else {
	 	printf ("Order for \"%s\" doesn't exist\n", name);
	 }
   

}


