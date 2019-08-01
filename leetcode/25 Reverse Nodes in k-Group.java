// 25 Reverse Nodes in k-Group.java

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
// not a very good solution
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k < 2 || head.next == null){
        	return head;
        }

        ListNode ans = head, itr = head, tail, tailPrev = head, dummy;
        int tempK = k - 1, reverseCount = 0;
        
        while (itr != null) {
            if (tempK > 0) {
        		itr = itr.next;
                tempK--;
        	}
        	else {
        		tail = itr;
        		itr = itr.next;
        		reverseCount++;
        		reverseGroup (head, tail);
                dummy = head;
                head = tail;
                tail = dummy;
        		if (reverseCount == 1) {
        			ans = head;
        			tailPrev = tail;
        		}
        		else {
        			tailPrev.next = head;
        			tailPrev = tail;
        		}
        		tempK = k - 1;	        		
	        	head = itr;
        	}
        }
        if (reverseCount > 0)   tailPrev.next = head;
        
        return ans;
    }

    private void reverseGroup (ListNode head, ListNode tail) {
    	ListNode prev = head, curr = head.next, next;

    	while (curr != tail) {
    		next = curr.next;
    		curr.next = prev;
    		prev = curr;
    		curr = next;
    	}

    	curr.next = prev;
    	tail = head;
    	head = curr;
    }
}
