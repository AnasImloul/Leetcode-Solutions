// Runtime: 0 ms (Top 100.0%) | Memory: 41.70 MB (Top 55.0%)

class Solution {
    public int minNumberOfHours(int initialEnergy, int initialExperience, int[] energy, int[] experience) {
        int currentEnergy = initialEnergy;
        int currentExperience = initialExperience;
        int result = 0;
        int diff = 0;
        for (int i = 0; i < energy.length; i++) {
            if (energy[i] >= currentEnergy) {   
                diff = energy[i] - currentEnergy + 1;
                result = result + diff;
                currentEnergy = currentEnergy + diff;
            }
            currentEnergy = currentEnergy - energy[i];
            if (experience[i] >= currentExperience) {
                diff = experience[i] - currentExperience + 1;
                result = result + diff;
                currentExperience = currentExperience + diff;
            }
            currentExperience = currentExperience + experience[i];
        }
        return result;
    }
}
