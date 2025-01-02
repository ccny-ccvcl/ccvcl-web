//
//  Example solutions (iteratively and recursively) with testing code for Exam 2 extra credit problem 1.
//  Note: (1) You will need the node2.h and node2.template files for compiling this code.
//        (2) These two files can be downloaded at: http://ccvcl.org/~fhu/Sample_Code_CSc212/Lecture_11_Sample_Code/node2-ppt.html
//  Created by Feng Hu on 11/22/16.
//  Copyright © 2016 Feng Hu. All rights reserved.
//

#include <iostream>
#include "node2.h"
using namespace main_savitch_6B;
using namespace std;

// Solution 1: reverse the linked list iteratively
node<int>* reverse_iteratively(node<int>* head){
    if(head == NULL){
        return head;
    }
    
    node<int>* prev = NULL;
    node<int>* current = head;
    node<int>* next;
    
    while (current != NULL) {
        next = current->link();
        current->set_link(prev);
        prev = current;
        current = next;
    }
    return prev;
}

// Solution 2: reverse the linked list recursively
node<int>* reverse_recursively(node<int>* head){
    if (head->link() == NULL) {
        return head;
    }else{
        node<int>* temp = reverse_recursively(head->link());
        head->link()->set_link(head);
        head->set_link(NULL);
        return temp;
    }
}


// Testing code
int main(int argc, const char * argv[]) {
    node<int>* head = NULL;
    list_head_insert(head, 4);
    list_head_insert(head, 3);
    list_head_insert(head, 2);
    list_head_insert(head, 1);
    
    // Make a copy of the linked list for testing recursively reverse
    node<int>* head_duplicate = NULL;
    node<int>* tail_duplicate = NULL;
    list_copy(head, head_duplicate, tail_duplicate);
    
    cout << "Print the original linked list" << endl;
    node<int>* temp = head;
    while (temp != NULL) {
        cout << temp->data() << endl;
        temp = temp->link();
    }
    
    // Iteratively reverse the linked list
    node<int>* head_iteratively = head;
    head_iteratively = reverse_iteratively(head_iteratively);
    
    cout << "Print the iteratively reversed linked list" << endl;
    temp = head_iteratively;
    while (temp != NULL) {
        cout << temp->data() << endl;
        temp = temp->link();
    }
    
    // Recursively reverse the linked list
    node<int>* head_recursively = NULL;
    head_recursively = reverse_recursively(head_duplicate);
    
    cout << "Print the recursively reversed linked list" << endl;
    temp = head_recursively;
    while (temp != NULL) {
        cout << temp->data() << endl;
        temp = temp->link();
    }
    
    return 0;
}

