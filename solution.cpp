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
        ListNode* output = new ListNode(0);
        ListNode* head = output;

        ListNode* index1;
        ListNode* index2;
        index1 = l1;
        index2 = l2;

        int val = 0;
        int carry = 0;
        while ((index1 != nullptr) || (index2 != nullptr)) {
            int x = (index1 != nullptr) ? index1->val : 0;
            int y = (index2 != nullptr) ? index2->val : 0;
            val = x + y + carry;
            carry = val / 10;
            val = val % 10;
            head->next = new ListNode(val);
            head = head->next;
            if (index1 != nullptr)
                index1 = index1->next;
            if (index2 != nullptr)
                index2 = index2->next;
        }
        if (carry > 0)
            head->next = new ListNode(carry);
        head = head->next;
        ListNode* result = output->next;
        delete output;
        return result;
    }
};
