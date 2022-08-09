class Robot {
private:
    int width, height, perimeter;
    int dir = 0;
    int x = 0, y = 0;
    map<int, string> mp = {{0, "East"}, {1, "North"}, {2, "West"}, {3, "South"}};

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->perimeter = 2 * (height + width) - 4;
    }
    
    void step(int num) {
		if(!num) return;
        num = num % perimeter;
        if(x == 0 && y == 0 && num == 0) dir = 3;
        while(num--){
            if(x == 0 && y == 0) dir = 0;
            else if(x == width-1 && y == 0) dir = 1;
            else if(x == width-1 && y == height-1) dir = 2;
            else if(x == 0 && y == height-1) dir = 3;
            
            if(dir == 0) x += 1; 
            if(dir == 1) y += 1;
            if(dir == 2) x -= 1;
            if(dir == 3) y -= 1;
        }
        
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return mp[dir];
    }
};
