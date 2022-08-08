class Solution {
public:
    int minSetSize(vector<int>& arr) {
        const int n=1e5+10 ;
        int a[n]={0} ;
        for(int i=0 ;i<arr.size() ;i++)
        {
            a[arr[i]]++ ;
        }
        priority_queue<int> maxh ;
        for(int i=0; i<n ;i++)
        {
            maxh.push(a[i]) ;
        }
        int sum=0 ;
        int count=0 ;
        
        while(sum<(arr.size()/2))
        {
            sum=sum+maxh.top() ;
            maxh.pop() ;
            count++ ;
        }
        return count ;
        
    }
};