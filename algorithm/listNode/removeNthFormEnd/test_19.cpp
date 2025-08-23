#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* _dummyHead = new ListNode(0, head);
        ListNode* fast = _dummyHead;
        ListNode* slow = _dummyHead;
        
        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        while(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

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
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    head = solution.removeNthFromEnd(head, 2);

    ListNode* node = head;
    while(node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}