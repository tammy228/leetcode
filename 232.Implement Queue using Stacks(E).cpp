#include<stack>
using namespace std;


class MyQueue {
public:
    stack<int> s1;
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        stack<int> s2;
        int pop;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        pop = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return pop;
    }

    int peek() {
        stack<int> s2 = s1;
        int peek;
        while(!s1.empty())
            if (s1.size() == 1)
                peek = s1.top();
            s1.pop();

        s1 = s2;
        return peek;
    }

    bool empty() {
        return s1.empty();
    }
};

/*
 * Optimize
 * We could also always maintain n/2 elements in both the stacks, so that the space usage is uniform.
 * pop: this pop method won't need to maintain original stack element.
 * peek: so does peek()
 */
class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    MyQueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }

        int val = out.top();
        out.pop();
        return val;
    }

    int peek() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty() {
        return out.empty() && in.empty();
    }
};