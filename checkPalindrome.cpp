#include<iostream>
#include<conio.h>
#include<stack>
#include<queue>

using namespace std;

bool checkPalindrome(stack<int> s, queue<int> q) {

    int bit1, bit2;
    while((s.size() != 0) && (q.size() != 0)) {
        bit1 = s.top();
        bit2 = q.front();
        if(bit1 != bit2)
            return false;
        s.pop();
        q.pop();
    }
    return true;
}

int main() {

    stack<int> s;
    queue<int> q;
    int num;
    cout << "\n Enter a number: ";
    cin >> num;

    int temp = num;
    int rem = 0;
    while(temp != 0) {
        rem = temp%10;
        temp = temp/10;
        s.push(rem);
        q.push(rem);
    }

    if(checkPalindrome(s, q))
        cout << "\n Number is Palindrome!";
    else
        cout << "\n Number is not Palindrome!";

    return 0;
}

