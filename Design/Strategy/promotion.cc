
#include <vector>
#include <iostream>

//! @note
//! 场景：用户在商场购买物品并结算时，需要选择不同的促销方案
//! 在单个处理函数内通过 if-else 的方式不可维护，后续新增和修改代码都很麻烦
//!
//! 这里将策略抽象出来，后续新增策略只需要新增 PromotionStrategy 的派生类
//! 修改策略也是修改一个具体派生类内的函数实现。
//! 
//! 并且在用户和具体策略实现之间使用了一个用于接口隔离的接口 Promotion
//! 封装了用户调用具体策略的逻辑，这个接口的内容在后续维护中基本稳定
//! 

////////////////////////////////////////////////////////////////////////

struct Date {
  size_t year;
  size_t month;
  size_t day;
};

class UserContext {
public:
  UserContext() = default;
  UserContext(Date d, bool v, size_t f, double a)
   : date(d), VIP(v), frequency(f), amount(a) {}

public:
  Date date;
  bool VIP;
  size_t frequency;
  
  double amount;
};

////////////////////////////////////////////////////////////////////////

//! @brief 
//! 这个基类是一个抽象类，是接口解耦的常见做法
//! 
class PromotionStrategy {
public:
  virtual double CalculatePro(const UserContext& ctx) = 0;
  virtual ~PromotionStrategy() = default;
};

class FestivalsPro : public PromotionStrategy {
  virtual double CalculatePro(const UserContext& ctx) {
    if (ctx.date.month == 1 && ctx.date.day == 1) {
      return ctx.amount * 0.7;
    }
  }
};

class VIPPro : public PromotionStrategy {
  virtual double CalculatePro(const UserContext& ctx) {
    if (ctx.VIP) {
      return ctx.amount * 0.9;
    }
  }
};

class RegularPro : PromotionStrategy {
  virtual double CalculatePro(const UserContext& ctx) {
    if (ctx.frequency % 10 == 0) {
      return ctx.amount - 10.0;
    }
  }
};

////////////////////////////////////////////////////////////////////////

//! @brief 
//! 这个类用于隔离 User 和 策略选择
//! 这使得具体促销策略的选择调用变得非常稳定（即这个类）
//! 
class Promotion {
public:
  Promotion(PromotionStrategy* ps = nullptr) : _ps(ps) { }
  ~Promotion() { }

public:
  void choose_strategy(PromotionStrategy* ps) { if (ps) { _ps = ps; } }

  double CalculatePro(const UserContext& ctx) {
    if (_ps)
      return _ps->CalculatePro(ctx);
    else
      return 0.0;
  }

private:
  PromotionStrategy* _ps;
};

////////////////////////////////////////////////////////////////////////

int main() {
  UserContext ctx({2024, 10, 4}, true, 3, 648.0);
  PromotionStrategy* ps = new VIPPro();
  
  Promotion* p = new Promotion(ps);
  auto res = p->CalculatePro(ctx);

  std::cout << res << std::endl;
}
