#ifndef LIST_H
#define LIST_H

#include <stdlib.h>


typedef struct Elem {
    int value;
    struct Elem *prev;
    struct Elem *next;

} ListElement;                                              // Element of Double List

typedef struct DList{
    int size;
    ListElement *head;
    ListElement *tail;

} DoubleList;                                               // Double List

DoubleList* initialize ();                                  // Initilizating the Double List
int append(DoubleList *dl, int value );                     // Inserting value at the end of list
ListElement* getElementAt(DoubleList *dl, int index);       // Getting element at specific index
ListElement* searchAt(DoubleList *dl, int index);           // Searching from the beginning to the end
ListElement* reverseSearchAt(DoubleList *dl, int index);    // Searching from the end to the beginning
int removeElementAt(DoubleList *dl, int index);             // Removing element at specific index
int search (DoubleList *dl, int value);                     // Searching value in Double List
void print (DoubleList *dl);                                // Printing out the whole List
int removeLast (DoubleList *dl);                            // Removing last element from the Double List
int removeFirst (DoubleList *dl);                           // Removing first element from the Double List
void destroy (DoubleList *dl);                              // Destroying List and its elements

#define getFirstElement(E) ((E)->head->value)               // Getting value of the first element
#define getLastElement(E) ((E)->tail->value)                // Getting value of the last element
#define getNumberOfElements(E) ((E)->size)                  // Getting number of elements

#endif // LIST_H
