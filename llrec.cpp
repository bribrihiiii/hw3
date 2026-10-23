#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
  //std::cout << "llpivot called" << std::endl;

    if(head == NULL){
        smaller = NULL;
        larger = NULL;
        return;
    }

  

    if (head == NULL) {
        return; // just in case
    }

    Node* temp = head;
    Node * nextOne = head->next;
    int theValue = temp->val;
    head = nextOne;

    /* first try
    if(theValue <= pivot) {
        temp->next = smaller;
        smaller = temp;
    }
    llpivot(head, smaller, larger, pivot);
    */

    llpivot(head,smaller,larger,pivot);

    //std::cout << "value is " << theValue << std::endl;

    if(theValue <= pivot) {
        Node* temp2 = smaller;
        temp->next = temp2;
        smaller = temp;
    }

    else if(theValue>pivot){
      Node* temp3 = larger;
      temp->next = temp3;
      larger = temp;
    }
    
    else {
        // should never get here
    }

    head = NULL; //DONT TOUCH
}