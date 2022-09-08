// Runtime: 13 ms (Top 8.65%) | Memory: 6.9 MB (Top 88.34%)
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 * public:
 * int get(int index);
 * int length();
 * };
 */

class Solution {
public:

    //----------------------- find peak ---------------------------------------

    int find_max(MountainArray &mountainArr,int start,int end)
    { int n= mountainArr.length();
        while(start<=end)
        { int mid= start+(end-start)/2;
           int next=(mid+1)%n;
          int prev=(mid+n-1)%n;

         int mid_val = mountainArr.get(mid);
         int pre_val = mountainArr.get(prev);
         int next_val = mountainArr.get(next);

           if(mid_val > next_val and mid_val>pre_val)
               return mid;

           else if(mid_val<next_val and mid_val > pre_val)
                start=mid+1;

           else if(mid_val>next_val and mid_val<pre_val)
                end=mid-1;

        }
        return -1;

    }

   //--------------------------binary search-------------------------------------------

   int binary_search(MountainArray &mountainArr,int start,int end,int target)
   {
       while(start<=end)
       {
           int mid= start + (end-start)/2;
             int mid_val=mountainArr.get(mid);

           if(mid_val==target)
               return mid;
          else if(target < mid_val)
           {
               end=mid-1;
           }
           else
               start=mid+1;
       }
       return -1;
   }

    //----------------------binary search in reverse sorted------------------------------

       int binary_search_rev(MountainArray &mountainArr,int start,int end,int target)
   {
       while(start<=end)
       {
           int mid= start + (end-start)/2;
           int mid_val=mountainArr.get(mid);
           if(mid_val==target)
               return mid;
          else if(target > mid_val)
           {
               end=mid-1;
           }
           else
               start=mid+1;
       }
       return -1;
   }

  //------------------------------returns minimum index of target--------------------------------------

    int evaluate_ans(int a,int b)
    {
        if(a==-1 and b==-1 )
            return -1;
        else if(a!= -1 and b!= -1)
            return min(a,b);
        else if(a==-1 and b!=-1)
            return b;
        else
            return a;

    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int start=0;
        int n= mountainArr.length()-1;
        int max_in = find_max(mountainArr,start ,n);

        int a= binary_search(mountainArr,start,max_in,target);
        int b= binary_search_rev(mountainArr,max_in + 1,n,target);

        return evaluate_ans(a,b);
    }
};