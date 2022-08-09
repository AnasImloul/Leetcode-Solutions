class Solution {
public:
    int minOperationsToFlip(string expression) {
        expression = "(" + expression + ")";
        splitParantheses(expression);
        sort(p.begin(), p.end(), [](Parantheses &a, Parantheses &b){
            return a.order > b.order;
        });
        for (int i = 0; i < p.size(); i++)
            solveParantheses(expression, i);
        return evaluations[0].toFlip;
    }
private:
    class Parantheses{
    public:
        int open;
        int close;
        int eval;
        int toFlip;
        int order;
    };
    unordered_map<int, Parantheses> evaluations; // information about Paratheses stored by index of open bracket.
    vector<Parantheses> p;
    void splitParantheses(string &e){
        int open = 0;
        stack<int> opened;
        for (int i = 0; i < e.size(); i++)
            switch (e[i]){
                case '(':
                    open++;
                    opened.push(i);
                    break;
                case ')':
                    open--;
                    Parantheses para;
                    para.open = opened.top();
                    opened.pop();
                    para.close = i;
                    para.order = open;
                    p.push_back(para);
                    break;
            }
    }
    void solveParantheses(string &e, int index){
        int open = p[index].open;
        int close = p[index].close;
        int poz = open + 1;
        int eval = -1; // evaluation of the expression so far (-1 because we need to read a value first)
        int toFlipEval; // number of flips needed to change current evaluation.
        for (int i = open + 1; i < close; i++){
            if (e[i] == '&' || e[i] == '|'){
                op = e[i];
                continue;
            }
            int val; // value of th ecurrent term
            int toFlipVal; // number of flips needed to change current term.
            if (evaluations.count(i)){
                val = evaluations[i].eval;
                toFlipVal = evaluations[i].toFlip;
                i = evaluations[i].close;
            }
            else if (e[i] == '0'){
                val = 0;
                toFlipVal = 1;
            }
            else if (e[i] == '1'){
                val = 1;
                toFlipVal = 1;
            }
            else{
                printf("ERROR, e[i] = %c\n", e[i]);
            }
            
            if (eval == -1){
                eval = val;
                toFlipEval = toFlipVal;
            } else {
                if (op == '&'){
                    if (eval == 1 && val == 1){
                        toFlipEval = min(toFlipEval, toFlipVal);
                    } else{
                        int changeJustTerm, changeOperatorAndTerm;
                        changeJustTerm = !eval * toFlipEval + !val * toFlipVal;
                        if (eval != val)
                            changeOperatorAndTerm = 1;
                        else
                            changeOperatorAndTerm = min(toFlipEval, toFlipVal) + 1;
                        toFlipEval = min(changeJustTerm, changeOperatorAndTerm);
                        eval = 0;
                        
                    }
                } else{
                    if (eval == 0 && val == 0){
                        toFlipEval = min(toFlipEval, toFlipVal);
                    } else{
                        int changeJustTerm, changeOperatorAndTerm;
                        changeJustTerm = eval * toFlipEval + val * toFlipVal;
                        if (eval != val)
                            changeOperatorAndTerm = 1;
                        else
                            changeOperatorAndTerm = min(toFlipEval, toFlipVal) + 1;
                        toFlipEval = min(changeJustTerm, changeOperatorAndTerm);
                        eval = 1;
                    }
                }
            }
        }
        p[index].eval = eval;
        p[index].toFlip = toFlipEval;
        evaluations[open] = p[index];
    }
};
