// Runtime: 321 ms (Top 35.18%) | Memory: 117.7 MB (Top 29.49%)
class Solution {
public int numSubmatrixSumTarget(int[][] matrix, int target) {
    int m = matrix.length, n = matrix[0].length;

    int[] summedArray = new int[n];
    int ans = 0;
    for(int i = 0; i < m; i++){ //starting row
        Arrays.fill(summedArray, 0);
        for(int j = i; j < m; j++){ //ending row
            for(int k = 0; k < n; k++){ // column
                summedArray[k] += matrix[j][k];
            }
            ans += subarraySum(summedArray, target);
        }
    }
    return ans;
}

 public int subarraySum(int[] nums, int k) {
    //map<sum, freq>
    Map<Integer, Integer> map = new HashMap<>();
    int count = 0;
    map.put(0,1);
    int sum = 0;
    for(int num : nums){
        sum += num;
        int diff = sum - k;
        if(map.containsKey(diff)){
            count += map.get(diff);
        }
        map.put(sum, map.getOrDefault(sum, 0) + 1);
    }
    return count;
}
}