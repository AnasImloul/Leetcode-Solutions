Let us understand question first
Question is saying wherever you are finding continous elements then keep them in an interval
else keep them alone

EX->  [0,1,2,4,5,7]
[0,1,2]-->[0->2] {2-4 in array is breakpoint}
[4,5]  -->[4->5]
[7]    -->[7]

Approach

Traverse the entire array
1.keep start at every element and check whether i doesnt reached end and the ith element added with 1 gives the next element. If so then keep travelling ahead by incrementing i until you find a breakpoint
2. Once you find a breakpoint where nums[i]+1!=nums[i+1],so at that time check whether nums[i]!=start,if so add it to list start+"->"+nums[i]
3. else add just the start 

Time Compl-> 0(N)
Space -> 0(1)
    
    
-------------------------------------------------------------------------
class Solution {
    public List<String> summaryRanges(int[] nums) {
       ArrayList<String> al=new ArrayList<>();
        
        for(int i=0;i<nums.length;i++){
            int start=nums[i];
            while(i+1<nums.length && nums[i]+1==nums[i+1])
                i++;
            
            if(start!=nums[i]){
                al.add(""+start+"->"+nums[i]);
            }
            else{
                al.add(""+start);
            }
        }
        return al;
    }
}
