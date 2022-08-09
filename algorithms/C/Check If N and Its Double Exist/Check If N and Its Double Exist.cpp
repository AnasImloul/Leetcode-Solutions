class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        int i =0;
            int j  = 1;
        int n = arr.size();
        while(i<n && j<n)
        {
                
                if(  arr[i]<0 && arr[j]<0 && arr[i]==2*arr[j])return true;
            
                else if(2*arr[i]<arr[j])
                {
                    
                    i++;
                  

                
                }
            else if(2*arr[i]>arr[j])j++;
            else if(i==j && arr[i]==0){
            i++;
                j++;
            }
            
            else return true;
        
        }
        return false;
        
    }
};
