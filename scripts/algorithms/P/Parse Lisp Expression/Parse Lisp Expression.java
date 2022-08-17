class Solution {
    
    String expression;
    int index;
    HashMap<String,Deque<Integer>> scope; 
    //variable may be assigned many times, we use the peek value 
    
    public int evaluate(String expression) {
        this.expression=expression;
        index=0;
        scope=new HashMap<>();
        return evaluate();
    }
    
    private int evaluate(){
        
        if(expression.charAt(index)=='('){
            //this is an expression
            index++; //skip '('
            char begin=expression.charAt(index);
            int ret;
            if(begin=='l'){
                //let
                index += 4; //skip let and a blank space
                ArrayList<String> vars=new ArrayList<>();
                while(true){
                    if(!Character.isLowerCase(expression.charAt(index))){
                        ret=evaluate();
                        break;
                    }
                    String var=parseVar();
                    if(expression.charAt(index)==')'){
                        ret=scope.get(var).peek();
                        break;
                    }
                    vars.add(var);
                    index++;
                    int e=evaluate();
                    scope.putIfAbsent(var, new LinkedList<>());
                    scope.get(var).push(e); //assign a new value
                    index++;
                }
                for (String var : vars) {
                    scope.get(var).pop(); // remove all values of this scope
                }

            } else if(begin=='a') {
                //add
                index += 4;
                int v1 = evaluate();
                index++;
                int v2 = evaluate();
                ret = v1+v2;
            } else {
                //multi
                index += 5;
                int v1 = evaluate();
                index++;
                int v2 = evaluate();
                ret =  v1*v2;
            }
            index++; // skip ')'
            return ret;
        } else {
            //this is not a expression, this is an integer or a variable
            if(Character.isLowerCase(expression.charAt(index))){
				//this is a variable, the current value is peek value
                String var=parseVar();
                return scope.get(var).peek();
            } else {
				//this is an integer
                return parseInt();
            }
        }
    }
    
    //read an integer
    private int parseInt(){
        boolean negative=false;
        if(expression.charAt(index)=='-'){
            negative=true;
            index++;
        }
        int ret=0;
        while(Character.isDigit(expression.charAt(index))){
            ret*=10;
            ret+=expression.charAt(index)-'0';
            index++;
        }
        if(negative) return -ret;
        return ret;
    }
    
    //read a variable
    private String parseVar(){
        StringBuilder sb=new StringBuilder();
        char c=expression.charAt(index);
        while(c!=' ' && c!=')'){
            sb.append(c);
            c=expression.charAt(++index);
        }
        return sb.toString();
    }
}
