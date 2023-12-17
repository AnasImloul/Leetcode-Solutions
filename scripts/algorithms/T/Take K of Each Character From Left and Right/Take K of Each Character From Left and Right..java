// Runtime: 15 ms (Top 40.79%) | Memory: 44.60 MB (Top 31.58%)

class Solution {
    public boolean valid(int arr[],int k){
         if(arr[0]<k || arr[1]<k || arr[2] < k) return false;
         return true;
    }
    public int takeCharacters(String s, int k) {
        int arr[]=new int[3];
        for(int i=0;i<s.length();i++){
            arr[s.charAt(i)-'a']++;
        }
        if(arr[0]<k || arr[1]<k || arr[2]<k) return -1;
        int i = s.length()-1;
        int j = s.length()-1;
        int sum = arr[0] + arr[1] + arr[2];
        int mini = Integer.MAX_VALUE;
        while(i>=0 && j>=0){
            arr[s.charAt(i)-'a']--;
            i--;
            while(!valid(arr,k)&& j>=0){
                    arr[s.charAt(j)-'a']++;
                    j--;
                    
            }
            sum=arr[0]+arr[1]+arr[2];
            mini=Math.min(sum,mini);
        }
        return mini;
    }
}
