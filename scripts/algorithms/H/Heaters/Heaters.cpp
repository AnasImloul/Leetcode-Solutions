// Runtime: 62 ms (Top 96.61%) | Memory: 25.4 MB (Top 58.20%)
class Solution {
public:
    //we will assign each house to its closest heater in position(by taking the minimum
    //of the distance between the two closest heaters to the house) and then store the maximum
    //of these differences(since we want to have the same standard radius)
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int radius=0;
        for(int house:houses){
            //finding the smallest heater whose position is not greater than
            //the current house
            int index=lower_bound(heaters.begin(),heaters.end(),house)-heaters.begin();
            if(index==heaters.size()){
                index--;
            }
            //the two closest positions to house will be heaters[index] and
            //heaters[index-1]
            int leftDiff=(index-1>=0)?abs(house-heaters[index-1]):INT_MAX;
            int rightDiff=abs(house-heaters[index]);
            radius=max(radius,min(leftDiff,rightDiff));
        }
        return radius;
    }
};