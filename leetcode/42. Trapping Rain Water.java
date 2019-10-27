// 42 Trapping Rain Water.java

// not a good solution
// time: O(n^2), space: O(n)
class Solution {
    public int trap(int[] height) {
        int length = height.length;
        if (length < 3) {
        	return 0;
        }

        Set <Integer> minHeap = new TreeSet <Integer> ();
        int ans = 0, currHeight = 0, prevHeight, poolFirst = length, poolLen = 0;

        for (int i = 0; i < length; i++) {
            minHeap.add (height[i]);
        }
        Iterator itr = minHeap.iterator();
        Integer next = (Integer) itr.next();
        prevHeight = (next).intValue();
        
        minHeap.remove(next);
        for(Integer value : minHeap) {
            currHeight = value.intValue();
            
            for (int i = 0; i < length; i++) {
                if (height[i] > prevHeight) {
                    ans += poolLen * (currHeight - prevHeight);
                    poolLen = 0;
                    poolFirst = i;
                } 
                else {
                    if (i > poolFirst) {
                        poolLen = i - poolFirst;
                    }
                }
            }

            prevHeight = currHeight;
            poolFirst = length;
            poolLen = 0;
        }
        return ans;
    }
}

// much better solution
// time: O(n), space: O(1)
class Solution {
    public int trap(int[] height) {
        int ans = 0, length = height.length;

        if (length > 2){
        	int max = height[0], maxIndex = 0;

        	for (int i = 1; i < length; i++) {
        		if (height[i] > max) {
        			max = height[i];
        			maxIndex = i;
        		}
        	}
        	
        	int localMax = height[0];

        	for (int i = 0; i < maxIndex; i++) {
        		if (height[i] > localMax) {
        			localMax = height[i];
        		}
        		else {
        			ans += localMax - height[i];
        		}
        	}

        	localMax = height[length-1];
        	for (int i = length - 2; i > maxIndex; i--) {
        		if (height[i] > localMax) {
        			localMax = height[i];
        		}
        		else {
        			ans += localMax - height[i];
        		}
        	}
        }

        return ans;
    }
}