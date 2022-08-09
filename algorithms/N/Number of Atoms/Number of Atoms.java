class Solution {
    public String countOfAtoms(String formula) {
        Deque<Integer> multiplier = new ArrayDeque<>();
        Map<String, Integer> map = new HashMap<>();
        int lastValue = 1;
        
        multiplier.push(1);
        
		// Iterate from right to left
        for (int i = formula.length() - 1; i >= 0; i--) {
            if (Character.isDigit(formula.charAt(i))) { // Case of a digit - Get full number and save
                StringBuilder sb = new StringBuilder();
				
                while (Character.isDigit(formula.charAt(i-1))) {
                    sb.append(formula.charAt(i));
                    i--;
                }
                sb.append(formula.charAt(i));
                lastValue = Integer.parseInt(sb.reverse().toString());
            } else if (formula.charAt(i) == ')') { // Start parenthesis - push next multiplier to stack
                multiplier.push(lastValue * multiplier.peek());
                lastValue = 1;
            } else if (formula.charAt(i) == '(') { // End parenthesis - pop last multiplier
                multiplier.pop();
            } else { // Case of an element name - construct name, update count based on multiplier
                StringBuilder sb = new StringBuilder();
                
                while (Character.isLowerCase(formula.charAt(i))) {
                    sb.append(formula.charAt(i));
                    i--;
                }
                sb.append(formula.charAt(i));
                
                String element = sb.reverse().toString();
                map.put(element, map.getOrDefault(element, 0) + lastValue * multiplier.peek());
                lastValue = 1;
            }
        }
        
		// Sort map keys
        List<String> elements = new ArrayList<>(map.keySet());
        StringBuilder sb = new StringBuilder();
        Collections.sort(elements);
        
		// Construct output
        for (String element : elements) {
            sb.append(element);
            if (map.get(element) > 1) {
                sb.append(map.get(element));       
            }
        }
        return sb.toString();
    }
}
