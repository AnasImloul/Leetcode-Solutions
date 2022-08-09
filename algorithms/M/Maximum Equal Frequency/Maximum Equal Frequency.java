import java.util.TreeMap;
import java.util.NavigableMap;
class Solution {
    public int maxEqualFreq(int[] nums) {
        Map<Integer, Integer> F          = new HashMap<>(); //Frequencies
        NavigableMap<Integer, Integer> V = new TreeMap<>(); //Values for frequencies
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            increaseCount(F, nums[i]);
            int frequency = F.get(nums[i]);
            decreaseCount(V, frequency - 1);
            increaseCount(V, frequency);
            if (isPossibleToRemove(V)) max = i;
        }
        return max + 1;
    }
    
    public boolean isPossibleToRemove(NavigableMap<Integer, Integer> frequenciesMap) {
        if (frequenciesMap.size() > 2) return false; //more than 2 different frequencies
        Map.Entry<Integer, Integer> first = frequenciesMap.firstEntry();
        Map.Entry<Integer, Integer> last  = frequenciesMap.lastEntry();
        if (frequenciesMap.size() == 1) return first.getKey() == 1 || first.getValue() == 1; //should be [a,a,a,a] or [a,b,c,d]
        int firstReduced = removeElement(first);
        int lastReduced  = removeElement(last);
        if (firstReduced > 0 && lastReduced > 0 && first.getKey() != lastReduced) return false;
        return true;
    }
    
    //Try to remove element which contributes to this frequency:
    //if there's only 1 occurence of such frequency, the frequency itself will become smaller by 1
    //if there are more than 1 occurences of such frequency, removing 1 element will not change it
    public int removeElement(Map.Entry<Integer, Integer> frequencyValue) {
        if (frequencyValue.getValue() == 1) return frequencyValue.getKey() - 1;
        return frequencyValue.getKey();
    }
    
    public void decreaseCount(Map<Integer, Integer> map, int element) {
        if (!map.containsKey(element)) return;
        map.put(element, map.get(element) - 1);
        if (map.get(element) == 0) map.remove(element);
    }
    
    public void increaseCount(Map<Integer, Integer> map, int element) {
        if (!map.containsKey(element)) map.put(element, 0);
        map.put(element, map.get(element) + 1);
    }
}
