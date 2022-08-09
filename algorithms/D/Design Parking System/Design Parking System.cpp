class ParkingSystem {
public: vector<int> vehicle;
public:
    ParkingSystem(int big, int medium, int small) {
        vehicle = {big, medium, small};
    }

    bool addCar(int carType) {
        return vehicle[carType - 1]-- > 0;
    }
