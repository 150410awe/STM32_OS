#pragma once

#include "foundation_type.h"
#include "../../kernel_include/memory/call.h"
#include "type_traits.h"

namespace general {
    using namespace kernel::call;
    using nullptr_t = decltype(nullptr);

    /**
     * @brief unique_ptr 类模板
     * @tparam T 指针类型
     * @tparam Deleter 删除器类型
     */
    template <typename T>
    class unique_ptr {
    public:
        using pointer = T*;
        using element_type = T;
        
        /**
         * @brief 默认构造函数
         */
        constexpr unique_ptr() noexcept : ptr_(nullptr) {}
        
        /**
         * @brief 空指针构造函数
         */
        constexpr unique_ptr(nullptr_t) noexcept : ptr_(nullptr) {}
        
        /**
         * @brief 指针构造函数
         * @param p 要管理的指针
         */
        explicit unique_ptr(pointer p) noexcept : ptr_(p) {}
        
        /**
         * @brief 移动构造函数
         * @param other 另一个 unique_ptr
         */
        unique_ptr(unique_ptr&& other) noexcept : ptr_(other.ptr_) {
            other.ptr_ = nullptr;
        }
        
        /**
         * @brief 移动构造函数（不同类型）
         * @tparam U 其他类型
         * @param other 另一个 unique_ptr
         */
        template <typename U>
        unique_ptr(unique_ptr<U>&& other) noexcept : ptr_(other.release()) {}
        
        /**
         * @brief 析构函数
         */
        ~unique_ptr() {
            if (ptr_) {
                // 调用对象的析构函数
                ptr_->~T();
                // 释放内存
                free(ptr_);
            }
        }
        
        /**
         * @brief 移动赋值运算符
         * @param other 另一个 unique_ptr
         * @return *this
         */
        unique_ptr& operator=(unique_ptr&& other) noexcept {
            if (this != &other) 
                reset(other.release());
            return *this;
        }
        
        /**
         * @brief 空指针赋值运算符
         * @param nullptr_t 空指针
         * @return *this
         */
        unique_ptr& operator=(nullptr_t) noexcept {
            reset();
            return *this;
        }
        
        unique_ptr(const unique_ptr&) = delete;
        unique_ptr& operator=(const unique_ptr&) = delete;
        element_type& operator*() const noexcept { return *ptr_; }
        pointer operator->() const noexcept { return ptr_; }
        pointer get() const noexcept { return ptr_; }
        explicit operator bool() const noexcept { return ptr_ != nullptr; }
        void swap(unique_ptr& other) noexcept { general::swap(ptr_, other.ptr_); }
        bool operator==(const unique_ptr& other) const noexcept { return ptr_ == other.ptr_; }
        bool operator!=(const unique_ptr& other) const noexcept { return ptr_ != other.ptr_; }
        bool operator==(nullptr_t) const noexcept { return ptr_ == nullptr; }
        bool operator!=(nullptr_t) const noexcept { return ptr_ != nullptr; }
        
        private:
        /**
         * @brief 释放所有权
         * @return 原始指针
         */
        pointer release() noexcept {
            pointer p = ptr_;
            ptr_ = nullptr;
            return p;
        }
        public:
        /**
         * @brief 重置指针
         * @param p 新指针
         */
        void reset(pointer p = nullptr) noexcept {
            pointer old_ptr = ptr_;
            ptr_ = p;
            if (old_ptr) {
                // 调用对象的析构函数
                old_ptr->~T();
                // 释放内存
                free(old_ptr);
            }
        }
        pointer ptr_;          // 指向管理对象的指针

    };
    
    /**
     * @brief make_unique 辅助函数
     * @tparam T 类型
     * @tparam Args 构造参数类型
     * @param args 构造参数
     * @return unique_ptr<T>
     */
    template <typename T, typename... Args>
    unique_ptr<T>&& make_unique(Args&&... args) {
        T* ptr = static_cast<T*>(malloc(sizeof(T)));
        if (ptr) 
            // 在分配的内存上构造对象
            new (ptr) T(forward<Args>(args)...);

        return move(unique_ptr<T>(ptr));
    }
    template <typename T>
    unique_ptr<T>&& malloc_unique(size_t size) {
        return move(unique_ptr<T>(static_cast<T*>(malloc(sizeof(T) * size))));
    }
}