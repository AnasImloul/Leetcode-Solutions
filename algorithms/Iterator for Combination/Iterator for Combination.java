class CombinationIterator {

    private Queue<String> allCombinations;
    public CombinationIterator(String characters, int combinationLength) {
        this.allCombinations = new LinkedList<>();
        generateAllCombinations(characters,0,combinationLength,new StringBuilder());
    }
    
    private void generateAllCombinations(String characters,int index,int combinationLength,StringBuilder currentString){
        
        if(currentString.length() == combinationLength){
            this.allCombinations.offer(currentString.toString());
            return;
        }
        
        for(int i = index ; i < characters.length() ; i++){
            currentString.append(characters.charAt(i));
            generateAllCombinations(characters,i+1,combinationLength,currentString);
            currentString.deleteCharAt(currentString.length()-1);
        }
        
    }
    
    public String next() {
        return this.allCombinations.poll();
    }
    
    public boolean hasNext() {
      return !this.allCombinations.isEmpty();
    }
}
