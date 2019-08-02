// 456 132 Pattern.java

// not the best solution
// time complexity could be reduced to O(n)
// but i don't know how...
class Solution {
    public boolean find132pattern(int[] nums) {
        int length = nums.length;
        if (length < 3) return false;

        // the index of the minimum number from 0 to i
        int[] minLeft = new int[length];

        minLeft[0] = 0;
        int min = nums[0];

        for (int i = 1; i < length; i++) {
        	if (nums[i] <= min) {
        		minLeft[i] = i;
        		min = nums[i];
        	}
        	else {
        		minLeft[i] = minLeft[i-1];
        	}
        }

        List<Integer> possibleRight = new ArrayList <Integer>();

        for (int i = length - 1; i >= 0; i--) {
        	if (minLeft[i] == i) { // can't be right or middle
        		continue;
        	}
        	else {
        		if (possibleRight.size() == 0 || nums[i] < possibleRight.get(0)) {
        			possibleRight.add (nums[i]);
        		}
        		
                for (int j = 0; j < possibleRight.size(); j++) {
                    if (nums[i] > possibleRight.get(j) && nums[minLeft[i]] < possibleRight.get(j)) {
                        return true;
                    }
                    else if (nums[minLeft[i]] >= possibleRight.get(j)) {
                        possibleRight.remove(j);
                        j--;
                    }
                }
        		
        	}
        }

        return false;
    }
}