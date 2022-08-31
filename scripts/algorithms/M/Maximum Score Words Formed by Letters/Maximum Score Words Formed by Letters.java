// Runtime: 10 ms (Top 32.14%) | Memory: 44.3 MB (Top 16.39%)
class Solution {
    int[] memo;
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        memo = new int[words.length];
        Arrays.fill(memo,-1);
        HashMap<Character,Integer> hm = new HashMap<>();
        for(char c : letters){
            int t = hm.getOrDefault(c,0);
            t++;
            hm.put(c,t);
        }
        //return dp(words,hm,score,0,0);
        int res = dp(words,hm,score,0,0);
        //for(int i : memo) System.out.println(i);
        return res;
    }

    public int dp(String[] words, Map<Character,Integer> hm, int[] score, int index, int cs){//cs-current Score
        if(index==words.length) return cs;
        if(memo[index]!=-1) return memo[index];
        HashMap<Character,Integer> temp = new HashMap<>(hm);
        int tcs=cs; //tcs = temporory current score

        for(char c : words[index].toCharArray()){
            int t = temp.getOrDefault(c,0);
            t--;
            if(t<0){
                return dp(words,hm,score,index+1,cs);
                // memo[index] = dp(words,hm,score,index+1,cs);
                // return memo[index];
            }
            tcs+=score[c-'a'];
            temp.put(c,t);
        }
        return Math.max(dp(words,hm,score,index+1,cs),dp(words,temp,score,index+1,tcs));
        // memo[index] = Math.max(dp(words,hm,score,index+1,cs),dp(words,temp,score,index+1,tcs));
        // return memo[index];
    }
}