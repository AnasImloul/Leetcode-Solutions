class Solution {
    public int minDeletionSize(String[] strs) {
       boolean[] sorted = new boolean[strs.length];
        int res = 0;
        for(int i = 0;i<strs[0].length();i++){
            int j = 0;
           for(;j<strs.length-1;j++){
              if(!sorted[j]&&strs[j].charAt(i)>strs[j+1].charAt(i)){
                  res++;
                  break;
              }  
            }
            if(j<strs.length-1){
                continue;
            }
            j = 0;
            for(;j<strs.length-1;j++){
                if(strs[j].charAt(i)<strs[j+1].charAt(i)){
                    sorted[j] = true;
                }
            }
        }
        return res;
}
}
