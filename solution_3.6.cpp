#include <iostream>
#include <stack>

using namespace std;

template<typename T>
void sort_stack(stack<T>& s)
{
    stack<T> helper;
    while (s.size() > 0) {
        T t = s.top();
        s.pop();
        if (helper.empty() || t >= helper.top()) {
            helper.push(t);
            continue;
        }
        
        while (helper.size() > 0) {
            T h = helper.top();
            if (t >= h) {
                break;
            }
            s.push(h);
            helper.pop();
        }
        helper.push(t);
    }
    s.swap(helper);
}

template<typename T>
void print_stack(stack<T> s)
{
    cout << "size: " << s.size() << endl;
    int size = s.size();
    for (int i=0; i<size; ++i) {
        cout << s.top() << endl;
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(9);
    s.push(4);
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(5);
    s.push(8);
    s.push(6);
    s.push(7);
    sort_stack(s);
    print_stack(s);
}

