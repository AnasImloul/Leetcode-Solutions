// Runtime: 3 ms (Top 98.11%) | Memory: 61.90 MB (Top 20.33%)

class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        
    	int i,m=rolls.length,sum=0;
    	for(i=0;i<m;i++)
    		sum+=rolls[i];
			
    	int x=(mean*(m+n))-sum;
		
		if(x<=0||n*6<x||((x/n)==0)) {
    		return new int[] {};
		}
			
    	int arr[]=new int[n];
    	
		int p=x/n,q=x%n;
    	for(i=0;i<n;i++)  {
		
    		arr[i]=p+(q>0?1:0);
    		q--;
    	}
    	return arr;
    }
}
