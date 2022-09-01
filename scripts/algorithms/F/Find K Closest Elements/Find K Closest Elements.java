// Runtime: 13 ms (Top 41.96%) | Memory: 62.2 MB (Top 71.32%)
class Solution {
public List<Integer> findClosestElements(int[] arr, int k, int x) {
    List<Integer> result = new ArrayList<>();

    int low = 0, high = arr.length -1;

    while(high - low >= k){
        if(Math.abs(arr[low] - x) > Math.abs(arr[high] - x))
            low++;
        else
            high--;
    }

    for(int i = low; i <= high; i++)
        result.add(arr[i]);

    return result;
}
}