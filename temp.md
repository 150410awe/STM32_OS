1.
general > internal > address_structh > general > memory > distribution > address
异常处理与异常类型实现....
2.
namespace kernel::memory {
     // 初始化完整的memory数组
    constexpr std::array<memory, block_num> memory_array = create_memory_array(std::make_index_sequence<block_num>());
    inline static std::queue<subscript_t> empty_memory_queue = []() {
        std::queue<subscript_t> q;
        // 这里i = 0只是临时. 因为内核内存不算
        for (subscript_t i = 0; i < block_num; i++)
            q.push(i);
        return q;
    }();
    一定设好内核内存区间
}
...