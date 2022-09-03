// Runtime: 4 ms (Top 43.75%) | Memory: 48.2 MB (Top 87.50%)
class Solution {
    public int[] threeEqualParts(int[] arr) {
        List<Integer> ones = new ArrayList<>();
        for (int i = 0; i < arr.length; i++){
            if (arr[i]==1){
                ones.add(i);
            }
        }
        if (ones.size()==0){ // edge case
            return new int[]{0,2};
        }
        int[] ans = new int[2];
        int each = ones.size()/3;
        for (int i = 0; i < 2 && ones.size()%3==0; i++){ // for the first 2 partitions
            for (int j = 0; j < each-1; j++){ // compare gaps
                if (ones.get(j+1+i*each)-ones.get(j+i*each)!=ones.get(j+2*each+1)-ones.get(j+2*each))
                    return new int[]{-1, -1};
            }
            ans[i]=ones.get((i+1)*each-1)+i+(arr.length - 1 - ones.get(ones.size()-1)); // cut point
        }
        return ones.size()%3>0||ans[0]>=ones.get(each)||ans[1]>ones.get(2*each)?
            new int[]{-1, -1} : ans;
    }
}