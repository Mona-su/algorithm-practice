// 2. Add Two Numbers

// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order and each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// go over once
// time: O(n), space: O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(-1), *curr = head;
        while (l1 != NULL || l2 != NULL) {
            int num = ((l1 == NULL) ? 0 : l1->val) + ((l2 == NULL) ? 0 : l2->val) + carry;
            carry = 0;
            if (num >= 10) {
                carry = num / 10;
                num = num % 10;
            }
            curr->next = new ListNode(num);
            curr = curr->next;
            l1 = (l1 == NULL) ? NULL : l1->next;
            l2 = (l2 == NULL) ? NULL : l2->next;
        }
        if (carry > 0)
            curr->next = new ListNode(carry);
        return head->next;
    }
};

// solution 2
// same idea, different coding
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *answer;
        ListNode *temp;
        
        int carry = 0, addition = 0;
        
        addition = l1->val + l2->val;
        
        temp = new ListNode (addition % 10);
        carry = addition / 10;
        
        answer = temp;
        
        l1 = l1->next;
        l2 = l2->next;
        
        while (l1 != NULL or l2 != NULL){
            
            addition = carry;
            if (l1 != NULL){
                addition += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL){
                addition += l2->val;
                l2 = l2->next;
            }
            
            temp->next = new ListNode(addition % 10);
            carry = addition / 10;
            
            
            temp = temp -> next;
        }
        
        if (carry > 0){
            temp->next = new ListNode(carry);
        }
        
        return answer;
    }
};