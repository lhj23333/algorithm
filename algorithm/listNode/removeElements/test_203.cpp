#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // title：移除链表元素
    // 思路_1: 暴力拆解法分两步处理
    //       1. 对头节点进行循环判断，delete head->val (注意使用 while 循环，防止出现连续头节点 head-> val == val 情况)
    //       2. 对单向链接节点进行判断，采取优先判断滞后节点的思路，从 head 节点开始进行判断
    //          当 cur 节点的 next 节点 val == val 时，cur 节点的 next 节点指向 next->next
    //          当 cur 节点的 next 节点 val == val 时，cur 节点进行迭代
    ListNode* removeElements(ListNode* head, int val)
    {
        while(head != NULL && head->val == val)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;    // c++ 注意释放节点内存
        }

        ListNode* curListNode = head; 
        while(curListNode != NULL && curListNode->next != NULL)
        {
            if(curListNode->next->val == val)
            {
                ListNode* temp = curListNode->next;
                curListNode->next = curListNode->next->next;
                delete temp;
            }
            else
            {
                curListNode = curListNode->next;
            }
        }
        
        return head;
    }

    // 思路_2：虚拟头节点方法
    // scription：创建新的节点(虚拟节点)作为原链表节点头节点，使得暴力拆解两步合并
    ListNode* removeElements(ListNode* head, int val)
    {
        // 创建虚拟头节点
        ListNode* dummyHead = new ListNode(0, head);

        ListNode* curListNode = dummyHead;
        while(curListNode != NULL && curListNode->next != NULL)
        {
            if(curListNode->next->val == val)
            {
                ListNode* temp = curListNode->next;
                curListNode->next = curListNode->next->next;
                delete temp;
            }
            else
            {
                curListNode = curListNode->next;
            }
        }
        
        // 删除 dummyHead
        head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};

int main()
{
    Solution solut;

    ListNode* node6 = new ListNode(6);
    ListNode* node5 = new ListNode(5, node6);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(6, node3);
    ListNode* node1 = new ListNode(2, node2);
    ListNode* node0 = new ListNode(1, node1);
    int val = 6;

    ListNode* cur = solut.removeElements(node0, val);
    for(cur; cur != NULL; cur = cur->next)
    {
        cout << cur->val << " ";
    }
    cout << endl;

    return 0;
}