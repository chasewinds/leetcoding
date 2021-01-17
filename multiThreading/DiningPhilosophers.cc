#include <semaphore.h>
#include <iostream>
#include <mutex>

using namespace std;


// limit upper bound, prevent five eating
class DiningPhilosophers {
 public:
  std::mutex fmtx[5];
  sem_t eaterLimit;
  DiningPhilosophers() {
    sem_init(&eaterLimit, 0, 4);
  }

  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    int left = philosopher;
    int right = (philosopher + 1) % 5;

    sem_wait(&eaterLimit);
    std::lock_guard<std::mutex> leftMtx(fmtx[left]);
    std::lock_guard<std::mutex> rightMtx(fmtx[right]);

    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();
    sem_post(&eaterLimit);
  }
};
