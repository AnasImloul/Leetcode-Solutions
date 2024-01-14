// Runtime: 7 ms (Top 99.5%) | Memory: 45.00 MB (Top 40.87%)

class ParkingSystem {
    private int slots[] = new int[3];
    public ParkingSystem(int big, int medium, int small) {
        slots[0] = big;
        slots[1] = medium;
        slots[2] = small;
    }
    
    public boolean addCar(int carType) {
        if(slots[carType-1]>0)
        {   
            slots[carType-1]--;
            return true;
            
        }
        return false;
    }
}
