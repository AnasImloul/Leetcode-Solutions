// Runtime: 11 ms (Top 50.06%) | Memory: 10.6 MB (Top 23.88%)
class Solution {
public:
    //what i think is we have to return the intersection elements from both nums
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        //result vector which will store those values which will be intersecting in both nums
        vector<int> result;

        //map intersection, which will store values of all the elements in num1
        unordered_map<int,int> intersection;

        //map will store all the values of num1(as key),with corresponding value 1
        for(auto character : nums1)
        {
            intersection[character] = 1;
        }

        //this loop will check if any element of num1 is there in num2? if yes, insert it in result
        //after inserting it once, make its corresponding value to 0
        //so that if you find any elements, that is repeating in num2, as well as present in num1
        //so you dont enter it twice in result, you should enter it once only
        for(auto character : nums2)
        {
            //if found once, it's value would be 1, so entered in result
            //after it is entered in result, its value we change to 0
            //so agin if that same element repeats, due to 0 as its value, we avoid pushing it to result
            if(intersection[character])
            {
                result.push_back(character);
                intersection[character] = 0;
            }
        }

        //after getting all the intersecting elements,we return result
        return result;
    }
};