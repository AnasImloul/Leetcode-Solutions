class MagicDictionary {
    private String[] dictionary;
    
    public MagicDictionary() {}
    
    public void buildDict(String[] dictionary) {
        this.dictionary = dictionary;
    }
    
    public boolean search(String searchWord) {
        for (String dictWord: this.dictionary) {
            if (this.match(searchWord, dictWord, 1))
                return true;
        }
        
        return false;
    }
    
    private boolean match(String s, String t, int expectedDiff) {
        if (s.length() != t.length())
            return false;
        
        int diff = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != t.charAt(i))
                diff++;
            if (diff > expectedDiff)
                return false;
        }
        
        return diff == expectedDiff;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dictionary);
 * boolean param_2 = obj.search(searchWord);
 */
