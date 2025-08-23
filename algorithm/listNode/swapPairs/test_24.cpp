#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
public:
    // 代码思路：
    // 1. 取 cur 节点为所要交换两节点的前一节点
    // 2. 对要交换节点进行拉直展开：0->2 2->1 1->3
    // 3. 存储节点为中间节点，注意解序重点操作理解
    ListNode* swapPairs(ListNode* head){
        ListNode* _dummyHead = new ListNode(0, head);
        ListNode* cur = _dummyHead;

        while(cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            temp->next = cur->next->next;   // 交换解序重点理解
            cur->next->next = temp;

            cur = cur->next->next;
        }

        ListNode* result = _dummyHead->next;
        delete _dummyHead;
        return result;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution solution;
    head = solution.swapPairs(head);

    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}