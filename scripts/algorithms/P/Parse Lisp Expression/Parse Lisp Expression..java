// Runtime: 5 ms (Top 68.0%) | Memory: 41.90 MB (Top 62.0%)

class Solution {
    Map<String, Integer> vars = new HashMap<>();

    public int evaluate(String expression) {
        String[] strs = split(expression);

        switch (strs[0]) {
            case "let":
                Map<String, Integer> localVars = new HashMap<>(vars);
                Map temp = vars;
                for (int i = 1; i < strs.length - 1; i++) {
                    String name = strs[i];
                    int val = evaluate(strs[i + 1]);
                    if (localVars.containsKey(name)) localVars.replace(name, val);
                    else localVars.put(name, val);
                    i++;
                    vars = localVars;
                }
                int res = evaluate(strs[strs.length - 1]);
                vars = temp;
                return res;

            case "add":
                return evaluate(strs[1]) + evaluate(strs[2]);

            case "mult":
                return evaluate(strs[1]) * evaluate(strs[2]);

            default:
                try {
                    return Integer.parseInt(strs[0]);
                } catch (Exception e) {
                    return vars.get(strs[0]);
                }
        }
    }

    private String[] split(String exp) {
        List<String> tokens = new ArrayList<>();

        if (exp.charAt(0) != '(') {
            tokens.add(exp);
        }
        else {
            tokens.add(exp.substring(1, exp.indexOf(' ')));

            for (int i = exp.indexOf(' ') + 1; i < exp.length(); i++) {
                if (exp.charAt(i) == ')') break;
                else if (exp.charAt(i) == ' ') continue;

                if (tokens.get(0).equals("let") && tokens.size() % 2 == 1 && exp.charAt(i) != '(' && exp.indexOf(' ', i) > 0) {
                    tokens.add(exp.substring(i, exp.indexOf(' ', i + 1)));
                    i = exp.indexOf(' ', i + 1) + 1;
                }

                if (exp.charAt(i) != '(') {
                    int index = exp.indexOf(' ', i + 1);
                    if (index < 0) index = exp.indexOf(')', i + 1);
                    tokens.add(exp.substring(i, index).trim());
                    i = index;
                } else {
                    int stack = 1;
                    int j = i + 1;
                    while (stack > 0) {
                        if (exp.charAt(j) == '(') stack++;
                        else if (exp.charAt(j) == ')') stack--;
                        j++;
                    }
                    tokens.add(exp.substring(i, j));
                    i = j;
                }
            }
        }

        return tokens.toArray(new String[0]);
    }
}
