// Runtime: 114 ms (Top 5.75%) | Memory: 89.00 MB (Top 5.75%)

class Solution {
    public long[] distance(int[] nums) {
        long ans[]=new long[nums.length];
        int arr[][]=new int[nums.length][2];
        for(int i=0;i<nums.length;i++){
            arr[i][0]=nums[i];
            arr[i][1]=i;
        }
        Arrays.sort(arr,(a,b)->a[0]==b[0]?a[1]-b[1]:a[0]-b[0]);
        HashMap<Integer,List<Integer>> h=new HashMap<>();
         HashMap<Integer,Long> h1=new HashMap<>();
        long s=0;
        for(int i=0;i<nums.length;i++){
            if(h.containsKey(arr[i][0])){
                s+=1L*arr[i][1];
                h1.put(arr[i][1],s);
            }else{
                s=arr[i][1];
                h1.put(arr[i][1],s);
            }
             h.putIfAbsent(arr[i][0],new ArrayList<>());
            h.get(arr[i][0]).add(arr[i][1]);
        }
        for(int i=0;i<nums.length;i++){
            if(h.get(nums[i]).size()==1){
                ans[i]=0;
            }else{
                List<Integer> l1=h.get(nums[i]);
                int ind=Collections.binarySearch(l1,i);
                long leftSum=1L*(h1.get(i).longValue()-i);
                long rightSum=1L*(h1.get(l1.get(l1.size()-1)).longValue()-leftSum-i);
                long x=1L*(ind)*i-leftSum-1L*(l1.size()-ind-1)*i+rightSum;
                ans[i]=x;
            }
        }
        return ans;
    }
}
