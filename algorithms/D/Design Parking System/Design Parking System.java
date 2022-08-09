class ParkingSystem {
    private int[] size;
    public ParkingSystem(int big, int medium, int small) {
        this.size = new int[]{big, medium, small};
    }
    
    public boolean addCar(int carType) {
        return size[carType-1]-->0;
    }
}
