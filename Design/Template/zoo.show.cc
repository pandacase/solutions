
#include <iostream>

class ZooShow {
public:
  ZooShow(int type = 1) : _type(type) { }

public:
  // 算法骨架：模板模式的特征
  // 单一职责原则
  void Show() {
    // 流程由抽象类大一，具体的环节内细节可以被子类重写
    if (Show0())
      PlayGame();
    Show1();
    Show2();
    Show3();
  }

  int GetType() const {
    return _type;
  }

private:
  // 接口隔离原则
  void PlayGame() {
    std::cout << "After show0, then play game" << std::endl;
  }

protected:
  // 使用 protected 限定可以被扩展的接口
  virtual bool Show0() {
    std::cout << "Show0" << std::endl;
    return true;
  }

  virtual void Show1() {
    std::cout << "Show1" << std::endl;
  }

  virtual void Show2() {
    std::cout << "Show2" << std::endl;
  }

  virtual void Show3() {
    std::cout << "Show3" << std::endl;
  }

private:
  int _type;
};

////////////////////////////////////////////////////////////////////////

class ZooShowEx1 : public ZooShow {
protected:
  // 子类覆写可扩展接口
  virtual bool Show0() {
    std::cout << "Great Show0" << std::endl;
    return true;
  }
};

////////////////////////////////////////////////////////////////////////

int main() {
  // 动态多态
  ZooShow* ptr = new ZooShowEx1;
  ptr->Show();
  return 0;
}
