// Runtime: 4 ms (Top 85.13%) | Memory: 42 MB (Top 91.86%)
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