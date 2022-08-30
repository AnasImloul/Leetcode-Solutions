// Runtime: 20 ms (Top 69.34%) | Memory: 54.7 MB (Top 58.44%)
class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>(); // create 2 hashsets
        Set<Integer> set2 = new HashSet<>();
        for(int num : nums1){ set1.add(num); } // add nums1 elements to set1
        for(int num : nums2){ set2.add(num); } // add nums2 elements to set2

        List<List<Integer>> resultList = new ArrayList<>(); // Initialize result list with 2 empty sublists that we will return
        resultList.add(new ArrayList<>());
        resultList.add(new ArrayList<>());

        for(int num : set1){ // just iterate to all elements of set1
            if(!set2.contains(num)){ resultList.get(0).add(num); } // add those elements to first sublist of result list, which are not in set2.
        }
        for(int num : set2){ // just iterate to all elements of set2
            if(!set1.contains(num)){ resultList.get(1).add(num); } // add those elements to first sublist of result list, which are not in set1
        }
        return resultList;
    }
}