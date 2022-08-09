class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {        
        //initially score is 0, that's why in these conditions, return 0.        
        if(tokens.length == 0 || power < tokens[0])
			return 0;        
        Arrays.sort(tokens); //sort the array
        
        int i = 0;
        int r = tokens.length - 1;
        int score = 0;
        int answer = 0;
        
        while(i<=r){            
            if(power >= tokens[i]){
                power -= tokens[i++];                
                answer = Math.max(answer, ++score); //play all tokens, but store the max score in answer.    
            }
            else if (score > 0){
                power += tokens[r--]; //take power from greatest element
                score--; //decrease by 1.
            }            
            //when you can't do any of the steps (face up, face down)
            else
                return answer;
        }        
        return answer;
    }
}
