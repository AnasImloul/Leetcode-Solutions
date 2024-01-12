// Runtime: 0 ms (Top 100.0%) | Memory: 41.40 MB (Top 29.82%)

class Solution {
    public String interpret(String c) {
        StringBuilder st = new StringBuilder();
        for(int i =0; i<c.length(); i++)
        {
            if(c.charAt(i) == 'G')
                st.append("G");
            else
            {
                if(c.charAt(i+1) == ')' )
                {
                    st.append("o");
                    i++;
                }
                else
                {
                    st.append("al");
                    i = i+3;
                }
            }
        }
        return st.toString();
    }
}
