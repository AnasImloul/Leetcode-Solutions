class Solution {
public:
    int minimumDeletions(string s){

        vector<int> deletions(s.size()+1, 0);
        int b_count = 0;
        
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='a'){
                // Either Delete this 'a' or Delete all previous 'b's.
                deletions[i+1] = min(deletions[i]+1, b_count);
            } else{
                deletions[i+1] = deletions[i];
                b_count++;
            }
        }

        return deletions[s.size()];

        // The code is contributed by Mufaddal Saifuddin
    }
};