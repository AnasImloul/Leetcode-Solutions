class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int sum1=0;
        for(int i=0;i<arr.size();i++)
        {
            int count=0;
            sum+=arr[i];
            for(int j=i;j<arr.size();j++)
            {
                sum1+=arr[j];
                count++;
                if(count%2!=0 and count!=1)
                    sum+=sum1;
            }
            sum1=0;
        }
        return sum;
    }
};
