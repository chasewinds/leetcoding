
// runtime 7.01% memo 94.04% 看来互斥锁的效率不高啊
class ZeroEvenOdd {
 private:
  int n;
  pthread_mutex_t mutex0;
  pthread_mutex_t mutex1;
  pthread_mutex_t mutex2;

 public:
  ZeroEvenOdd(int n) {
    pthread_mutex_init(&mutex0, NULL);
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    this->n = n;
    pthread_mutex_lock(&mutex1);
    pthread_mutex_lock(&mutex2);
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for (int i = 0; i < n; i++) {
      pthread_mutex_lock(&mutex0);
      printNumber(0);
      if (i % 2 == 0) {
        pthread_mutex_unlock(&mutex2);
      } else {
        pthread_mutex_unlock(&mutex1);
      }
    }
  }

  void even(function<void(int)> printNumber) {
    for (int i = 2; i <= n; i+=2) {
      pthread_mutex_lock(&mutex1);
      printNumber(i);
      pthread_mutex_unlock(&mutex0);
    }
  }

  void odd(function<void(int)> printNumber) {
    for (int i = 1; i <= n; i+=2) {
      pthread_mutex_lock(&mutex2);
      printNumber(i);
      pthread_mutex_unlock(&mutex0);
    }
  }
};