class Solution {
    String s;
    List<String>result;
    int target;
    public void operator(int i,int prev,long prod,long mid,String exp,List<Long>l){
        if(i==l.size()){
            if(mid+prod==target)
                result.add(exp);
            return;
        }
        if(prev==-1){
            operator(i+1,0,-1*l.get(i)*l.get(i-1),mid+l.get(i-1),exp+"*"+l.get(i),l);
        }else if(prev==1){
            operator(i+1,0,l.get(i)*l.get(i-1),mid-l.get(i-1),exp+"*"+l.get(i),l);
        }else{
            operator(i+1,0,prod*l.get(i),mid,exp+"*"+l.get(i),l);
        }
        operator(i+1,-1,0,mid+prod-l.get(i),exp+"-"+l.get(i),l);
        operator(i+1,1,0,mid+prod+l.get(i),exp+"+"+l.get(i),l);
    }
    public void rec(int in,List<Long>l){
        if(in==s.length()){
            operator(1,1,0,l.get(0),l.get(0)+"",l);
            return;
        }
        if(s.charAt(in)=='0'){
            l.add(0L);
            rec(in+1,l);
            l.remove(l.size()-1);
        }else{
            for(int i=in;i<s.length();i++){
                l.add(Long.parseLong(s.substring(in,i+1)));
                rec(i+1,l);
                l.remove(l.size()-1);
            }
        }
    }
    public List<String> addOperators(String num, int target) {
        result=new ArrayList<>();
        this.s=num;
        this.target=target;
        rec(0,new ArrayList<>(30));
        return result;
    }
}
