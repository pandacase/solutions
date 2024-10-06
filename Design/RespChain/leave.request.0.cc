
#include <string>

class Context {
public:
  std::string name;
  size_t day;
};

//! @brief 
//! 这是采用责任链模式之前的代码，模拟请假请求处理流程
//! 这里可以看到 handle_request 本身维护性非常差
//! 
class LeaveRequest {
public:
  bool handle_request(const Context& ctx) {
    if (ctx.day <= 1)
      handle_by_beaty(ctx);
    if (ctx.day <= 3)
      handle_by_main_program(ctx);
    else if (ctx.day <= 10)
      handle_by_proj_mgr(ctx);
    else
      handle_by_boss(ctx);
  }

private:
  bool handle_by_beaty(const Context& ctx) { }
  bool handle_by_main_program(const Context& ctx) { }
  bool handle_by_proj_mgr(const Context& ctx) { }
  bool handle_by_boss(const Context& ctx) { }
};
