// Runtime: 5 ms (Top 67.01%) | Memory: 45.5 MB (Top 47.50%)
class Solution {
    public List<String> removeAnagrams(String[] words) {
        String prev ="";
        List<String> li=new ArrayList<>();
        for(int i=0;i<words.length;i++){
            char[] ch=words[i].toCharArray();
            Arrays.sort(ch);
            String curr=String.valueOf(ch);
            if(!curr.equals(prev)){
                li.add(words[i]);
                prev=curr;
            }
        }
        return li;
    }
}