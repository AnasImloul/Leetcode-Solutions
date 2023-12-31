// Runtime: 215 ms (Top 30.21%) | Memory: 78.90 MB (Top 67.67%)

class Car{
public:
    Car(int pos, int speed){
        this->pos = pos;
        this->speed= speed;
    }
    int pos;
    int speed;
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        int N = position.size();
        for(int i = 0; i<N; i++){
            cars.emplace_back(position.at(i), speed.at(i));
        }
        
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b){
            return a.pos<b.pos;
        });
        
        stack<float> mono;
        for(int i = 0; i<N; i++){
            float time = 
                (target-cars.at(i).pos)/(float)cars.at(i).speed;
            while(!mono.empty() && time >= mono.top()){
                mono.pop();
            }
            mono.push(time);
        }
        return mono.size();
    }
};
