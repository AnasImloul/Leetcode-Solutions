class Solution {
    List<Integer> result=new ArrayList<>();
    
    public int[] numsSameConsecDiff(int n, int k) {
        
        List<Integer> list=new ArrayList<>();
        generate(list,n,k);
        int Ans[]=new int[result.size()];
        
        
        for(int i=0;i<result.size();i++)
        {
            Ans[i]=result.get(i);
        }
        
        return Ans;
        
    }//main 
    
    public void generate(List<Integer> list,int n,int k)
    {
        //base case ....
        if(n==list.size())
        {
            String num="";
            for(int d:list)
                num+=d;
            
            result.add(Integer.parseInt(num));
            return ;
        }
        
        
        for(int i=0;i<=9;i++)
        {
            if(list.size()==0)//snce it is the 1st digit to be picked so 1st digit cannot be 0 at all 
            {
                if(i==0)
                    continue;
                
                else
                {
                    list.add(i);
                    generate(list,n,k);
                    list.remove(list.size()-1);//backtrack ....
                }
            }//for 1st place 
            
            else //if not the 1st place thenn we can pick any digits including zero provided its absolute differnce from the previous picked digit in the list must be equal to k ..
            {
                if(Math.abs(list.get(list.size()-1)-i)!=k)
                    continue;
                
                else//if equal to k tehn pick it .. 
                {
                    list.add(i);
                    generate(list,n,k);
                    
                    //backtrack 
                    list.remove(list.size()-1);
                }
                
            }//if not the 1st place ...
            
        }//loop to iterate over all the digits from 0 to 9 
    }//generate all the combinations ....
}
