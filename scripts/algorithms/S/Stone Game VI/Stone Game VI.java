class Solution 
{
static class Pair
{
        int sum=0;
        int alice=0;
        int bob=0;
    public Pair(int sum,int alice, int bob)
{
    this.sum=sum;
	this.alice = alice;
	this.bob = bob;
}
}

// class to define user defined conparator
static class Compare {
	
	static  void compare(Pair arr[], int n)
	{
		// Comparator to sort the pair according to second element
		Arrays.sort(arr, new Comparator<Pair>() {
			@Override public int compare(Pair p1, Pair p2)
			{
				return p2.sum - p1.sum;
			}
		});
		
		
	}
}
    public int stoneGameVI(int[] aliceValues, int[] bobValues)
    {
        int n=aliceValues.length;
        Pair[] a=new Pair[n];
        for(int i=0;i<n;i++)
        {
            a[i]=new Pair(aliceValues[i]+bobValues[i],aliceValues[i],bobValues[i]);
        }
        Compare.compare(a,n);
         int al=0;int bo=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                al+=a[i].alice;
            }
            else
            {
                bo+=a[i].bob;
            }
        }
        return Integer.compare(al,bo);
    
    
    
    }
}

