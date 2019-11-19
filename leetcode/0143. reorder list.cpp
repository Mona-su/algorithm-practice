/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// time: 34.52% O(N), space: 12.91 O(N)
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> list;
        ListNode* temp = head;
        int length = 1;
        
        if (head == NULL){
            return;
        }
        
        // put all nodes into the vector container
        while (temp->next != NULL){
            list.push_back(temp);
            temp = temp->next;
            length++;
        }
        list.push_back(temp);
        
        for (int i = 0; i < length/2; i++){
            list[i]->next = list[length-1-i];
            list[length-1-i]->next = list[i+1];
        }
        
        list[length/2]->next = NULL;
        
        head = list[0];
    }
};


// another soluction
// time: 80.04% O(n), space: 71.43 O(1)
// idea: reverse the second half of the linked list
// then change the next pointer one by one (from both ends)
class Solution {
public:
    void reorderList(ListNode* head) {
        // count list length
        int length = 0;
        ListNode * temp = head;
        while (temp != NULL){
            length++;
            temp = temp -> next;
        }
        
        if (length > 2){
            int halfLen = length/2;
            ListNode *halfNode = NULL, *reversedHead = NULL;
            
            // find the middle node
            temp = head;
            for (int i = 0; i < halfLen; i++){
                temp = temp -> next;    
            }
            
            reversedHead = reverseList (temp);
            
            temp = head;
            ListNode *reversedNext = reversedHead -> next, *next = temp -> next;
            for (int i = 0; i < halfLen; i++){
                temp -> next = reversedHead;
                reversedHead -> next = next;
                reversedHead = reversedNext;
                reversedNext = reversedHead -> next;
                temp = next;
                next = temp -> next;
            }
            temp -> next = NULL;
        }
    }
    
    
    ListNode* reverseList(ListNode* head){
        ListNode *currNode = head -> next, *nextNode, *prevNode = head;
        
        while (currNode -> next != NULL){
            nextNode = currNode -> next;
            currNode -> next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        currNode -> next = prevNode;
        
        return currNode;
    }
};
