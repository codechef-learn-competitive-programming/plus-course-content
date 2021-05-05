#include <iostream>
using namespace std;
typedef struct nodes {
    int info;
    nodes *next;
} node;

node * ll_getnode(void) {
    node *newnode;
    cout << "Allocating memory for a new node..." << endl;
    if ((newnode = (node *) malloc(sizeof(node))) == NULL) {
        cout << "Not enough memory to allocate buffer..." << endl;
        exit(1);
    };
    return newnode;
}

void ll_delnode(node *delnode) {
    cout << "Releasing memory space against the deleting node..." << endl;
    free (delnode);
}

int main(void) {
    int ll_menu(void);
    void ll_insert(node *&);     // call by reference
    void ll_delete(node *&);     // call by reference
    void ll_update(node *);      // call by value
    void ll_search(node *);      // call by value
    void ll_display(node *);     // call by value
    void ll_quit(void);
    int choice = 0;
    node *start = NULL;

    while(choice != 6) {
        choice = ll_menu();
        switch(choice) {
            case 1:
                ll_insert(start);
                break;
            case 2:
                ll_delete(start);
                break;
            case 3:
                ll_update(start);
                break;
            case 4:
                ll_search(start);
                break;
            case 5:
                ll_display(start);
                break;
            case 6:
                ll_quit();
                break;
        }
    }

}

void ll_quit(void) {
    cout << "End of the program..." << endl;
    cout << "Good bye..." << endl;
}    

int ll_menu(void) {
    int ch = 0;

    while (ch < 1 || ch > 6) {
        cout << endl << "M A I N  M E N U ...." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1 >  I N S E R T  O P E R A T I O N ..." << endl;
        cout << "2 >  D E L E T E  O P E R A T I O N ..." << endl;
        cout << "3 >  U P D A T E  O P E R A T I O N ..." << endl;
        cout << "4 >  S E A R C H  O P E R A T I O N ..." << endl;
        cout << "5 >  D I S P L A Y  O P E R A T I O N ..." << endl;
        cout << "6 >  Q U I T  O P E R A T I O N ..." << endl;

        cout << endl << "Please enter your choice number: ";
        cin >> ch;
    }
    return ch;
}

void ll_insert(node *&st) {
    int newinfo, searchinfo;
    node *ptr, *newnode;

    cout << "Please enter the info for the new node: ";
    cin >> newinfo;
    newnode = ll_getnode();
    newnode->info = newinfo;
    newnode->next = NULL;

    if (st == NULL) {
        cout << "Linked list does not pre-exist..." << endl;
        cout << "Creating the linked with the new node..." << endl;
        st = newnode;
    } else {
        cout << "Linked list is pre-existing..." << endl;
        cout << "Please enter the searching info: ";
        cin >> searchinfo;
        ptr = st;
        while (ptr != NULL && ptr->info != searchinfo) {
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            cout << "Unsuccessful searching !!!" << endl;
            cout << "So the newnode will be prepended..." << endl;
            newnode->next = st;
            st = newnode;
        } else {
            cout << "Successful searching !!!" << endl;
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
    }
    cout << "INSERT operation has been completed successfully..." << endl;
}

void ll_delete(node *&st) {
    int searchinfo;
    node *ptr, *prevptr;

    if (st == NULL) {
        cout << "Linked list is not pre-existing..." << endl;
        cout << "Deletion operation can not be carried out..." << endl;
    } else {
        cout << "Linked list is pre-existing..." << endl;
        cout << "Please enter the info to be searched: ";
        cin >> searchinfo;
        if (st->info == searchinfo) {
            cout << "Search info matching has been found at the first node..." << endl;
            ptr = st;
            st = st->next;
            ll_delnode(ptr);
        } else {
            cout << "Searchinfo has not been found at the start node..." << endl;
            prevptr = st;
            ptr = st->next;
            while (ptr != NULL && ptr->info != searchinfo) {
                prevptr = ptr;
                ptr = ptr->next;
            }
            if (ptr == NULL) {
                cout << "Unsuccessful searching of the search info !!!" << endl;
                cout << "Deletion operation can not be carried out..." << endl;
            } else {
                cout << "Successful searching of the search info..." << endl;
                prevptr->next = ptr->next;
                ll_delnode(ptr);
            }
        }
    }
    cout << "DELETE operation has been completed successfully..." << endl;
}

void ll_update(node *st) {
    int searchinfo, updateinfo;
    node *ptr;

    if (st == NULL) {
        cout << "Linked list does not pre-exist..." << endl;
        cout << "Update operation can not be carried out..." << endl;
    } else {
        cout << "Please enter the search info: ";
        cin >> searchinfo;

        cout << "Linked list is pre-existing..." << endl;
        ptr = st;
        while (ptr != NULL && ptr->info != searchinfo) {
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            cout << "Unsuccessful searching of the search info..." << endl;
        } else {
            cout << "Successful searching against the search info..." << endl;
            cout << "Updating the search info with the update info..." << endl;
            cout << "Enter the update info: ";
            cin >> updateinfo;
            ptr->info = updateinfo;
        }
    }

    cout << "UPDATE operation has been completed successfully..." << endl;   
}

void ll_search(node *st) {
    int searchinfo;
    node *ptr;

    if (st == NULL) {
        cout << "Linked list does not pre-exist..." << endl;
        cout << "Search operation can not be carried out..." << endl;
    } else {
        cout << "Please enter the search info: ";
        cin >> searchinfo;

        cout << "Linked list is pre-existing..." << endl;
        ptr = st;
        while (ptr != NULL && ptr->info != searchinfo) {
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            cout << "Unsuccessful searching of the search info..." << endl;
        } else {
            cout << "Successful searching against the search info..." << endl;
        }
    }

    cout << "SEARCH operation has been completed successfully..." << endl;       
}

void ll_display(node *st) {
    node *ptr;

    if (st == NULL) {
        cout << "Linked list does not pre-exist..." << endl;
        cout << "Display operation can not be carried out..." << endl;
    } else {
        cout << "Linked list is pre-existing..." << endl;
        cout << "Dislaying the current content of the linked list..." << endl;
        ptr = st;
        while (ptr != NULL) {
            cout << "Node Address: " << ptr << ", Info: " << ptr->info 
                                     << " and Link: " << ptr->next << "..." << endl;
            ptr = ptr->next;
        }
    }

    cout << "DISPLAY operation has been completed successfully..." << endl;     
}