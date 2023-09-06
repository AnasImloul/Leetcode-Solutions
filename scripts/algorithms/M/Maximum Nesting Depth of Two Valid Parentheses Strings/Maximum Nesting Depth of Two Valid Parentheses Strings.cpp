// Runtime: 5 ms (Top 33.5%) | Memory: 7.72 MB (Top 13.7%)

    class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        //since we want the difference to be as low as possible so we will try to balance both A and B by trying to maintain the number of paranthesis as close as close as possible
        vector<int> indexA, indexB, res(seq.length(), 0 );
		//initailly assuming all parenthesis belong to A so filling res with 0
        int i = 0;
        int addToA = 0, addToB = 0;
        while(i < seq.length()){
            if(seq[i] == '('){
                if(addToA <= addToB){
                    //adding depth to A when it's depth is lesser or equal to b
                    indexA.push_back(i);
                    addToA ++;
                }else{
                    indexB.push_back(i);
                    addToB++;
                }
            }else{
                // removing depth from string whose depth is maximum as we have to keep the difference minimum
                if(addToA >= addToB){
                    addToA--;
                    indexA.push_back(i);
                }else{
                    indexB.push_back(i);
                    addToB--;
                }
            }
           i++;
        }
         for(i = 0; i < indexB.size(); i++){
                res[indexB[i]] = 1;
            }
         return res;   
    }
};