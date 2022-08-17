class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int Max = INT_MIN;
        int N = colors.size();
        
        // find the first house from the end which does not match the color of house at front
        int j=N;
        while(--j>=0 && colors[0]==colors[j]) { }   // worst-case O(n)
        Max = abs(j-0);
        
        // find the first house from the front which does not match the color of house at back
        j=-1;
        while(++j<N && colors[N-1]==colors[j]) { }  // worst-case O(n)
        Max = max(Max, abs(j-(N-1)));
        
        return Max;
    }
};
