class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> ch(26,0);
		// store the broken letters in ch vector
        for(char c: brokenLetters){
            ch[c-'a']=1;
        }
        int cnt=0,ans=0;
		//traversing the text string
        for(int i=0;i<text.length();i++){
		    //if char is ' ' means that we got a new word
            if(text[i]==' '){
			    // cnt remain 0 means that there is no broken letter in this word
                if(cnt==0) ans++;
                cnt=0; //reinitialize cnt to 0 as new word start from here
            }else if(ch[text[i]-'a']==1){ //if char is present in ch then just increment the cnt
                    cnt++;
            }
        }
		//for last word in string
        if(cnt==0) ans++;
        return ans;
    }
};
