#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};


class linked_list{
private:
    node *head, *tail;
    int size;

    node* get_node(int val){
        node *temp = new node;
        temp -> data = val;
        temp -> next = NULL;

        return temp;
    }
public:
    linked_list(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void print(){
        node *temp = head;
        while(temp != NULL){
            cout<<temp->data;

            if(temp->next == NULL){ //last element
                cout<<endl;
            }else{
                cout<<" --> ";
            }
            temp = temp->next;   
        }

    }

    void push_back(int val){
        
        node *temp = get_node(val);

        if(head == NULL){
            head = tail = temp;
        }else{
            tail -> next = temp;
            tail = temp;
        }
        size++;
    }

    int get_size(){
        return size;
    }

    void push_front(int val){
        node *temp = get_node(val);

        if(head == NULL){
            head = tail = temp;
        }else{
            temp -> next = head;
            head = temp;
        }
        size++;
    }

    void insert(int index, int val){
        if(index > size || index < 0){
            cout<< "Not possible to insert " <<val<<" at position " << index <<endl;;
            return;
        }

        if(index == 0){
            push_front(val);
        }else if(index == size){
            push_back(val);
        }else{
            node *new_node = get_node(val);

            node *prev = head;
            for(int i = 0; i< index - 1 ; i++){
                prev = prev -> next;
            }

            new_node -> next = prev -> next;
            prev -> next = new_node;
            size++;
        }
    }

    void print_kth(int index){
        if(index >= size  || index <0){
            cout<<"Out of bound index\n";
            return;
        }

        node *temp = head;

        for(int i = 0; i< index ; i++){
            temp = temp -> next;
        }
        cout<< temp-> data <<endl;
    }

    void delete_kth(int index){
        if(index >= size || index <0){
            cout<<"Out of bound index\n";
            return;
        }

        node *prev, *cur = head;
        if(index == 0){
            head = head -> next;
            free(cur);
            size--;
            return;
        }   

        for(int i = 0 ; i < index ; i++){
            prev = cur;
            cur = cur -> next;
        }
        
        prev -> next = cur -> next;
        free(cur);
        size--;

        if(index == size - 1){    //cur was my tail, and cur is now deleted
            tail = prev;
        }        
    }

    void printRecursive(node *temp){
        if(temp == NULL){
            cout<<endl;
            return;
        }

        printRecursive(temp->next);
        cout<< temp->data <<" --> ";
       
        return;
    }

    node* get_head(){
        return head;
    }

    void reverse(node *temp){

        if(temp == NULL || temp -> next == NULL){  //temp is the last element
            head = temp;
            return;
        }

        reverse(temp->next);

        node *nxt = temp->next;
        nxt -> next = temp;
        temp -> next = NULL;
        tail = temp;
    }

};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 


    linked_list a;

    a.push_back(5);
    a.push_back(100);
    a.push_back(-9);
    a.push_front(90);
    a.insert(2, 10);
    a.insert(1, -20);
    a.insert(0,1);
    a.insert(7,-2);
    a.insert(20, -2);
    a.delete_kth(4);
    a.delete_kth(6);
    a.print();
    cout<< a.get_size() <<endl;
    a.print_kth(2);

    a.reverse(a.get_head());
    a.print();
   
    return 0;
}