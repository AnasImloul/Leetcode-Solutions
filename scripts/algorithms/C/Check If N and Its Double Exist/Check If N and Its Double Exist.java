// Runtime: 2 ms (Top 76.57%) | Memory: 42.30 MB (Top 45.56%)

class Solution {
    public boolean checkIfExist(int[] arr) {
	    int n = arr.length;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (i != j && arr[i] == 2 * arr[j]) 
                    return true;

        return false;
    }
}

// TC: O(n ^ 2), SC: O(1)
