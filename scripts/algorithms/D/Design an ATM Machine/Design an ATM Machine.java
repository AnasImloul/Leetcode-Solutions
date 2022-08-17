class ATM {
	long[] notes = new long[5];                                                // Note: use long[] instead of int[] to avoid getting error in large testcases
	int[] denoms;
	public ATM() {
		denoms = new int[]{ 20,50,100,200,500 };                               // create an array to represent money value.
	}

	public void deposit(int[] banknotesCount) {
		for(int i = 0; i < banknotesCount.length; i++){
			notes[i] += banknotesCount[i];                                       // add new deposit money to existing
		}
	}

	public int[] withdraw(int amount) {                 
		int[] result = new int[5];                                              // create result array to store quantity of each notes we will be using to withdraw "amount"
		for(int i = 4; i >= 0; i--){
			if(amount >= denoms[i] ){                                              
				int quantity = (int) Math.min(notes[i], amount / denoms[i]);     // pick the minimum quanity. because if say, amount/denoms[i] gives 3 but you only have 1 note. so you have to use 1 only instead of 3 
				amount -= denoms[i] * quantity;                                 // amount left = 100
				result[i] = quantity;
			}
		}
		if(amount != 0){ return new int[]{-1}; }
		for(int i = 0; i < 5; i++){  notes[i] -= result[i];  }                   // deduct the quantity we have used.
		return result;
	}
}
