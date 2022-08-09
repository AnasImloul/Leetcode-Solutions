class Solution {
public:
    int minFlips(string target) {
	int count=0;
		// we see thye number of times the change occur
        for(int i=0; i<target.size()-1;i++){
            if(target[i] != target[i+1] ){
                count++;
            }}
        if(target[0]=='0'){return count;}
        else{return count+1;}
        return 0;
    }
};
