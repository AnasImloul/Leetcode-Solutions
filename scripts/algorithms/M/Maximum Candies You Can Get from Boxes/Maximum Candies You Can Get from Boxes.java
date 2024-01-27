// Runtime: 6 ms (Top 61.19%) | Memory: 57.10 MB (Top 59.7%)

class Solution {
		public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes)
		{
			int n=initialBoxes.length;

			if(n==0)
				return 0;

			Queue<Integer> q=new LinkedList<>();
			int totalCandies=0;

			for(int i:initialBoxes)
			{
                if(status[i]==0)
                {
                    q.add(i);
                }
                else
                {
                    totalCandies+=candies[i];              // Add all Candies of intial box;
                    for(int j=0;j<containedBoxes[i].length;j++)
                    {
                        q.add(containedBoxes[i][j]);       // Add all Contained Boxes in queue;
                    }
                    for(int j=0;j<keys[i].length;j++)
                    {
                        status[keys[i][j]]=1;              // Set status of of box=1 if we found key;
                    }
                }
			}

			while(q.size()>0 && isValid(q,status))
			{
				int b=q.poll();
				if(status[b]==1)
				{
					totalCandies+=candies[b];          // Add all Candies of selected box;


					for(int j=0;j<containedBoxes[b].length;j++)
					{
						q.add(containedBoxes[b][j]);   // Add all Contained Boxes in queue;
					}
					for(int j=0;j<keys[b].length;j++)
					{
						status[keys[b][j]]=1;          // Set status of of box=1 if we found key;
					}
				}
				else
					q.add(b);       // If Status==0 add again in queue;
			}
			return totalCandies;
		}

	/* This function helps to know whether any boxes in queue status is still open or not
	if all boxes status is off then it will return false and above while loop while terminate beacue now  we cannot get any candy*/
		public boolean isValid(Queue<Integer> q,int[] status)  
		{
			Queue<Integer> cq=new LinkedList<>(q);

			while(cq.size()>0)
			{
				if(status[cq.poll()]==1)
					return true;
			}
			return false;
		}
	}
