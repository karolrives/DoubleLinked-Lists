//
//  main.c
//  Double Linked Lists
//
//  Created by A Carolina Figueroa Rives on 2015-08-14.
//  Copyright © 2015 A Carolina Figueroa Rives. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "list.c"
#define MAXNODE 100
#define MINNODE 1
#define POSITION 90

DoubleList *dl;

void test_create (){                                                // Initializing the DL
    dl = initialize ();
    assert(dl != NULL);                                             // Should be different than NULL
}

void test_populate () {
    int node;
    for (node = MINNODE; node <= MAXNODE; node ++)                  // Inserting elements into the DL from MINNODE to MAXNODE
        assert (append (dl,node) == 0);                             // append should returns 0 if the insertion is succesful
}

void test_head() {
    removeFirst(dl);                                                // Removing first element
    assert(getFirstElement(dl) == MINNODE+1);                       // First element should be the following element now
}

void test_tail() {
    removeLast(dl);                                                 // Removing last element
    assert(getLastElement(dl) == MAXNODE-1);                        // Last element should be the previous element now
}

void test_remove_at() {
    ListElement *elem = getElementAt(dl,POSITION);                  // Getting an element at POSITION

    if (removeElementAt(dl,POSITION) == 0) {                        // Removing that element from DL
        assert (getElementAt(dl,POSITION) == elem->next);           // Element at POSITION should be the following element now
        assert (getElementAt(dl,POSITION)->prev == elem->prev );    // Previous elem of element at POSITION should be previous element of the removed element
    }
    free (elem);
}

void test_destroy() {
    destroy(dl);                                                    // Destroying every element of DL and DL
}

int main(void)
{

    test_create();
    test_populate();
    test_head();
    test_tail();
    test_remove_at();
    print(dl);
    test_destroy();

    return 0;
}

