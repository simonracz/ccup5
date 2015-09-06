#include <stack>
#include <iostream>

using namespace std;

template<typename T>
class my_queue
{
    stack<T> queue;
    stack<T> helper;
public:
    my_queue<T>& push(T);
    T pop();
    int size() {return queue.size();}
};

template<typename T>
my_queue<T>& my_queue<T>::push(T t)
{
    int s = queue.size();
    for (int i=0; i<s; ++i) {
        helper.push(queue.top());
        queue.pop();
    }
    helper.push(t);
    for (int i=0; i<s+1; ++i) {
        queue.push(helper.top());
        helper.pop();
    }
    return *this;
}

template<typename T>
T my_queue<T>::pop()
{
    T t = queue.top();
    queue.pop();
    return t;
}

int main()
{
    my_queue<int> q;
    q.push(1).push(2).push(3).push(4).push(5);

    int s = q.size();
    cout << "queue size: " << s << endl;
    for (int i=0; i<s; ++i) {
        cout << q.pop() << endl;
    }
}


