static constexpr uint8_t FORKS_NUM = 5;
class DiningPhilosophers {
public:
    DiningPhilosophers() {
        for(int i = 0; i < FORKS_NUM; ++i){
            pthread_mutex_init(&forks[i], NULL);
        }    
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        uint8_t leftForkId = (philosopher + 1) % FORKS_NUM;
        uint8_t rightForkId = philosopher;
        if(philosopher < FORKS_NUM - 1){
            pthread_mutex_lock(&forks[rightForkId]);
            pthread_mutex_lock(&forks[leftForkId]);
        }
        else{ // this prevents the circular wait condition, that if would happen would cause the deadlock.
            pthread_mutex_lock(&forks[leftForkId]);
            pthread_mutex_lock(&forks[rightForkId]);
        }
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        pthread_mutex_unlock(&forks[leftForkId]);
        putRightFork();
        pthread_mutex_unlock(&forks[rightForkId]);
    }
private:
    pthread_mutex_t forks[FORKS_NUM]; // mutex for each fork
};
