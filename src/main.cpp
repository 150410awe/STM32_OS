#include "../include_set.h"
#include "1.h"
#include "../kernel_include/memory/call.h"
#include "../kernel_include/memory/memory.h"
#include "../general/internal/vector.h"

using namespace kernel::call;
using namespace kernel::memory;
using namespace general;

void print_use_memory() {
    println("=== Current Memory Usage ===");

    for (auto& block : use_memory) {
        print("Address: ");
        print(block.first);
        print(" Size: ");
        print(block.second);
        println();
    }
}

void test_empty_memory_queue() {
    println("=== Testing empty memory queue ===");

    for (auto& memory : empty_memory_queue) {
        print("address_interval: ");
        print(memory.address_interval.start);
        print(" - ");
        print(memory.address_interval.end);
        print(" Size: ");
        print(memory.size());
        println();
    }
}

// 测试 vector 功能
void test_vector() {
    println("=== Testing vector.h ===");
    println();
    
    // 测试1: 默认构造函数
    println("Test 1: Default constructor");
    vector<int> v1;
    println("  Default vector created");
    print("  Size: ");
    println(v1.size);
    print("  Capacity: ");
    println(v1.capacity);
    println();
    
    print_use_memory();
    test_empty_memory_queue();

    // 测试2: 带容量的构造函数
    println("Test 2: Constructor with capacity");
    vector<int> v2(5);
    println("  Vector with capacity 5 created");
    print("  Size: ");
    println(v2.size);
    print("  Capacity: ");
    println(v2.capacity);
    println();
    
    print_use_memory();
    test_empty_memory_queue();

    // 测试3: push_back 操作
    println("Test 3: push_back operation");
    for (int i = 0; i < 10; i++) {
        v2.push_back(i * 10);
        print("  Pushed ");
        print(i * 10);
        print(" - Size: ");
        print(v2.size);
        print(" Capacity: ");
        println(v2.capacity);
    }
    println();
    
    // 测试4: operator[] 访问
    println("Test 4: operator[] access");
    for (int i = 0; i < v2.size; i++) {
        print("  v2[");
        print(i);
        print("] = ");
        println(v2[i]);
    }
    println();
    
    // 测试5: reserve 操作
    println("Test 5: reserve operation");
    print("  Before reserve - Capacity: ");
    println(v2.capacity);
    v2.reserve(20);
    print("  After reserve(20) - Capacity: ");
    println(v2.capacity);
    print("  Size remains: ");
    println(v2.size);
    println();
    
    // 测试6: delete_data 操作
    println("Test 6: delete_data operation");
    print("  Before delete - Size: ");
    println(v2.size);
    v2.delete_data(2); // 删除索引为2的元素
    print("  After delete_data(2) - Size: ");
    println(v2.size);
    println("  Elements after deletion:");
    for (int i = 0; i < v2.size; i++) {
        print("  v2[");
        print(i);
        print("] = ");
        println(v2[i]);
    }
    println();
    
    // 测试7: clear 操作
    println("Test 7: clear operation");
    print("  Before clear - Size: ");
    println(v2.size);
    v2.clear();
    print("  After clear - Size: ");
    println(v2.size);
    print("  Capacity remains: ");
    println(v2.capacity);
    println();
    
    // 测试8: 重新使用已清除的 vector
    println("Test 8: Reusing cleared vector");
    for (int i = 0; i < 5; i++) {
        v2.push_back(i * 100);
    }
    print("  After push_back 5 elements - Size: ");
    println(v2.size);
    print("  Capacity: ");
    println(v2.capacity);
    println("  Elements:");
    for (int i = 0; i < v2.size; i++) {
        print("  v2[");
        print(i);
        print("] = ");
        println(v2[i]);
    }
    println();
    
    // 测试9: 边界测试 - 访问空 vector
    println("Test 9: Edge case - empty vector");
    vector<int> v3;
    print("  Empty vector size: ");
    println(v3.size);
    print("  Empty vector capacity: ");
    println(v3.capacity);
    println();
    
    print_use_memory();
    test_empty_memory_queue();
    
    // 测试10: 测试大尺寸 vector
    println("Test 10: Large vector test");
    vector<int> v4(100);
    for (int i = 0; i < 100; i++) {
        v4.push_back(i);
    }
    print("  Large vector size: ");
    println(v4.size);
    print("  Large vector capacity: ");
    println(v4.capacity);
    print("  First element: ");
    println(v4[0]);
    print("  Last element: ");
    println(v4[99]);
    println();
    
    print_use_memory();
    test_empty_memory_queue();
    
    println("=== Vector tests completed ===");
    println();
}

void setup() {
    // 初始化串口，波特率 115200
    begin();
    
    // 打印启动信息
    println("================================");
    println("  STM32 Vector Test");
    println("  Testing vector.h functionality");
    println("================================");
    println();
    
    // 运行 vector 测试
    test_vector();
    print_use_memory();
    test_empty_memory_queue();
    
    println("All vector tests completed!");
}

void loop() {
    // 空循环，用于保持系统运行
}

int main(void) {
    setup();
    
    while (1) {
        loop();
    }
    
    return 0;
}
