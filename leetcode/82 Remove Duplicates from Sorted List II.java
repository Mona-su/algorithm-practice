// 82 Remove Duplicates from Sorted List II.java

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
        	return head;
        }

        ListNode itr = head.next, prev = new ListNode(0), temp = prev;
        int number = head.val;
        prev.next = head;
        head = prev;

        while (itr != null) {
        	if (itr.val != number) {
        		temp = prev;
        		number = itr.value;
        		prev.next = itr;
        		prev = prev.next;
        	}
        	else {
        		prev = temp;
        	}
        	itr = itr.next;
        }
        prev.next = null;

        return head.next;
    }
}