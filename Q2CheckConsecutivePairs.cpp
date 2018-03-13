#include<iostream>
#include<conio.h>
#include<stack>
#include<queue>
#include<math.h>

using namespace std;

bool checkConsecutivePair(int element1, int element2) {
    if(fabs(element1-element2) == 1)
        return true;
    else
        return false;
}

bool checkAllPairs(stack<int> s) {
    queue<int> q;

    // to pop element at top if there are odd number of elements in stack
    if (s.size()%2 != 0) {
        s.pop();
    }

    int element;
    while(s.size() != 0) {
        element = s.top();
        s.pop();
        q.push(element);
        if(!checkConsecutivePair(s.top(), q.front()))
            return false;
        s.pop();
        q.pop();
    }
    return true;
}

int main() {

    stack<int> s;
    int n;
    cout << "\n Enter number of elements: ";
    cin >> n;

    int element;
    for(int i = 0; i < n; i++) {
        cout << " Enter element " << (i+1) << ": ";
        cin >> element;
        s.push(element);
    }

    if(checkAllPairs(s))
        cout << "All consecutive pairs: true";
    else
        cout << "All consecutive pairs: false";

    return 0;
}
