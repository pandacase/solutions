
#include <string>
#include <iostream>

class Context {
public:
  std::string name;
  size_t day;
  mutable std::string message;

  Context(std::string n, size_t d)
   : name(n), day(d) { }
  
  void SetMessage(std::string m) const {
    message = m;
  }
};

////////////////////////////////////////////////////////////////////////

class IHandler {
public:
  IHandler() : _next(nullptr) { }

  void SetNextHandler(IHandler* next) {
    _next = next;
  }

  // 算法骨架，使用了模板方法
  bool Handle(const Context& ctx) {
    if (CanHandle(ctx)) {
      return HandleRequest(ctx);
    } else if (GetNextHandler()) {
      return GetNextHandler()->Handle(ctx);
    } else {
      return false;
    }
  }

  static bool handler_leave_req(Context& ctx);

protected:
  virtual bool HandleRequest(const Context& ctx) { return true; }
  virtual bool CanHandle(const Context& ctx) { return true; }
  IHandler* GetNextHandler() { return _next; }

private:
  IHandler* _next;
};

////////////////////////////////////////////////////////////////////////

class HandleByBeaty : public IHandler {
  virtual bool HandleRequest(const Context& ctx) {
    ctx.SetMessage("Handle by beaty.");
    return true;
  }

  virtual bool CanHandle(const Context& ctx) {
    // ...
    if (ctx.day <= 1) 
      return true;
    else
      return false;
  }
};

class HandleByMainProgram : public IHandler {
protected:
  virtual bool HandleRequest(const Context& ctx) {
    ctx.SetMessage("Handle by main program.");
    return true;
  }

  virtual bool CanHandle(const Context& ctx) {
    // ...
    if (ctx.day <= 3)
      return true;
    else
      return false;
  }
};

class HandleByProjMgr : public IHandler {
protected:
  virtual bool HandleRequest(const Context& ctx) {
    ctx.SetMessage("Handle by project manager.");
    return true;
  }

  virtual bool CanHandle(const Context& ctx) {
    // ...
    if (ctx.day <= 10)
      return true;
    else
      return false;
  }
};

class HandleByBoss : public IHandler {
protected:
  virtual bool HandleRequest(const Context& ctx) {
    ctx.SetMessage("Handle by boss.");
    return true;
  }

  virtual bool CanHandle(const Context& ctx) {
    // ...
    if (ctx.day <= 15)
      return true;
    else
      return false;
  }
};

////////////////////////////////////////////////////////////////////////

//! 工厂模式：解决复杂对象构建过程（一般和单例模型相比较）
bool IHandler::handler_leave_req(Context& ctx) {
  IHandler* h0 = new HandleByBeaty();
  IHandler* h1 = new HandleByMainProgram();
  IHandler* h2 = new HandleByProjMgr();
  IHandler* h3 = new HandleByBoss();
  h0->SetNextHandler(h1);
  h1->SetNextHandler(h2);
  h2->SetNextHandler(h3);
  // 实际生产中应该返回头结点对象
  return h0->Handle(ctx);
}

////////////////////////////////////////////////////////////////////////

int main() {
  Context ctx("panda",  5);
  if (IHandler::handler_leave_req(ctx)) {
    std::cout << "Request Successfully." << std::endl;
    std::cout << ctx.message << std::endl;
  } else {
    std::cout << "Request Failure." << std::endl;
  }
}