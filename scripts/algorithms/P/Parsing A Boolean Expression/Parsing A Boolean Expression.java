class Solution {
    public boolean parseBoolExpr(String expression) {
        int n=expression.length();
        
        Stack<Character>operator=new Stack<>();
        Stack<Character>operand=new Stack<>();
        
        for(int i=0;i<n;i++){
            char c=expression.charAt(i);
            if(c==','){
                continue;
            }
            
            if(c=='!' || c=='|' || c=='&'){
                operator.push(c);
            }else if(c=='(' || c=='f' || c=='t'){
                operand.push(c);
            }else{
                char op=operator.pop();
                char ans=operand.pop();
                boolean flag=false;
                while(!operand.isEmpty() && operand.peek()!='('){
                    ans=evaluate(ans,operand.pop(),op);
                    flag=true;
                }
                operand.pop();
                if(!flag){
                    if(op=='!'){
                    operand.push(ans=='f'?'t':'f');    
                    }else{
                        operand.push(ans);
                    }
                    
                }else{
                operand.push(ans);    
                }
                
            }
        }
        return operand.peek()=='t';
    }
    
    public char evaluate(char a, char b, char op){
        if(op=='|'){
            return (a=='t' || b=='t')?'t':'f';
        }else if(op=='&'){
            return (a=='t' && b=='t')?'t':'f';
        }
        return 't';
    }
}