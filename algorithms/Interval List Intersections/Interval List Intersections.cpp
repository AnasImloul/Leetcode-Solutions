class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0;
        int j = 0;
        while(i < firstList.size() && j < secondList.size()){
            if((firstList[i][0] >= secondList[j][0] && firstList[i][0] <= secondList[j][1])||(secondList[j][0] >= firstList[i][0] && secondList[j][0] <= firstList[i][1]) ){
                //there is an overlap
                result.push_back( {max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
            }
            if(firstList[i][1] < secondList[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        return result;
    }
};
