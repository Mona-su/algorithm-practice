// 23 merge k sorted list.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Idea: use devide and conquer on the lists
 * time complexity: suppose m = lists.size() and n = number of ints in one list
 * O(mn) ?
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists (lists, 0, lists.size());
    }
    
    ListNode* mergeLists (vector<ListNode*>& lists, int start, int end){
        int length = end - start;
        
        if (length == 0){
            return NULL;
        }
        else if (length == 1){
            return lists[start];
        }
        else {
            int half = (start + end) / 2;
            ListNode* left = mergeLists(lists, start, half);
            ListNode* right = mergeLists(lists, half, end);
            return Merge2Lists (left, right);
        }
    }

    ListNode* Merge2Lists (ListNode* left, ListNode* right){
    	// head point to the head of the sorted list
    	// pre point to the last node of the sorted list
    	ListNode* head, *pre;
        
        if (left == NULL && right == NULL){
            return NULL;
        }
        else if (left == NULL && right != NULL){
            return right;
        }
        else if (left != NULL && right == NULL){
            return left;
        }

    	if (left->val <= right->val) {
    		head = left;
    		pre = left;
    		left = left->next;
    	}
    	else {
    		head = right;
    		pre = right;
    		right = right->next;
    	}

    	ListNode* newLast = head;
    	
    	while (left != NULL && right != NULL) {
    		if (left->val <= right->val){
    			pre->next = left;
    			pre = pre->next;
    			left = left->next;
    		}
    		else {
    			pre->next = right;
    			pre = pre->next;
    			right = right->next;
    		}
    	}

    	pre->next = (left == NULL) ? right : left;
        return head;
    }
};