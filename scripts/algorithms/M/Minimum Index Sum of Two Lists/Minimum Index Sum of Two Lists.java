// Runtime: 7 ms (Top 93.08%) | Memory: 45.40 MB (Top 19.13%)

class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        if (list1.length > list2.length) {
            return findRestaurant(list2, list1);
        }
        
        Map<String, Integer> map1 = new HashMap<>();
        for (int i = 0; i < list1.length; i++) {
            map1.put(list1[i], i);
        }
        
        List<String> mins = new ArrayList<>();
        int minSum = Integer.MAX_VALUE;
        for (int i = 0; i < list2.length; i++) {
            String rest2 = list2[i];
            if (map1.containsKey(rest2)) {
                int sum = map1.get(rest2) + i;
                if (sum < minSum) {
                    mins = new ArrayList<>();
                    minSum = sum;
                }
                if (sum == minSum) {
                    mins.add(rest2);
                }
            }
        }
        
        return mins.toArray(new String[mins.size()]);
    }
}
