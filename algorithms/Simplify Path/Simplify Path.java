class Solution {
    public String simplifyPath(String path) {
        String[] paths = path.split("/");
        Stack<String> st=new Stack<>();
        for(String dir:paths){
            if(dir.equals(".") || dir.length()==0) continue;
            else{
                if(!st.isEmpty() && dir.equals(".."))
                    st.pop();
                else if(st.isEmpty() && dir.equals(".."))
                    continue;
                else st.push(dir);
            }
        }
        StringBuilder sb=new StringBuilder();
        if(st.isEmpty()) return "/";
        for(String s:st){
            sb.append("/"); sb.append(s);
        }
        return sb.toString();
    }
}
