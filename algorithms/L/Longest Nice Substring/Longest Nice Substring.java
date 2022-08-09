class Solution {
    public String longestNiceSubstring(String s) {
        String result = "";
        // take first index, go from 0 to length-1 of the string
		for (int i = 0;i<s.length(); i++){        
            // take second index, this should go up to the length of the string <=
			for (int j = i+1;j<=s.length(); j++){
                //get the substring for the index range from i to j
				String temp = s.substring(i, j);
                // if length of the substring should be greater than 1
				// if the length should be greater that the previous computed result
				// if the substring is valid Nice String
				// then update the result with the current substring from range i and j
				if (temp.length() > 1 && result.length() < temp.length() && checkNice(temp)) result = temp;
            }    
        }
        return result;
    }
    
	//validate Nice String check
    public boolean checkNice(String temp){
        //add substring to the set
		Set<Character> s = new HashSet<>();
        for (char ch : temp.toCharArray()) s.add(ch);
        
		// return false If you do not find both lower case and upper case in the sub string
		//for e.g 'aAa' substring added to set will have both a and A in the substring which is valid
		// 'azaA' substring will fail for 'z'
		// 'aaaaaaaa' will return "" as result
		//make sure that the substring contains both lower and upper case
        for (char ch : s)
            if (s.contains(Character.toUpperCase(ch)) != s.contains(Character.toLowerCase(ch))) return false;  
        return true;
    }
}
