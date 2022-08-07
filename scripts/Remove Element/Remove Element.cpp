class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        //loop will run till the size of nums 
        //if any elements is deleted in between, size is reduced
        for(int i=0;i<nums.size();i++)
        {
            //if element equal to val, go to else, if not equal, skip that element and increment counter
            if(nums[i] != val)
            {
                continue;
            }
            else
            {
                //for equal elements, to erase that no, assign iterator which is pointing at that position
                nums.erase(nums.begin()+i);
                //after deleting that pointer, decrement i
                i--;
                
                
                //suppose we are dealing with 2,2,2,2 and we want to delete 2
                //first i=0, we get a match, we delete 2
                //now i will be inc to 1, but now size of nums is 3 and as 1st element is deleted
                //new 2,2,2 will have indexes 0,1,2
                //if i is now 1, it'll skip the newly generated 0th 2
                //and it'll delete the newly generated 2,and i became 2
                //after deleting newly generated 2, size of num is updated to 2, and we will be out of loop
                //as i = 3, and newly updated nums have size 2, and those 2 will remain there
                
                //by doing i--, after deleting, we will again start our loop, from that position, 
                //from where we've deleted the matched value,
                //say 2,2,2,2
                //we found 2 on 0th posn, deleted it, now size 3
                //by i--, i will be -1 at the moment of i--, then as per outer loop inc -1 to 0
                //we got new size 3, with 2,2,2 at 0,1,2nd index
                //we check at 0th index,match and erase
                //again i-- to have -1
                //inc to 0 by for loop
                //got list with size 2, at 0th & 1st index
                //got match and erase
                //optimal solution
            }
        }
        
        int size = nums.size();
        
        return size;
    }
    
    /* ** THIS THROWS EXCEPTION, BUT PATIYA BESADELA CHHE ELTLE CHALI GYU **
    
    int removeElement(vector<int>& nums, int val) {
        
        for(int i=0;i<nums.size();i++)
        {
            for(auto it = nums.begin();it != nums.end();it++)
            {
                if(*it == val)
                {
                    cout<<*it<<" "<<val<<endl;
                   nums.erase(it);
                    break;
                }
            }
        }
        
        int size = nums.size();
        
        return size;
    }
    
    */
};