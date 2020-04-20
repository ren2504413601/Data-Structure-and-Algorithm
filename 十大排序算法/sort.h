#ifndef SORT_H
#define SORT_H
#include<vector>
#include<iostream>
/**
 * 十种排序方法的实现
*/
class Sort
{
private:
    /* data */
public:
    Sort();
    ~Sort();
    void swap(int& a, int& b);
    void print(std::vector<int>& array);
    // 冒泡排序
    std::vector<int> bubble_sort(std::vector<int>& array);
    // 选择排序
    std::vector<int> selection_sort(std::vector<int>& array);
    // 插入排序
    std::vector<int> inserction_sort(std::vector<int>& array);
    //希尔排序
    std::vector<int> shell_sort(std::vector<int>& array);
    // 归并排序
    void merge(int left, int right, std::vector<int>& array);
    std::vector<int> merge_sort(std::vector<int>& array);
    // 快速排序
    void random_quick_sort(std::vector<int>& array, int left, int right);
    int random_partion(std::vector<int>& array, int left, int right);
    int partion(std::vector<int>& array, int left, int right);
    std::vector<int> quick_sort(std::vector<int>& array);
    // 堆排序
    void max_heap_fixed(std::vector<int>& array, int cur_idx, int len);
    void make_max_heap(std::vector<int>& array, int len);
    std::vector<int> heap_sort(std::vector<int>& array);
    // 计数排序
    std::vector<int> count_sort(std::vector<int>& array);
    // 桶排序
    std::vector<int> bucket_sort(std::vector<int>& array);
    // 基数排序
    std::vector<int> radix_sort(std::vector<int>& array);
};
#endif