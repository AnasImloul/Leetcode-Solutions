class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int> map;
        for(vector<int> rectangle: rectangles){
		    //storing number of time a particular square can obtain
            map[min(rectangle[0],rectangle[1])]++; //[4,6], you can cut it to get a square with a side length of at most  4.
        }
        int cnt=INT_MIN,maxlen=INT_MIN;
        for(auto m: map){
            if(m.first>maxlen) cnt=m.second,maxlen=m.first; //finding out the maxlength square then storing its count in cnt
        }
        return cnt;
    }
};
