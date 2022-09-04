// Runtime: 25 ms (Top 60.54%) | Memory: 14.6 MB (Top 67.48%)
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();

        //taking last index as greatest for now
        int g=arr[n-1];
        //setting last index as -1
        arr[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
        //storing last index value to be changed to comapare with the greatest value till now
            int h=arr[i];
            //assigning greatest till now from right
            arr[i]=g;
            //checking if current is greater than the previous indices
            if(h>g)
            {
                g=h;
            }
        }
                     //returning the value
     return arr;
    }
};