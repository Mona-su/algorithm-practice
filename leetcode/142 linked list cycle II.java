// 142 linked list cycle II.java

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

// not a very good solution (time complexity a bit high)
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode meetNode = checkCycle (head);
        
        if (meetNode == null){
            return null;
        }
        
        int cycleLen = 0;
        ListNode check = meetNode;
        while (check.next != meetNode){
        	check = check.next;
        	cycleLen++;
        }
        cycleLen++;

        ListNode ans = head;
        check = ans;
        while (ans != meetNode.next) {
        	for (int i = 0; i < cycleLen; i++){
	        	 check = check.next;
	        	 
	        }
	        if (check == ans) {
        	 	break;
        	 }
	        ans = ans.next;
	        check = ans;
        }

        return ans;
        
    }
    
    private ListNode checkCycle(ListNode head){
    	if (head == null){
    		return null;
    	}

    	ListNode slow = head, fast = head, ans = null;

    	while (slow.next != null && fast.next != null && fast.next.next != null){
    		slow = slow.next;
    		fast = fast.next.next;
    		if (slow == fast){
    			ans = slow;
    			break;
    		}
    	}

    	return ans;
    }
}


// a better solution
// update the find cycle part
// detect cycle still use Floyd's cycle detection method
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode meetNode = checkCycle (head);
        
        if (meetNode == null){
            return null;
        }
        
        int cycleLen = 0;
        ListNode check = meetNode, ans = head;
        while (check.next != meetNode){
        	check = check.next;
        	cycleLen++;
        }
        cycleLen++;

        check = head;
        for (int i = 0; i < cycleLen; i++){
            check = check.next;
        }
        while (ans != check){
            ans = ans.next;
            check = check.next;
        }
        

        return ans;
        
    }
    
    private ListNode checkCycle(ListNode head){
    	if (head == null){
    		return null;
    	}

    	ListNode slow = head, fast = head, ans = null;

    	while (slow.next != null && fast.next != null && fast.next.next != null){
    		slow = slow.next;
    		fast = fast.next.next;
    		if (slow == fast){
    			ans = slow;
    			break;
    		}
    	}

    	return ans;
    }
}