
## Intro

- solutions to the leetcode problems.
- some algo implementation.
- some infrastructure implementation.

## Makefile

1. Compile and Run

```sh
# run 24.cc
make 24

# run sort.cc
make sort
```

> ❗ main function required


2. Clean Debug/*.out

```sh
make clean
```

3. Quickly Push a Solution 

```sh
make push m="complete problem xxx"
```

## Dir

1. Check the `.vscode/` for vscode debug info.

2. U can put the tempary source file in `Debug/` and run it, and all the `.out` files are here.

3. The functional implementations are in `Impls/`.

4. Solutions to the problems from leetcode are in `Scripts/`.

## About problems' description

The description for each problem is generated by chatGPT, using the prompt like this:

> 
> 
> 我希望你为我完成以下任务：我发给你题目的原始描述，你发给我对应的 c++ doxygen 注释。
> 
> 示例如下：
> 
> ```txt
> 给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i > 个区间的开始和结束，并且 intervals 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end] 表示> 另一个区间的开始和结束。
> 
> 在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要> 的话，可以合并区间）。
> 
> 返回插入之后的 intervals。
> 
> 注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。
> 
> 示例 1：
> 
> 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
> 输出：[[1,5],[6,9]]
> 示例 2：
> 
> 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
> 输出：[[1,2],[3,10],[12,16]]
> 解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
> 
> 
> 提示：
> 
> 0 <= intervals.length <= 104
> intervals[i].length == 2
> 0 <= starti <= endi <= 105
> intervals 根据 starti 按 升序 排列
> newInterval.length == 2
> 0 <= start <= end <= 105
> ```
> 
> 输出的注释：
> 
> ```cpp
> //! @brief 
> //! 给你一个无重叠的，按照区间起始端点排序的区间列表 intervals，
> //! 其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，
> //! 并且 intervals 按照 starti 升序排列。
> //! 同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。
> //! 
> //! 在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 
> //! 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。
> //!
> //! 返回插入之后的 intervals。
> //!
> //! 注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。
> //! 
> //! @details 
> //! 0 <= intervals.length <= 104
> //! intervals[i].length == 2
> //! 0 <= starti <= endi <= 105
> //! intervals 根据 starti 按 升序 排列
> //! newInterval.length == 2
> //! 0 <= start <= end <= 105
> //! 
> //! @example 
> //! input:  intervals = [[1,3],[6,9]], newInterval = [2,5]
> //! output: [[1,5],[6,9]]
> //! 
> //! input:  intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], 
> //!         newInterval = [4,8]
> //! output: [[1,2],[3,10],[12,16]]
> //! 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
> //!
> ```
> 
> 注意，由于每行的长度不能太长（否则屏幕装不下）所以在 brief 和 example 中你需要像示例的这样进行适当的分行，明白了吗？


After this prompt, what you need to do is simply putting the leetcode's official description into chat box and waiting for the reply.