class Solution {
    public int minimumBuckets(String street)
    {
        Set<Integer> set = new HashSet<>();
        if(!street.contains(".")) return -1;
        int count = 0;
        for(int i=0;i<street.length();i++)
        {
            if(street.charAt(i)=='H')
            {
                if((i==0 && street.charAt(i+1)=='H')||(i==street.length()-1 && street.charAt(i-1)=='H'))
                    return -1;
                else if(i!=0 && i!=street.length()-1 && street.charAt(i+1)=='H' && street.charAt(i-1)=='H')
                    return -1;
            }
            else if(i!=0 && i!=street.length()-1 && street.charAt(i-1)=='H' && street.charAt(i+1)=='H' && !set.contains(i-1) && !set.contains(i+1))
            {
                set.add(i-1);
                set.add(i+1);
                count++;
            }
        }
        for(int i=0;i<street.length();i++)
        {
            if(street.charAt(i)=='H' && !set.contains(i))
                count++;
        }
        return count;
    }
}
