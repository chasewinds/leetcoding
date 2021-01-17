#include <iostream>
#include <semaphore.h>

using namespace std;

class Foo {
 public:
  sem_t firstSem;
  sem_t secondSem;

  Foo() {
    sem_init(&firstSem, 0, 0);
    sem_init(&secondSem, 0, 0);
  }

  void first(function<void()> printFirst) {
    printFirst();
    sem_post(&firstSem);
  }

  void second(function<void()> printSecond) {
    sem_wait(&firstSem);
    printSecond();
    sem_post(&secondSem);
  }

  void third(function<void()> printThird) {
    sem_wait(&secondSem);
    printThird();
  }
};