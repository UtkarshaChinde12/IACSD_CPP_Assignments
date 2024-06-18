// create Stack class  for storing 10 numbers
// create function push(int number)--->number will get stored in array
// create function pop() will return top most number ,last added number

// Note:Hadle StackFull and StackEmpty Exception
// Stack s;//array[4];
// s.push(10);s.push(20);s.push(30);//s.push(40); s.push(50);

// int a=s.pop();//------> 30
//   a=s.pop();//----->20
//    a=s.pop();//------>10

// s.pop();//


#include<iostream>
using namespace std;

#include <iostream>

class Stack {
private:
    int array[10];
    int top;

public:
    Stack() : top(-1) {}

    void push(int number) {
        if (top >= 9) {
            throw "StackFull Exception";
        }
        array[++top] = number;
    }

    int pop() {
        if (top < 0) {
            throw "StackEmpty Exception";
        }
        return array[top--];
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    try {
        // Uncomment the line below to test StackFull Exception
       // s.push(40);

        int a = s.pop(); // 30
        std::cout << a << std::endl;

        a = s.pop(); // 20
        std::cout << a << std::endl;

        a = s.pop(); // 10
        std::cout << a << std::endl;

        // Uncomment the line below to test StackEmpty Exception
        //s.pop();
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}