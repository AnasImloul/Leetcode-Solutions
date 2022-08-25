// Runtime: 938 ms (Top 33.33%) | Memory: 118 MB (Top 71.11%)

class Solution {

    HashMap<String , HashSet<Integer>> cache ;

    public int scoreOfStudents(String s, int[] answers) {

        cache = new HashMap();
        HashSet<Integer> total_possible_ans = getPossibleAns(s);

        int correct_ans = getCorrectAns(s);

        int total_score = 0 ;
        for(int i=0 ; i<answers.length ; i++){
            if(answers[i] == correct_ans){
                total_score += 5 ;
            }else if(total_possible_ans.contains(answers[i])){
                total_score += 2 ;
            }
        }

        return total_score ;
    }

    public HashSet<Integer> getPossibleAns(String s){

        if(cache.containsKey(s)){
            return cache.get(s) ;
        }

        HashSet<Integer> possible_ans = new HashSet() ;

        for(int i = 0 ; i<s.length() ; i++){

            char cur = s.charAt(i) ;
            HashSet<Integer> left = new HashSet() ;
            HashSet<Integer> right = new HashSet() ;

            if(cur == '+' || cur == '*'){
                left = getPossibleAns(s.substring(0 , i));
                right = getPossibleAns(s.substring(i+1));
            }

            for(Integer l : left){
                for(Integer r : right){
                    if(cur == '+'){
                        if(l+r > 1000) continue ; // skiping for ans that are greater than 1000
                        possible_ans.add(l+r);
                    }else if(cur == '*'){
                        if(l*r > 1000) continue ; // skiping for ans that are greater than 1000
                        possible_ans.add(l*r);
                    }
                }
            }
        }

        if(possible_ans.isEmpty() && s.length() <= 1){
            possible_ans.add(Integer.parseInt(s));
        }

        cache.put(s , possible_ans);

        return possible_ans ;
    }

    public int getCorrectAns(String s) {

        Stack<Integer> stack = new Stack() ;

        for(int i = 0 ; i<s.length() ; i++){

            // push only integers into stack
            if(s.charAt(i) != '+' && s.charAt(i) != '*'){
                stack.push(Character.getNumericValue(s.charAt(i))) ;
            }

            // If operator is '*' , then take the last element from stack and multiply with next element
            // Also push into stack , and then increment i also , to avoid pushing the same next element into stack again
            if(s.charAt(i) == '*'){
                int cur = stack.pop();
                int next = Character.getNumericValue(s.charAt(i+1)) ;
                stack.push(cur * next);
                i++ ;
            }
        }

        // Now sum all the element in the stack to get result for '+' operator
        int total_sum = stack.pop() ;

        while(!stack.isEmpty()){
            total_sum += stack.pop() ;
        }

        return total_sum ;
    }

}
