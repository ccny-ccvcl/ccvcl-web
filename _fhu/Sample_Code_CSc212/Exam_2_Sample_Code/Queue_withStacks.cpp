//
//  Example solutions with testing code for Exam 2 extra credit problem 2.
//  Note: (1) You will need the node2.h and node2.template files for compiling this code. These two files can be downloaded at: http://ccvcl.org/~fhu/Sample_Code_CSc212/Lecture_11_Sample_Code/node2-ppt.html
//        (2) You will also need stack2.h and stack2.template. These two files can be downloaded at: http://ccvcl.org/~fhu/Sample_Code_CSc212/Lecture_12_Sample_Code/stack-ppt.html
//  Created by Feng Hu on 11/22/16.
//  Copyright © 2016 Feng Hu. All rights reserved.
//

#include <iostream>
#include "stack2.h"
using namespace main_savitch_7B;
using namespace std;

class Queue_withStack{
public:
    void push(int x);
    void pop();
    int top();
    bool empty();

private:
    stack<int> input, output;
};


// Push function
void Queue_withStack::push(int x){
    input.push(x);
}

void pouring(stack<int>& input, stack<int>& output){
    if (output.empty()) {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }
}

// Pop function
void Queue_withStack::pop(){
    pouring(input, output);
    output.pop();
}

// Top function
int Queue_withStack::top(){
    pouring(input, output);
    return output.top();
}

// Empty function
bool Queue_withStack::empty(){
    return input.empty() && output.empty();
}

// Testing code
int main(int argc, const char * argv[]) {
    Queue_withStack my_Queue;
    
    cout << my_Queue.empty() << endl;
    
    my_Queue.push(1);
    cout << "Current top: " << my_Queue.top() << endl;
    my_Queue.push(2);
    cout << "Current top: " << my_Queue.top() << endl;
    my_Queue.push(3);
    cout << "Current top: " << my_Queue.top() << endl;
    my_Queue.push(4);
    cout << "Current top: " << my_Queue.top() << endl;
    
    my_Queue.pop();
    cout << "Current top after pop(): " << my_Queue.top() << endl;
    my_Queue.pop();
    cout << "Current top after pop(): " << my_Queue.top() << endl;
    my_Queue.pop();
    cout << "Current top after pop(): " << my_Queue.top() << endl;
    my_Queue.pop();
    
    cout << my_Queue.empty() << endl;
    
    return 0;
}






