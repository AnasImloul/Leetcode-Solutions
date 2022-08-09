class Solution {
    public int[] advantageCount(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->(b[0]-a[0]));
        for(int i=0;i<nums2.length;i++) pq.add(new int[]{nums2[i],i});
        int left=0, right=nums1.length-1;
        while(left<=right){
            int[] get=pq.poll();
            int pos=get[1], max=get[0];
            if(nums1[right]>max){
                nums2[pos]=nums1[right];
                right--;
            }else{
                nums2[pos]=nums1[left];
                left++;
            }
        }
        return nums2;
    }
}
