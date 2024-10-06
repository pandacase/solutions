
#include <list>
#include <iostream>

class IComponent {
public:
  IComponent() = default;
  ~IComponent() = default;
  virtual void Execute() = 0;
  virtual void AddChild(IComponent* ele) {}
  virtual void RemoveChild(IComponent* ele) {}
};


class Leaf : public IComponent {
public:
  virtual void Execute() {
    std::cout << "Leaf execute" << std::endl;
  }
};


class Composite : public IComponent {
public:
  virtual void Execute() {
    for (auto& child : _list) {
      child->Execute();
    }
  }

  virtual void AddChild(IComponent* ele) {
    _list.push_back(ele);
  }

  virtual void RemoveChild(IComponent* ele) {
    _list.remove(ele);
  }

private:
  std::list<IComponent*> _list;
};