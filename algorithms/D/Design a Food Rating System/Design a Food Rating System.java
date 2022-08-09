class FoodRatings {
    HashMap<String, TreeSet<String>> cuiToFood = new HashMap();
    HashMap<String, Integer> foodToRat = new HashMap();
    HashMap<String, String> foodToCui = new HashMap();
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for(int i = 0; i < foods.length; i++){
            TreeSet<String> foodOfThisCuisine = cuiToFood.getOrDefault(cuisines[i], new TreeSet<String> ((a,b)->
            foodToRat.get(a).equals(foodToRat.get(b)) ? a.compareTo(b) : foodToRat.get(b)-foodToRat.get(a)));
			
			// Both comparators are equal
			/* new Comparator<String>(){
                @Override
                public int compare(String a, String b){
                    int aRat = foodToRat.get(a);
                    int bRat = foodToRat.get(b);
                    
                    if(aRat != bRat) return bRat - aRat; // largest rating first
                    for(int i = 0; i < Math.min(a.length(), b.length()); i++){
                        if(a.charAt(i) != b.charAt(i)) return a.charAt(i) - b.charAt(i);
                    }
                    return a.length() - b.length();
                }
            })
			*/
            
            foodToRat.put(foods[i], ratings[i]);
            foodOfThisCuisine.add(foods[i]);
            foodToCui.put(foods[i], cuisines[i]);    
            
            cuiToFood.put(cuisines[i], foodOfThisCuisine);
        }
    }
    
    // CompareTo() is used to compare whether 2 strings are equal in hashSet! So remove, change value of key in HashMap, then insert again
    public void changeRating(String food, int newRating) {
        String cui = foodToCui.get(food);
        TreeSet<String> foodOfThisCui = cuiToFood.get(cui);
        foodOfThisCui.remove(food);
        foodToRat.put(food, newRating);
        
        foodOfThisCui.add(food);
        cuiToFood.put(cui, foodOfThisCui);
    }
    
    public String highestRated(String cuisine) {
        return cuiToFood.get(cuisine).first();
    }
}
