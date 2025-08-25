#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> ringQueue;

public:
    MyStack() { }

    void push(int x) {
        ringQueue.push(x);
    }

    int pop() {
        int size = ringQueue.size();
        size --;

        while(size --)
        {
            ringQueue.push(ringQueue.front());
            ringQueue.pop();
        }
        int ret = ringQueue.front();
        ringQueue.pop();
        return ret;
    }

    int top() {    
        int size = ringQueue.size();
        size --;
        while(size --)
        {
            ringQueue.push(ringQueue.front());
            ringQueue.pop();
        }
        int ret = ringQueue.front();
        ringQueue.push(ringQueue.front());
        ringQueue.pop();

        return ret;
    }

    bool empty() {
        return ringQueue.empty();
    }
};

int main()
{
    MyStack stack;
    stack.push(1);
    
    // cout << stack.top() << endl;   // 返回 4
    cout << stack.pop() << endl;    // 返回 4   
    cout << stack.empty() << endl;  // 返回 False
}

