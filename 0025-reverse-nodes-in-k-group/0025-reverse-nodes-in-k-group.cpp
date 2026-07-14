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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Step 1: Check if k nodes exist
        ListNode* temp = head;
        int cnt = 0;

        while (temp && cnt < k) {
            temp = temp->next;
            cnt++;
        }

        // If less than k nodes, don't reverse
        if (cnt < k)
            return head;

        // Step 2: Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        cnt = 0;

        while (curr && cnt < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        // Step 3: Connect remaining list
        head->next = reverseKGroup(curr, k);

        // Step 4: Return new head
        return prev;
    }
};