#include <queue>
#include <iostream>

using namespace std;

class global_time
{
    static int time;
public:
    static int get_time() {
        return time++;
    }
};

int global_time::time = 0;


class Shelter
{
    queue<int> cats;
    queue<int> dogs;
public:
    enum class Animal {dog, cat};
    Shelter& enqueue(Shelter::Animal);
    Shelter::Animal dequeue_any();
    Shelter::Animal dequeue_dog();
    Shelter::Animal dequeue_cat();
};

Shelter& Shelter::enqueue(Shelter::Animal a)
{
    int current_time = global_time::get_time();
    switch (a) {
        case Animal::cat:
            cats.push(current_time);
            break;
        case Animal::dog:
            dogs.push(current_time);
            break;
    }
    return *this;
}

Shelter::Animal Shelter::dequeue_any()
{
    if (cats.empty()) {
        dogs.pop();
        return Animal::dog;
    }
    if (dogs.empty()) {
        cats.pop();
        return Animal::cat;
    }

    int c = cats.front();
    int d = dogs.front();
    if (c < d) {
        cats.pop();
        return Animal::cat;
    }
    dogs.pop();
    return Animal::dog;    
}

Shelter::Animal Shelter::dequeue_dog()
{
    dogs.pop();
    return Animal::dog;
}

Shelter::Animal Shelter::dequeue_cat()
{
    cats.pop();
    return Animal::cat;
}

void print_animal(Shelter::Animal a)
{
    switch (a) {
        case Shelter::Animal::cat:
            cout << "cat" << endl;
            break;
        case Shelter::Animal::dog:
            cout << "dog" << endl;
            break;
    }
}

int main()
{
    Shelter s;
    s.enqueue(Shelter::Animal::cat);
    s.enqueue(Shelter::Animal::cat);
    s.enqueue(Shelter::Animal::cat);
    s.enqueue(Shelter::Animal::dog);
    s.enqueue(Shelter::Animal::cat);
    s.enqueue(Shelter::Animal::cat);
    s.enqueue(Shelter::Animal::cat);
    s.enqueue(Shelter::Animal::dog);
    s.enqueue(Shelter::Animal::cat);
    s.enqueue(Shelter::Animal::dog);
    cout << "{cat, cat, cat, dog, cat, cat, cat, dog, cat, dog}" << endl;
    cout << "dequeue_any -> ";
    print_animal(s.dequeue_any());
    cout << "dequeue_dog -> ";
    print_animal(s.dequeue_dog());
}  
