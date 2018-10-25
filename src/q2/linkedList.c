#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
    listElement* e = malloc(sizeof(listElement));
  
    //Error in malloc
    if(e == NULL) {
        return NULL;
    }
    
    char* dataPointer = malloc(sizeof(char)*size);
  
    if(dataPointer == NULL){
        free(e);
        return NULL;
    }
    
    strcpy(dataPointer, data);
    e->data = dataPointer;
    e->size = size;
    e->next = NULL;
    
    return e;
}

//Prints out each element in the list
void traverse(listElement* start){
    listElement* current = start;
    
    while(current != NULL){
        printf("%s\n", current->data);
        current = current->next;
    }
    
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
    listElement* newEl = createEl(data, size);
    listElement* next = el->next;
    newEl->next = next;
    el->next = newEl;
  
    return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
    listElement* delete = after->next;
    listElement* newNext = delete->next;
    after->next = newNext;

    free(delete->data);
    free(delete);
}

int length(listElement *list) {
    
    //Pointer to current elements's position in list
    listElement *current = list;
    int counter = 0;
    
    //While current pointer is not empty
    //continue increment counter and go to next element assinging it to current
    while (current != NULL) {
        counter++;
        current = current-> next;
    }
    
    return printf("# of elements in the list: %d \n", counter);
    
}

void push(listElement **list, char *data, size_t size) {
    
    //Create new element and set to a pointer, then
    //get next element and assign it to the list pointer
    //and let the list point point to the new element created
    listElement *newEle = createEl(data, size);
    newEle-> next = *list;
    *list = newEle;
    
}

listElement *pop(listElement **list) {
    listElement *headEle = *list;
    
    //If head of list*, then make the list equal to the next member
    //of the struct the head points to (aka the next element)
    if(headEle) {
        *list = headEle-> next;
    }
    
    return headEle;
    
}

void enqueue(listElement **list, char *dataBits, size_t size) {
    
    //Crete new element and set to a pointer, then
    //get next element in list and assign it to the list pointer
    //and let the list pointer point to the new element created
    listElement *newEle = createEl(dataBits, size);
    newEle-> next = *list;
    *list = newEle;
    
}

listElement *dequeue(listElement *list) {
    listElement *temp = list;
    
    //Go to element at the end aka teh one thats nextEle pointer is NULL
    while((temp-> next)-> next != NULL) {
        temp = temp-> next;
    }
    
    listElement *tailEle = temp-> next;
    temp-> next = NULL;
    
    return tailEle;
    
}
