#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
private:
    int _size;
    ListNode* _dummyHead;

public:
    MyLinkedList() {
        _dummyHead = new ListNode(0);   // 虚拟头节点
        _size = 0;                      // 链表大小
    }

    // 打印链表
    void printLinkedList()
    {
        ListNode* node = _dummyHead->next;
        while(node != nullptr)
        {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }

    // 获取节点值
    int get(int index) {
        // 获取节点值时，当index == _size 时，处于链表空节点，不可取
        if(index >= _size || index < 0) return -1;
        
        ListNode* node = _dummyHead->next;
        for(int i = 0; i < index; i++)
        {
            node = node->next;
        }
        return node->val;
    }

    // 新添加头部节点
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size ++;
    }

    // 新添加尾部节点
    void addAtTail(int val) {
        // 添加尾部节点时，需考虑当前链表为空链表情况，则node 从 _dummyHead 开始
        ListNode* node = _dummyHead;
        while(node->next != nullptr)
        {
            node = node->next;
        }
        node->next = new ListNode(val);
        _size ++;
    }

    // 在指定 index 索引下标节点前添加新的节点
    void addAtIndex(int index, int val) {
        // 边界添加不取index == _size，取index == _size 时，为添加在尾部
        if(index > _size || index < 0) return;
        if(index == 0)
        {
            addAtHead(val);
            return;
        }

        ListNode* node = _dummyHead;
        // index - 1 是为了找到插入节点的前一个节点
        for(int i = 0; i < index; i ++)
        {
            node = node->next;
        }

        ListNode* newNode = new ListNode(val);
        newNode->next = node->next;
        node->next = newNode;
        _size ++;
    }

    // 删除指定index索引处的节点
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0) return;

        ListNode* node = _dummyHead;
        // 删除指定 index 索引处节点，需找到前一节点，故取 i < index;
        for(int i = 0; i < index; i ++)
        {
            node = node->next;
        }

        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
        _size --;
    }
};

int main()
{
    MyLinkedList* obj = new MyLinkedList();
    
    // 按照示例顺序执行操作
    // obj->addAtHead(7);
    // obj->printLinkedList();
    // obj->addAtHead(2);
    // obj->printLinkedList();
    // obj->addAtHead(1);
    // obj->printLinkedList();
    // obj->addAtIndex(3, 0);
    // obj->printLinkedList();
    // obj->deleteAtIndex(2);
    // obj->printLinkedList();
    // obj->addAtHead(6);
    // obj->printLinkedList();
    obj->addAtTail(1);
    obj->printLinkedList();
    int param_1 = obj->get(0);
    // obj->addAtHead(4);
    // obj->printLinkedList();
    // obj->addAtIndex(5, 0);
    // obj->printLinkedList();
    // obj->addAtHead(6);
    // obj->printLinkedList();
    
    
    // 输出结果
    cout << param_1 << endl;

    delete obj;
    return 0;
}
