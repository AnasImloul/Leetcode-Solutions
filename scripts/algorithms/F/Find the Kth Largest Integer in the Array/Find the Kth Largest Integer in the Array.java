// Runtime: 107 ms (Top 27.4%) | Memory: 53.91 MB (Top 31.3%)

class Solution {
    public String kthLargestNumber(String[] nums, int k) {
        
        int n=nums.length;
        
        Arrays.sort(nums,(a,b)->{
            if(a.length()>b.length()) return 1;
            else if(b.length()>a.length()) return -1;
            else{
              return isgreater(a,b);   
            }
        });
        return nums[n-k];        
    }
    
    public static int isgreater(String a,String b){
        
        int n=a.length();
        
        for(int i=0;i<n;i++){
            int a1=Integer.parseInt(""+a.charAt(i));
            int b1=Integer.parseInt(""+b.charAt(i));
            if(a1>b1) return 1;
            if(b1>a1) return -1;
        }
        return 0;
    }
}