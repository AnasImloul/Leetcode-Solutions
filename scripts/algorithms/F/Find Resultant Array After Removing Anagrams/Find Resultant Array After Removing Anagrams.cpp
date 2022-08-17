class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {        
        vector<string> resultant_array;
        
		// Keeping the first pointer at index 0 and the second pointer at index 1
        int ptr1 = 0;
        int ptr2 = 1;
        
        while(ptr2<=words.size()){
            string s1 = words[ptr1];
            sort(s1.begin(),s1.end());
            
            resultant_array.push_back(words[ptr1]);
            
            while(ptr2<words.size()){
                string s2 = words[ptr2];
                sort(s2.begin(), s2.end());
                
				// Remember to compare the sorted arrays to check for anagrams
                if(s1!=s2){
                    break;
                }
                else{
                    ptr2++;
                }
            }
            
            ptr1 = ptr2;
            ptr2++;
        }
        
        return resultant_array;
    }
};
