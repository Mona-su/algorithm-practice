// 147 Insertion Sort List.java

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode sortedHead = new ListNode (0), sortedLast = head, itr = head.next, temp, dummy;
        sortedHead.next = head;
        Boolean inserted = false;

        while (itr != null) {
        	for (temp = sortedHead; temp != sortedLast; temp = temp.next) {
        		inserted = false;
        		if (itr.val >= temp.next.val) {
        			dummy = itr.next;
        			itr.next = temp.next;
        			temp.next = itr;
        			itr = dummy;
        			inserted = true;
        			break;
        		}
        	}
        	if (!inserted) {
        		dummy = itr.next;
    			itr.next = sortedHead.next;
    			sortedHead.next = itr;
    			itr = dummy;
        	}
        }
        return sortedHead.next;
    }
}