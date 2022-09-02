// Runtime: 1 ms (Top 44.68%) | Memory: 41.8 MB (Top 51.62%)
class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        if(!sentence.contains(searchWord))
            return -1;
        boolean y=false;
        String[] str=sentence.split(" ");

        for(int i=0;i<str.length;i++){
            if(str[i].contains(searchWord)){
                for(int j=0;j<searchWord.length();j++){
                    if(str[i].charAt(j)!=searchWord.charAt(j)){
                        y=true;
                        break;
                    }

                }
                 if(!y){
                     return i+1;
                 }
            }
            y=false;
        }

        return -1;
    }
}