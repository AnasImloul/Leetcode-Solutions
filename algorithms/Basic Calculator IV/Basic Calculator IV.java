class Solution {
    class Node {
        Map<List<String>, Integer> mem = new HashMap<>();
        
        void update(List<String> cur, int cnt) {
            Collections.sort(cur);
            mem.put(cur, mem.getOrDefault(cur, 0) + cnt);
        }
        
        Node add(Node cur) {
            Node ans = new Node();
            for (List<String> key1 : mem.keySet()) {
                ans.update(key1, mem.get(key1));
            }
            for (List<String> key2 : cur.mem.keySet()) {
                ans.update(key2, cur.mem.get(key2));
            }
            return ans;
        }
        Node sub(Node cur) {
            Node ans = new Node();
            for (List<String> key1 : mem.keySet()) {
                ans.update(key1, mem.get(key1));
            }
            for (List<String> key2 : cur.mem.keySet()) {
                ans.update(key2, -cur.mem.get(key2));
            }
            return ans;
        }
        
        Node mul(Node cur) {
            Node ans = new Node();
            for (List<String> key1 : mem.keySet()) {
                for (List<String> key2 : cur.mem.keySet()) {
                    List<String> next = new ArrayList<>();
                    next.addAll(key1);
                    next.addAll(key2);
                    ans.update(next, mem.get(key1) * cur.mem.get(key2));
                }
            }
            return ans;
        }
        
        Node evaluate(Map<String, Integer> vars) {
            Node ans = new Node();
            for (List<String> cur : mem.keySet()) {
                int cnt = mem.get(cur);
                List<String> free = new ArrayList<>();
                for (String tmp : cur) {
                    if (vars.containsKey(tmp)) {
                        cnt = cnt * vars.get(tmp);
                    } else {
                        free.add(tmp);
                    }
                }
                ans.update(free, cnt);
            }
            
            return ans;
        }
        
        List<String> toList() {
            List<String> ans = new ArrayList<>();
            List<List<String>> keys = new ArrayList<>(mem.keySet());
            Collections.sort(keys, (List<String> a, List<String> b) -> {
                if (a.size() != b.size()) {
                    return b.size() - a.size();
                }
                for (int i = 0; i < a.size(); i ++) {
                    if (a.get(i).compareTo(b.get(i)) != 0) {
                        return a.get(i).compareTo(b.get(i));
                    }
                }
                return 0;
            });
            
            for (List<String> key : keys) {
                if (mem.get(key) == 0) {
                    continue;
                }
                String cur = "" + String.valueOf(mem.get(key));
                for (String data : key) {
                    cur += "*";
                    cur += data;
                }
                ans.add(cur);
            }
            return ans;
        }
    }
    
    Node make(String cur) {
        Node ans = new Node();
        List<String> tmp = new ArrayList<>();
        if (Character.isDigit(cur.charAt(0))) {
            ans.update(tmp, Integer.valueOf(cur));
        } else {
            tmp.add(cur);
            ans.update(tmp, 1);
        }
        return ans;
    }
    int getNext(String expression, int start) {
        int end = start;
        while (end < expression.length() && Character.isLetterOrDigit(expression.charAt(end))) {
            end ++;
        }
        return end - 1;
    }
    
    int getPriority(char a) {
        if (a == '+' || a == '-') {
            return 1;
        } else if (a == '*') {
            return 2;
        }
        return 0;
    }
    
    Node helper(Stack<Node> nums, Stack<Character> ops) {
        Node b = nums.pop();
        Node a = nums.pop();
        char op = ops.pop();
        if (op == '*') {
            return a.mul(b);
        } else if (op == '+') {
            return a.add(b);
        } 
        return a.sub(b);
    }
    
    public List<String> basicCalculatorIV(String expression, String[] evalvars, int[] evalints) {
        List<String> ans = new ArrayList<>();
        if (expression == null || expression.length() == 0 || evalvars == null || evalints == null) {
            return ans;
        }
        
        Map<String, Integer> vars = new HashMap<>();
        for (int i = 0; i < evalvars.length; i ++) {
            vars.put(evalvars[i], evalints[i]);
        }
        
        int n = expression.length();
        Stack<Node> nums = new Stack<>();
        Stack<Character> ops = new Stack<>();
        for (int i = 0; i < n; i ++) {
            char a = expression.charAt(i);
            if (Character.isLetterOrDigit(a)) {
                int end = getNext(expression, i);
                String cur = expression.substring(i, end + 1);
                i = end;
                Node now = make(cur);
                nums.add(now);
            } else if (a == '(') {
                ops.add(a);
            } else if (a == ')') {
                while (ops.peek() != '(') {
                    nums.add(helper(nums, ops));
                }
                ops.pop();
            } else if (a == '+' || a == '-' || a == '*') {
                while (ops.size() > 0 && getPriority(ops.peek()) >= getPriority(a)) {
                    nums.add(helper(nums, ops));
                }
                ops.add(a);
            }
        }
        
        while (ops.size() > 0) {
            nums.add(helper(nums, ops));
        }
        
        return nums.peek().evaluate(vars).toList();
        
    }
}
