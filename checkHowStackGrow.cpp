/*
    STACK: On a given machine, how do you check whether the stack grows up or down?
    Submitted By:
        Name: Anjali Bansal
        Roll No: 04
*/

#include<iostream>

using namespace std;

void checkStackAdr(int* num1) {
    /*
        Objective: To check whether the stack grows up or down?
        Input parameters:
            a: Integer pointer
        Return Value: None
        Approach: Using address of two numbers and compare them
    */

    int num2;
    cout << "\n Address of num1: " << num1;
    cout << "\n Address of num2: " << &num2;
    if(num1 < &num2) {
        cout << "\n\n Stack grows up!!" << endl;
    }
    else {
        cout << "\n\n Stack grows down!!" << endl;
    }
}


int main() {
    /*
        Objective: To check whether the stack grows up or down?
        Input parameters: None
        Return Value: 0
        Approach: Using checkStackAdr function
    */

    int num1;
    checkStackAdr(&num1);
}
