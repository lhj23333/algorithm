#include <iostream>

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
    // 思路：快慢双指针
    // 1. 是否存在环: 
    // 当存在链表存在环时，则当快指针以 2 单位节点移动，慢指针以单位节点速度，则两指针一定会在慢指针完成第一圈前相遇
    // 2. 入口点: 
    // 通过模型分析可得，当两指针相遇时，慢指针走了 k 步，则快指针走了 2k 步
    // 设链表头到环入口点距离为 a，环入口点到相遇点距离为 b，相遇点到环入口点距离为 c
    // 则有：2k - k = a + b + n(b + c)，其中 n 为快指针在环中走的圈数
    // 化简得：a = (n - 1)(b + c) + c
    // 则说明，当一节点从相遇点开始，一节点从链表头开始，以单位节点速度移动，则两节点一定会在环入口点相遇
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
            {
                ListNode *ptr = head;
                while(ptr != slow)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next;

    Solution solut;
    ListNode* res = solut.detectCycle(head);
    if(res != nullptr){
        cout << res->val << endl;
    }
    else{
        cout << "no cycle" << endl;
    }

    return 0;
}