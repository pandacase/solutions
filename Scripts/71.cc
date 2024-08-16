#include <vector>
#include <string>
#include <iostream>

//! @brief 
//! 给你一个字符串 path ，表示指向某一文件或目录的Unix风格绝对路径
//!（以 '/' 开头），请你将其转化为更加简洁的规范路径。
//! 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；
//! 此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；
//! 两者都可以是复杂相对路径的组成部分。
//! 任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。
//! 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。
//！ 
//! 请注意，返回的 规范路径 必须遵循下述格式：
//! 始终以斜杠 '/' 开头。
//! 两个目录名之间必须只有一个斜杠 '/' 。
//! 最后一个目录名（如果存在）不能 以 '/' 结尾。
//! 此外，路径仅包含从根目录到目标文件或目录的路径上的目录 (no '.' or '..')
//! 返回简化后得到的 规范路径 。
//! 
//! @details 
//! 1 <= path.length <= 3000
//! path 由英文字母，数字，'.'，'/' 或 '_' 组成。
//! path 是一个有效的 Unix 风格绝对路径。
//! 
//! @example 
//! input:  path = "/home/"
//! output: "/home"
//! 
//! input:  path = "/home//foo/"
//! output: "/home/foo"
//!
//! input:  path = "/home/user/Documents/../Pictures"
//! output: "/home/user/Pictures"
//!
//! input:  path = "/../"
//! output: "/" (根目录没有..)
//!
//! input:  path = "/.../a/../b/c/../d/./"
//! output: "/.../b/d"
//! 
//! @note
//! 
class Solution {
public:
  std::string 
  simplifyPath(std::string path) 
  {
    path.push_back('/');
    int size = path.size();
    
    std::vector<std::string> dirs;
    int dirBegin = 0;
    for (int i = 0; i < size; ++i) {
      if (path[i] == '/') {
        if (i > dirBegin) {
          auto dir = path.substr(dirBegin, i - dirBegin);
          if (dir == "..") {
            if (dirs.size() > 0)
              dirs.pop_back();
          } else if (dir != ".")
            dirs.push_back(dir);
        }
        dirBegin = i + 1;
      }
    }

    path.clear();
    for (auto& dir : dirs) {
      path.push_back('/');
      path.append(dir);
    }
    if (path.size() == 0) path = "/";
    return path;
  }
};


int main() {
  Solution sol;

  auto ans = sol.simplifyPath(
    "/home/user/Documents/../Pictures"
  );

  //! 0  
  std::cout << ans << std::endl;

  //! 1
  // for (auto & a : ans)
  //   std::cout << a << " ";
  // std::cout << std::endl;

  //! 2
  // for (auto & vec : ans) {
  //   for (auto & a : vec) 
  //     std::cout << a << " ";
  //   std::cout << std::endl;
  // }
}
