class Solution {
    HashMap<Character,Integer[]> pos;
    int [][][]memo;
    int type(String word,int index,char finger1,char finger2){
        if (index==word.length()) return 0;
        int ans=9999999;
        if (memo[index][finger1-'A'][finger2-'A']!=-1) return memo[index][finger1-'A'][finger2-'A'];
        if (finger1=='['){
            
            ans=Math.min(ans,type(word,index+1,word.charAt(index),finger2));
        }
        else{
            
            Integer [] prev=pos.get(finger1);
            Integer [] curr=pos.get(word.charAt(index));
            int dist=Math.abs(prev[0]-curr[0])+Math.abs(prev[1]-curr[1]);
            ans=Math.min(ans,type(word,index+1,word.charAt(index),finger2)+dist);
        }
        if (finger2=='['){
            ans=Math.min(ans,type(word,index+1,finger1,word.charAt(index)));
        }
        else{
            Integer [] prev=pos.get(finger2);
            Integer [] curr=pos.get(word.charAt(index));
            int dist=Math.abs(prev[0]-curr[0])+Math.abs(prev[1]-curr[1]);
            ans=Math.min(ans,type(word,index+1,finger1,word.charAt(index))+dist);
        }
        memo[index][finger1-'A'][finger2-'A']=ans;
        return ans;
    }
    public int minimumDistance(String word) {
        pos=new HashMap();
        for (int i=0;i<26;i++){
            Integer [] coord={i/6,i%6};
            pos.put((char)('A'+i),coord);
        }
        memo=new int [word.length()]['z'-'a'+3]['z'-'a'+3];
        for (int[][] row : memo) {
            for (int[] rowColumn : row) {
                Arrays.fill(rowColumn, -1);
            }
        }
        return  type(word,0,'[','[');
        }
}