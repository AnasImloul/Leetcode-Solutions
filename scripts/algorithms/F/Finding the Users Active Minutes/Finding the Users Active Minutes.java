// Runtime: 18 ms (Top 74.46%) | Memory: 56.30 MB (Top 38.32%)

class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        // create a hashmap to record the ids of users 
        // and a set to store the minutes in which they were active
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int[] l : logs) {
            // l[0] -> id, l[1] -> active minute
            map.putIfAbsent(l[0], new HashSet<>()); // if new id
            map.get(l[0]).add(l[1]);  // add the minute of activeness to the set
        }

        // create answer array
        int[] ans = new int[k];     
        for (int id : map.keySet()) {
            // the set contains all the minutes in which the id was active
            // so the set size will be the number of active minutes
            // or the 'User Active Minutes' (UAM)
            int uam = map.get(id).size();
            // each index in ans array is a UAM, 
            // and we need to put the number of users having that UAM
            // whenever we enocunter a UAM, we increment the value in array
            // which means we have found one more user with the same UAM
            ans[uam-1]++;  // since array is 1 based indexing, we substract 1
        }

        return ans;     // return ans array
    }
}
