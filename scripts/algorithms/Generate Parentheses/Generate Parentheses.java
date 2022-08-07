class Solution {
    List<String> s = new ArrayList<>();
    public void get(int n, int x, String p)
    {
        if(n==0 && x==0)
        {
            s.add(p);
            return;
        }
        if(n==0)
        {
            get(n,x-1,p+")");
        }
        else if(x==0)
        {
            get(n-1,x+1,p+"(");
        }
        else
        {
            get(n,x-1,p+")");
            get(n-1,x+1,p+"(");
        }
    }
    public List<String> generateParenthesis(int n) 
    {
        s.clear();
        get(n,0,"");
        return s;
    }
}
