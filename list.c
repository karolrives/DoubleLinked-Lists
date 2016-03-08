#include "list.h"


DoubleList* initialize (){
    DoubleList *dl =(DoubleList *)malloc(sizeof(DoubleList));
    dl->size = 0;
    dl->head = NULL;
    dl->tail = NULL;

    return dl;

}

int append(DoubleList *dl, int value ){

    ListElement *newElement;
    newElement = ( ListElement *)malloc(sizeof(ListElement));   // allocating memory for the new element
    newElement->value = value;

    if (dl->size == 0) {                                        // When the DL doesnt have any element yet
        dl->head = newElement;
        dl->tail = newElement;
    }
    else {
        dl->tail->next = newElement;                            // new element inserting after tail element
        (dl->tail->next)->prev = dl->tail;                      // new element ->prev would be the former tail element

        dl->tail = dl->tail->next;                              // tail pointing at the last element, the new element
        dl->tail->next = NULL;                                  // tail ->next would be NULL because is the last element

    }

    dl->size ++;                                                // Increasing the size of the DL
    return 0;

}

ListElement* getElementAt(DoubleList *dl, int index) {

    if (index > 0 && index <= dl->size) {   // index should be in range 1 to size of dl
        if (index < (dl->size/2))           // if index is located in the first half of size then it searches from the beginning
            return searchAt (dl,index);
        else {                              // otherwise it searches from the end
            index = dl->size - index;
            return reverseSearchAt (dl, index);
        }
    }
    return NULL;
}

ListElement* searchAt(DoubleList *dl, int index) {
    int it;
    ListElement *element;
    element = dl->head;                     // element is needed to iterate the list

    for (it = 1; it <= dl->size; it ++) {   // Iteration from index 1 to the end of list, using dl->size
        if (it == index)
            return element;

        element = element->next;

    }

    return NULL;
}

ListElement* reverseSearchAt(DoubleList *dl, int index) {
    int it;
    ListElement *element;
    element = dl->tail;                     // element is needed to iterate the list

    for (it = 0; it < dl->size; it ++) {    // Iteration from index 1 to the beginning of list, using dl->size
        if (it == index)
            return element;

        element = element->prev;            // going backwards

    }

    return NULL;
}

int removeElementAt(DoubleList *dl, int index) {

    ListElement *element;
    element = getElementAt(dl,index);
    if (element != NULL) {

        if (element == dl->tail)                // if index is the last element
            return removeLast(dl);
        if (element == dl->head)                // if index is the first element
            return removeFirst(dl);

        // else
        (element->next)->prev = element->prev;  // current prev will be prev of next element
        (element->prev)->next = element->next;  // current next will be next of prev element
        element = NULL;                         // clearing current element
        free (element);                         // freeing
        dl->size --;                            // updating size of double list

        return 0;
    }

    return -1;
}

int removeLast (DoubleList *dl) {
    ListElement *element;

    element = dl->tail;         // assigning current tail to a temp var
    dl->tail = dl->tail->prev;  // assigning new tail to the penultimate element
    dl->tail->next = NULL;      // tail doesnt have next element

    dl->size --;                // updating size of double list

    element = NULL;             // clearing
    free (element);             // freeing
    return 0;
}

int removeFirst (DoubleList *dl) {
    ListElement *element;

    element = dl->head;         // assigning current head to a temp var
    dl->head = dl->head->next;  // assigning new head to the following element
    dl->head->prev = NULL;      // head doesnt have prev element

    dl->size --;                // updating size of double list

    element = NULL;             // clearing
    free(element);              // freeing
    return 0;
}

int search (DoubleList *dl, int value) {
    int index;
    ListElement *element;
    element = dl->head;

    for (index = 1; index <= dl->size; index ++) {  // Iteration from index 1 to the end of list, using dl->size
       if (element->value == value)                 // if value matches, return index
           return index;
       element = element->next;
    }

    return -1;
}

void print (DoubleList *dl) {

    int count = 1;
    ListElement *element;
    element = dl->head;

    while (element != NULL) {           // iterating from the beginning to the end
        printf("%i: %i\n",count,element->value);
        element = element->next;
        count ++;
    }
}

void destroy (DoubleList *dl) {
    ListElement *curr;
    curr = dl->head;

    while (curr != NULL) {              // iterating from the beginning to the end
        ListElement *next = curr->next; // assigning next element to another var in order not to lose the reference
        free (curr);                    // freeing curr
        curr = next;                    // curr is now next
    }
    free(dl);                           //freeing Double list
}
