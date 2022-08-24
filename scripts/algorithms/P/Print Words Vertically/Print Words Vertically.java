// Runtime: 10 ms (Top 20.22%) | Memory: 42.9 MB (Top 20.22%)
class Solution {
    public List<String> printVertically(String s) {
        s = s.replace(" ",",");
        String str="";
        List<String> a=new ArrayList<>();

        int max=0;
        for(int i =0;i<s.length();i++){
           char ch=s.charAt(i);
            if(ch==','){
                a.add(str);
                max=Math.max(max,str.length());
                str="";
                continue;
            }
            else if(i==s.length()-1){
                str+=ch;
                a.add(str);
                max=Math.max(max,str.length());
                str="";
                continue;
            }
            str+=ch;

        }

        String [] arr=new String[max];
        for(int i =0;i<max;i++){
            arr[i]="";

        }

        for(int i =0;i<a.size();i++){
            String x=a.get(i);

            for(int j=0;j<max;j++){

                if(j<x.length()){
                    arr[j]+=x.charAt(j);
                }
                else{
                    arr[j]+=" ";
                }
            }

        }

        a=new ArrayList<>();
        for(int i=0;i<arr.length;i++){

            String x=arr[i];
            x=trim(x);

            a.add(x);
        }

        return a;
    }

    public String trim(String str) {
        int len = str.length();
        int st = 0;

        char[] val = str.toCharArray();

        while ((st < len) && (val[len - 1] <= ' ')) {
            len--;
        }
        return str.substring(st, len);
    }
}