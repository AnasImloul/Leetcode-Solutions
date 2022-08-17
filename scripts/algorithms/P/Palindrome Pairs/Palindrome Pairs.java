class Solution {
public List<List<Integer>> palindromePairs(String[] words) {
    List<List<Integer>> result = new ArrayList<>();
    HashMap<String, Integer> map = new HashMap<>();
    
    //buildMap
    for(int i = 0 ; i < words.length; i++){
        map.put(words[i], i);
    }
    
    //Case1 : Empty + palidrome string
    if(map.containsKey("")){
        int index = map.get("");
        for(int i = 0 ; i < words.length; i++){
            if(i != index && isPalindrome(words[i])){
                result.add(Arrays.asList(index, i));
                result.add(Arrays.asList(i, index));
            }
        }
    }
    
    //Case 2 : Reflection in array
    for(int i = 0; i < words.length; i++){
        String reverse = new StringBuilder(words[i]).reverse().toString();
        if(map.containsKey(reverse)){
            int index = map.get(reverse);
            if(index != i)
                result.add(Arrays.asList(i, index));
        }
    }
    
    //Case 3 : evalaute reflection
    for(int i = 0; i < words.length; i++){
        String curr = words[i];
        for(int j = 1; j < curr.length(); j++){
            String left = curr.substring(0, j);
            String right = curr.substring(j);
            if(isPalindrome(left)){
                String reversedRight = new StringBuilder(right).reverse().toString();
                if(map.containsKey(reversedRight)){
                    result.add(Arrays.asList(map.get(reversedRight), i));
                }
            }
            if(isPalindrome(right)){
                String reversedLeft = new StringBuilder(left).reverse().toString();
                if(map.containsKey(reversedLeft)){
                    result.add(Arrays.asList(i, map.get(reversedLeft)));
                }
            }
        }
    }  
    
    return result;
}

private boolean isPalindrome(String word){
    int i = 0, j = word.length() - 1;
    while(i < j)
        if(word.charAt(i++) != word.charAt(j--))
            return false;
    
    return true;
}
}