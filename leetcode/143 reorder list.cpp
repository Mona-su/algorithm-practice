/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// time: 34.52%, space: 12.91
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