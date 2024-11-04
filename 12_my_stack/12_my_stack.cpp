#include <iostream>
#include <stack>
#include "MyStack.h"
using namespace std;
int main()
{
    
 /*   MyStack<int> st(2, 2);
    cout << "Size :: " << st.getSize() << endl;
    int value;

    for (size_t i = 0; i < 5; i++)
    {
        cout << "Push element --> " << (value = rand() % 100) << endl;
        st.push(value);
    }
    cout << "Size :: " << st.getSize() << endl;
    cout << "Top el :: " << st.top() << endl;
    st.pop();
    cout << "Top el :: " << st.top() << endl;*/

    stack<string> st;

    st.push("one");
    st.push("two");
    st.push("three");
    cout << "Size :: " << st.size() << endl;
    cout << "Top el :: " << st.top() << endl;
    st.pop();
    cout << "Size :: " << st.size() << endl;
    cout << "Top el :: " << st.top() << endl;
}
