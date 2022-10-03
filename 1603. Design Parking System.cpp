class ParkingSystem {
public:
    
    short slots[3];
    ParkingSystem(int big, int medium, int small) {
        slots[2] = small;
        slots[1] = medium;
        slots[0] = big;
    }
    
    bool addCar(int carType) {
        if(slots[carType -1] > 0)
        {
            --slots[carType -1];
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */