/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode* last = head;
        int n = 1;

        while (last->next != NULL) {
            last = last->next;
            n++;
        }

        k = k % n;

        if (k == 0)
            return head;

        // Make circular list
        last->next = head;

        ListNode* t = head;
        int count = 1;

        while (count < n - k) {
            t = t->next;
            count++;
        }

        ListNode* res = t->next;
        t->next = NULL;

        return res;
    }
};