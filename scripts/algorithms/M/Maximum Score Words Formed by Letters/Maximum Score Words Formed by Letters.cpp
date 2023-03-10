class Solution {
public:
    int calc(vector<string>& words,map<char,int>&m,vector<int>& score,int i){ 
        int maxi=0;
        if(i==words.size())
            return 0;
        map<char,int>m1=m;//Creating a duplicate in case the given word does not satisfy our answer
        int c=0;//Store the score
        for(int j=0;j<words[i].length();j++){
            if(m1.find(words[i][j])==m1.end()||m1[words[i][j]]==0){//If frequency of the letter reduces to zero or that letter is not present in our hashMap            
                c=-1;
                break;
            }
            c+=score[words[i][j]-'a'];
            m1[words[i][j]]--;
        }        
        if(c!=-1)           
          maxi=c+(calc(words,m1,score,i+1));//We are considering the current word and adding it to our answer
        return max(maxi,calc(words,m,score,i+1));//FInding tha maximum between when we consider the current word and when we DONT consider current word
        
}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int>m;       
        for(auto i:letters)
            m[i]++;
        return calc(words,m,score,0);   
    }
};