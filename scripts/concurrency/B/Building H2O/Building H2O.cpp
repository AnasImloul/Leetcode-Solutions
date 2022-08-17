#include <semaphore.h>
class H2O {
public:
    H2O() {
        sem_init(&h_sem, 0, 1);
        sem_init(&o_sem, 0, 0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&h_sem);
		
        // Lock this - '++' is a critical code
        pthread_mutex_lock(&mtx);
        h++;
        pthread_mutex_unlock(&mtx);
		
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if (h % 2 == 0)
            sem_post(&o_sem);
        else
            sem_post(&h_sem);
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o_sem);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&h_sem);
    }
private:
    sem_t h_sem;
    sem_t o_sem;
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    int h = 0;
};
