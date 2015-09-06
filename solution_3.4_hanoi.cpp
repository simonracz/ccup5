#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class hanoi
{
    vector<stack<int>> s;

public:
    hanoi(int);

    void solve(int from, int to);
private:
    void move(int from, int to, int depth);
};

hanoi::hanoi(int size)
{
    s.resize(3);
    for (int i=size; i!=0; --i) {
        s[0].push(i);
    }
}

void hanoi::solve(int from, int to)
{
    hanoi::move(from, to, s[from].size());
}

void hanoi::move(int from, int to, int depth)
{
    if (depth == 1) {
        cout << "moving " << s[from].top() << " from coloumn " << from << " to " << to << ".\n";
        int t = s[from].top();
        s[from].pop();
        s[to].push(t);
        return;
    }

    int third = 3 - from - to;
    hanoi::move(from, third, depth - 1);
    cout << "moving " << s[from].top() << " from coloumn " << from << " to " << to << ".\n";
    int t = s[from].top();
    s[from].pop();
    s[to].push(t);
    hanoi::move(third, to, depth - 1);
}

int main()
{
    auto h = hanoi(3);
    h.solve(0, 2);
    h.solve(2, 1);
} 

