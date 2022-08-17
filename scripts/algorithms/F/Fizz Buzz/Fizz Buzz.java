class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> l=new ArrayList<>();
        
        for(int i=1,fizz=0,buzz=0;i<=n;i++)
        {
            fizz++;
            buzz++;
            
            if(fizz==3 && buzz==5)
            {
                l.add("FizzBuzz");
                fizz=0;
                buzz=0;
            }
            else if(fizz==3)
            {
                l.add("Fizz");
                fizz=0;
            }
            else if(buzz==5)
            {
                l.add("Buzz");
                buzz=0;
            }
            else{
                l.add(String.valueOf(i));
            }
        }
        return l;
    }
}
