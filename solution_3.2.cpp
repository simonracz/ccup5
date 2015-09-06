#include <iostream>
#include <stack>
#include <utility>

using namespace std;

template<typename T>
class my_stack {
    stack<T> data;
    stack<pair<int, T>> mins;
    int _size = 0;
public:
    my_stack<T>& push(T);
    T pop();
    T min();
    int size() {return _size;}
};

template<typename T>
my_stack<T>& my_stack<T>::push(T t)
{
    ++_size;
    if (mins.empty() || t < mins.top().second) {
        mins.push(make_pair(_size, t));
    }
    data.push(t);
    return *this;
}

template<typename T>
T my_stack<T>::pop()
{
    T t = data.top();
    data.pop();
    if (mins.top().first == _size) {
        mins.pop();
    }
    --_size;
    return t;
}

template<typename T>
T my_stack<T>::min()
{
    return mins.top().second;
}

template<typename T>
void print_s(my_stack<T>& s)
{
    int size = s.size();
    for (int i=0; i<size; ++i) {
        cout << "min: " << s.min() << " elem: " << s.pop() << endl;
    }
}

int main()
{
    my_stack<int> s;
    s.push(5).push(7).push(3).push(4).push(1);
    print_s(s);
}
    


