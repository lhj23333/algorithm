#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> inStack;     // 输入栈
    stack<int> outStack;    // 输出栈

    void transferInOut() {
        while(!inStack.empty())
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() { }

    // 队列入队
    void push(int x) {
        inStack.push(x);
    }

    // 队列出队
    int pop() {
        if(outStack.empty())
            transferInOut();

        int ret = outStack.top();
        outStack.pop();
        return ret;
    }

    // 获取队列首元素，不出队
    int peek() {
        if(outStack.empty())
            transferInOut();

        return outStack.top();
    }

    // 队列是否为空
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue queue;
    
    cout << "=== 队列操作测试 ===\n";
    
    // 测试入队
    cout << "入队: 1, 2, 3\n";
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    // 测试队首元素
    cout << "队首元素: " << queue.peek() << "\n";  // 应该是 1
    
    // 测试出队
    cout << "出队: " << queue.pop() << "\n";       // 应该是 1
    cout << "出队: " << queue.pop() << "\n";       // 应该是 2
    
    // 再次入队
    cout << "入队: 4\n";
    queue.push(4);
    
    cout << "队首元素: " << queue.peek() << "\n";  // 应该是 3
    cout << "出队: " << queue.pop() << "\n";       // 应该是 3
    cout << "出队: " << queue.pop() << "\n";       // 应该是 4
    
    // 测试空队列
    cout << "队列是否为空: " << (queue.empty() ? "是" : "否") << "\n";
    
    return 0;
}