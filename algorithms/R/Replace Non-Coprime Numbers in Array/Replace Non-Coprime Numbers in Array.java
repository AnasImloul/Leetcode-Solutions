class Solution {
	public List<Integer> replaceNonCoprimes(int[] nums) 
	{
		List<Integer> al=new ArrayList<>();
		long n1=nums[0];
		int idx=1;

		while(idx<nums.length)
		{
			if((int)gcd(n1,nums[idx])==1)
			{
				while(al.size()!=0)
				{
					int t=al.get(al.size()-1);
					if(gcd(n1,t)==1)
						break;
					else
					{
						al.remove(al.size()-1);
						n1=lcm(t,n1);
					}
				}

				al.add((int)n1);
				n1=nums[idx];
				idx++;
			}
			else
			{
				n1=lcm(n1,nums[idx]);
				idx++;
			}
		}

		while(al.size()!=0)
		{
			int t=al.get(al.size()-1);
			if(gcd(n1,t)==1)
				break;
			else
			{
				al.remove(al.size()-1);
				n1=lcm(t,n1);
			}
		} 
		al.add((int)n1);

		return al;
	}

	public long gcd(long a,long b)
	{
		if (b == 0)   
			return a;  

		return gcd(b, a % b);  
	}

	public long lcm(long a,long b)
	{
		long hcf=gcd(a,b);
		return (a*b)/hcf;
	}
}