class Solution {
    public NestedInteger deserialize(String s) {
        if(!s.startsWith("["))return new NestedInteger(Integer.valueOf(s));
        Stack<NestedInteger> st=new Stack<NestedInteger>();
        NestedInteger res = new NestedInteger();
        st.push(res);
        int start=1;
        for(int i=1;i<s.length();i++){
            if(s.charAt(i)=='['){
                NestedInteger cur=new NestedInteger();
                st.peek().add(cur);
                st.push(cur);
                start=i+1;
            }else if(s.charAt(i)==']' || s.charAt(i)==','){
                if(start<i){
                    int end=i;
                    String n=s.substring(start,end);
                    st.peek().add(new NestedInteger(Integer.valueOf(n)));
                }
                start=i+1;
                if(s.charAt(i)==']')st.pop();
            }
        }
        return res;
    }
}