INTUITION
1. since we have to find the minimum deletions, we dont have to 
	actually delete the elements , we just have to count those elements.
2. Now if we delete the element and shift all the elements towards left , it will
	cause time limit exceeded.
3. To handle above case we can  observe one thing that, if we delete some element
	at a certain position then the indices of all the elements towards the right 
	will get inverted means the odd index will become even and the even will become odd.
4. In the end checking if the vector size if even or odd, if it is even simply return or else if it 
	is odd then decrement result by 1 since we have to remove one element to have the vector size even.
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int res=0,n=nums.size(),i;
        int flag=1;
            for(i=0;i<nums.size()-1;i++){
                    if(i%2==0 and nums[i]==nums[i+1]  and flag){
                        res++;
                        flag=0;
                    }
                    else if(i%2==1 and nums[i]==nums[i+1] and flag==0){
                        res++;
                        flag=1;
                    }
                }
        int x=n-res;
        if(x%2==0){
            return res;
        }
        return res+1;
    }
};