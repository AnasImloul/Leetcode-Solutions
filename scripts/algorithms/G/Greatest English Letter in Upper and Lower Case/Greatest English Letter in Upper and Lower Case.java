// Runtime: 6 ms (Top 53.1%) | Memory: 41.50 MB (Top 23.1%)

class Solution
{
    public String greatestLetter(String s)
    {
        Set<Character> set = new HashSet<>();
        for(char ch : s.toCharArray())
            set.add(ch);
        
        for(char ch = 'Z'; ch >= 'A'; ch--)
            if(set.contains(ch) && set.contains((char)('a'+(ch-'A'))))
               return ""+ch;
        return "";
    }
}