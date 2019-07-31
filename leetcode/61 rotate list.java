// 61 rotate list.java

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0){
        	return head;
        }

        ListNode first = head, last = head, ans;
        int length = 0;

        while (last.next != null){
        	length++;
        	k--;
        	if (k < 0) {
        		first = first.next;
        	}
        	last = last.next;
        }
        length++;
        k--;

        if (k >= 0) {
	        int newK = k % length;
	        ans = rotateRight(head, newK);
	    }
	    else {
		    last.next = head;
		    ans = first.next;
		    first.next = null;
		}

	    return ans;
    }
}