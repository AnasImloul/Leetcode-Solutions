class Solution {
public:
    string reorganizeString(string s) {
        
        // Step1: insert elements to the map so that we will get the frequency
        unordered_map<char, int> mp;
        for(auto i: s){
            mp[i]++;
        }
        
        //Step2: Create a max heap to store all the elements according to there frequency
        priority_queue<pair<int, char>> pq;
        
         for(auto it: mp){
            pq.push({it.second, it.first});
        }
        
        //Step3: Now take two elements from the heap and do this till the map becomes size 1
        // why one : cause we are taking two top elements like pq.top is a then will pop and again pq.top is b and will add to answer
        string ans = "";
        while(mp.size() > 1){
            //get the top two elements from heap
            char ch1 = pq.top().second;
            ans+=ch1;
            pq.pop();
            char ch2 = pq.top().second;
            ans+=ch2;
            pq.pop();
            
            //now reduce the size in the mp
            // now we have added two char in the ans so reduce the cound in map
            mp[ch1]--;
            mp[ch2]--;
            
            //Now check if it's size is still greater than 0 then push
            // if size is greater in map than 0 then we again need to push into the map so that we can make the ans string
            if(mp[ch1] > 0){
                pq.push({mp[ch1],ch1});
            }
            else{
                //if the size is 0 then decrese the map means erase the map
                mp.erase(ch1);
            }
            if(mp[ch2] > 0){
                pq.push({mp[ch2],ch2});
            }
            else{
                mp.erase(ch2);
            }
        }
        
        //Step4 : Now check wheather any element is present into it
        // Now we have zero size of the map so check top element size is greater than 1 or not if greater the we cannot split it since it''s only that char if not add to ans
        if(mp.size() == 1){
            if(mp[pq.top().second] > 1){
                return "";
            }
            ans += pq.top().second;
        }
        //returrn ans
        return ans;
    }
};
