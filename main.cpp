/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *parentNode = nullptr;
        ListNode *addNode = nullptr;
        int carry = 0;
        bool addNumbers = true;
        
        while(addNumbers) {
            int e1 = 0;
            int e2 = 0;
            
            if (l1 != nullptr) {
                e1 = l1->val;
                l1 = l1 ->next;
            }
            
            if (l2 != nullptr) {
                e2 = l2->val;
                l2 = l2 ->next;
            }            
            
            int sum = e1 + e2 + carry;
            
            carry = 0;
            
            carry = sum / 10;
            sum = sum % 10;

            ListNode *childNode = new ListNode(sum);
            
            if (parentNode == nullptr) {
                parentNode = childNode;
                addNode = parentNode;
            }
            else {
                addNode->next = childNode;
                addNode = childNode;
            }

            if (l1 == nullptr && l2 == nullptr && carry == 0) {
                addNumbers = false;
            }
        }
        
        return parentNode;
    }
};
