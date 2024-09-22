
#include <iostream>
#include <array>
#include <queue>
#include <vector>

struct Talent {
  bool mat_type;
  size_t mat_cost;
  size_t value;
  Talent() = default;
};

void try_unlock(
  struct Talent& curr_talent,
  size_t& mid_cost, size_t& high_cost,
  size_t& curr_coin, size_t& curr_packet,
  size_t& curr_value, bool& unlock
) {
  if (curr_talent.mat_type) {
    if (curr_packet >= curr_talent.mat_cost) {
      curr_packet -= curr_talent.mat_cost;
      curr_value += curr_talent.value;
      unlock = true;
    } else if (curr_coin >= curr_talent.mat_cost * high_cost) {
      curr_coin -= curr_talent.mat_cost * high_cost;
      curr_value += curr_talent.value;
      unlock = true;
    }
  } else {
    if (curr_coin >= curr_talent.mat_cost * mid_cost) {
      curr_coin -= curr_talent.mat_cost * mid_cost;
      curr_value += curr_talent.value;
      unlock = true;
    }
  }
}

void search(
  size_t curr_ID, size_t n_talent,
  std::vector<struct Talent>& talents,
  std::vector<size_t>& tal_prev,
  size_t mid_cost, size_t high_cost,
  size_t curr_coin, size_t curr_packet,
  std::queue<size_t> waiting_IDs,
  size_t curr_value, size_t& max_value
) {
  for (int i = 2; i <= n_talent; ++i) {
    if (tal_prev[i] == curr_ID) 
      waiting_IDs.push(i);
  }

  auto curr_talent = talents[curr_ID];
  bool unlock = false;
  try_unlock(curr_talent, mid_cost, high_cost, 
             curr_coin, curr_packet, curr_value, unlock);

  if (!unlock) {
    max_value = std::max(max_value, curr_value);
    return;
  }

  while (!waiting_IDs.empty()) {
    size_t next_ID = waiting_IDs.front();
    waiting_IDs.pop();
    search(next_ID, n_talent,
           talents,
           tal_prev,
           mid_cost, high_cost,
           curr_coin, curr_packet,
           waiting_IDs,
           curr_value, max_value);
  }
}

int main() {
  size_t n_talent;
  std::cin >> n_talent;

  size_t mid_cost, high_cost;
  std::cin >> mid_cost >> high_cost;

  size_t user_coin, user_packet;
  std::cin >> user_coin >> user_packet;

  // index starts at 2
  std::vector<size_t> tal_prev{std::initializer_list<size_t>{0, 0}};
  for (int i = 1; i < n_talent; ++i) {
    size_t tmp;
    std::cin >> tmp;
    tal_prev.push_back(tmp);
  }

  // index starts at 1 : ID -> talents
  std::vector<struct Talent> talents; 
  talents.push_back(Talent());
  for (int i = 0; i <  n_talent; ++i) {
    struct Talent talent;
    std::cin >> talent.mat_type >> talent.mat_cost >> talent.value;
    talents.push_back(talent);
  }

  size_t max_value = 0;
  std::queue<size_t> waiting_IDs;
  search(1, n_talent,
         talents,
         tal_prev, 
         mid_cost, high_cost, 
         user_coin, user_packet, 
         waiting_IDs, 
         0, max_value);
  std::cout << max_value;
}
