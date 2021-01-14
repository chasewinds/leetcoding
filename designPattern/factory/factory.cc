#include <iostream>
#include <string>

using namespace std;

class Mask {
 public:
  virtual string String() = 0;
};

class SurgicalMask : public Mask {
 public:
  string String() { return "这是医用口罩"; }
};

class N95Mask : public Mask {
 public:
  string String() { return "这是 N95 口罩"; }
};

class MaskFactory {
 public:
  Mask* create(string type) {
    if (type == "Surgical") {
      return new SurgicalMask();
    } else if (type == "N95") {
      return new N95Mask();
    }
    return nullptr;
  }
};

int main() {
  MaskFactory* factory = new MaskFactory();
  cout << factory->create("Surgical")->String() << endl;
  cout << factory->create("N95")->String() << endl;
  return 0;
}