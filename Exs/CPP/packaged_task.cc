
#include <iostream>
#include <future>
#include <thread>
#include <functional>

// 模拟一个耗时的任务
int slow_task(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2));  // 模拟任务耗时
    return x * 2;
}

int main() {
    // 使用 packaged_task 包装任务
    std::packaged_task<int(int)> task(slow_task);
    
    // 获取关联的 future，用于稍后获取结果
    std::future<int> result = task.get_future();
    
    // 在新的线程中执行任务
    std::thread t(std::move(task), 10);
    
    // 执行任务时主线程可以做其他事情
    std::cout << "Task started, doing something else..." << std::endl;
    
    // 获取任务结果（阻塞直到任务完成）
    std::cout << "Result: " << result.get() << std::endl;
    
    // 等待线程结束
    t.join();
    
    return 0;
}
