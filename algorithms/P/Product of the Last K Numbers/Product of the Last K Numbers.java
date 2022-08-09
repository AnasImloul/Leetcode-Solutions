class ProductOfNumbers {
    List<Integer> prefix;
    public ProductOfNumbers() {
        prefix = new ArrayList<>();
        prefix.add(1);
    }
    
    public void add(int num) {
        if(num==0){
            prefix.clear();
            prefix.add(1);
        }
        else prefix.add(num*prefix.get(prefix.size()-1));
    }
    public int getProduct(int k) {
        if(k>=prefix.size()) return 0;
        return prefix.get(prefix.size()-1)/prefix.get(prefix.size()-k-1);
    }
}
