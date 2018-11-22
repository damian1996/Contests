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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0, len2 = 0;
        for(ListNode* temp = l1; temp != nullptr; temp = temp->next) len1++;
        for(ListNode* temp = l2; temp != nullptr; temp = temp->next) len2++;
        int mini = min(len1, len2);
        int transfer = 0;
        ListNode* res = new ListNode(0);
        ListNode* nextToInsert = res;
        for(int i = 0; i < mini; i++) {
             nextToInsert->val = (l1->val + l2->val + transfer) % 10;
             transfer = (l1->val + l2->val + transfer)/10;
             l1 = l1->next;
             l2 = l2->next;
             if(i == (mini-1)) {
                 if(len1 != len2) {
                     nextToInsert->next = new ListNode(0);
                     nextToInsert = nextToInsert->next; 
                 }
             } else {
                 nextToInsert->next = new ListNode(0);
                 nextToInsert = nextToInsert->next; 
             }
        }
        int maxi = max(len1, len2);
        for(int i = mini; i < maxi; i++) {
            if(len1 < len2) {
                nextToInsert->val = (l2->val + transfer)%10;
                transfer = (l2->val + transfer) / 10;
                l2 = l2->next;
            } else {
                nextToInsert->val = (l1->val + transfer)%10;
                transfer = (l1->val + transfer) / 10;
                l1 = l1->next;
            }
            if(i != (maxi - 1)) {
                 nextToInsert->next = new ListNode(0);
                 nextToInsert = nextToInsert->next;   
            }
        }
        if(transfer) {
            nextToInsert->next = new ListNode(transfer);
        }
        
        return res;
    }
};
