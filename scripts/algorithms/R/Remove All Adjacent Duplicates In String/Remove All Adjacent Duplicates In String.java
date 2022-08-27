// Runtime: 95 ms (Top 46.58%) | Memory: 54.8 MB (Top 52.34%)
class Solution {
    public String removeDuplicates(String s) {
        Stack<Character> st=new Stack<>();
        int i=s.length()-1;
        while(i>=0)
        {
            char ch=s.charAt(i);
            if(st.size()>0 && ch==st.peek())
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
            i--;
        }
        StringBuilder ans=new StringBuilder("");
        while(!st.isEmpty())
        {
            ans.append(st.pop());
        }
        return ans.toString();
    }
}