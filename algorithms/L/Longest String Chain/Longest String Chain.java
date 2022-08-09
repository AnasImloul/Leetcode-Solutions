class Solution {
    
    Boolean compareForIncreaseByOne(String str1,String str2){
            //str 1 will be long than str2
        int first=0;
        int second=0;
        if(str1.length() != (str2.length() + 1)){
            return false;
        }
        while(first < str1.length()){
            if(second < str2.length() && str1.charAt(first) == str2.charAt(second)){
                first++;
                second++;
            }else{
                first++;
            }
        }
        if(first == str1.length() && second == str2.length()){
            return true;
        }
        return false;
    }
    
    public int longestStrChain(String[] words) {
        int N = words.length;
        Arrays.sort(words,(a,b) -> a.length()-b.length());  //as Sequence/Subset are not ordered
        int []dp =new int[N];
        Arrays.fill(dp,1);
        int maxi = 1;
        for(int i=0;i<N;i++){
            for(int j=0;j<i;j++){
                if(compareForIncreaseByOne(words[i],words[j]) && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    maxi = Math.max(maxi,dp[i]);
                }
            }
        }//for neds
        return maxi;
    }
}
