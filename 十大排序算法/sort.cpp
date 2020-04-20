#include"sort.h"
#include<cstdlib>
#include<ctime>
Sort::Sort()
{
}
void Sort::swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void Sort::print(std::vector<int>& array)
{
    for (int i = 0; i < array.size(); ++i) std::cout<<array[i]<<",";
    std::cout<<std::endl;
}
std::vector<int> Sort::bubble_sort(std::vector<int>& array)
{
    if (array.size() == 1) return array;
    bool sorted = true;
    for (int i = 0; i < array.size()-1; ++i)
    {
        for (int j = array.size()-1; j > i; --j)
        {
            if (array[j] < array[j-1]) swap(array[j], array[j-1]);
            sorted = false;
        }
        if (sorted)
        {
            return array;
        }
    }
    return array;
}
std::vector<int> Sort::selection_sort(std::vector<int>& array)
{
    if (array.size() == 1) return array;
    for (int i = 0; i < array.size()-1; ++i)
    {
        int minIdx = i;
        for (int j = i+1; j < array.size(); ++j)
        {
            if (array[minIdx] > array[j]) minIdx = j;
        }
        if (minIdx != i) swap(array[i], array[minIdx]);
    }
    return array;
}
std::vector<int> Sort::inserction_sort(std::vector<int>& array) 
{
    if (array.size() == 1) return array;
    for (int i = 1; i < array.size(); ++i)
    {
        int preIdx = i - 1;
        int curVal = array[i];
        while(preIdx >= 0 && curVal < array[preIdx])
        {
            array[preIdx+1] = array[preIdx];
            preIdx--;
        }
        array[preIdx+1] = curVal;
    }
    return array;
}
std::vector<int> Sort::shell_sort(std::vector<int>& array) 
{
    int length = array.size();
    if (length == 1) return array;
    int inc = length;
    while (true)
    {
        inc /= 2;
        for (int k = 0; k < inc; ++k)
            for (int i = k + inc; i < length; i += inc)
            {
                int preIdx = i - inc;
                int curVal = array[i];
                while (preIdx >= 0 && curVal < array[preIdx])
                {
                    array[preIdx+inc] = array[preIdx];
                    preIdx -= inc;
                }
                array[preIdx+inc] = curVal;
            }
        if (inc == 1) break;
    }
    return array;
}
void Sort::merge(int left, int right, std::vector<int>& array)
{
    if (left >= right)
    {
        return ;
    } 
    // 先使每个子序列有序
    int mid = (left + right) / 2;
    merge(left, mid, array);
    merge(mid + 1, right, array);
    int i = left, j = mid + 1;
    std::vector<int> tmp;
    // 将两个有序表合并成一个有序表
    while (i <= mid && j <= right)
    {
        if (array[i] < array[j])
        {
            tmp.push_back(array[i]);
            i++;
        }
        else
        {
            tmp.push_back(array[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        tmp.push_back(array[i]);
        i++;
    }
    while (j <= right)
    {
        tmp.push_back(array[j]);
        j++;
    }
    for (i = 0; i < right - left + 1; ++i) array[i + left] = tmp[i];
}
std::vector<int> Sort::merge_sort(std::vector<int>& array)
{
    int length = array.size();
    if (length == 1) return array; 
    merge(0, array.size()-1, array); // 左闭右闭
    return array;
}
int Sort::partion(std::vector<int>& array, int left, int right)
{
    int pivot = array[right]; //选取尾端元素为基准
    int i = left, j; // i,j 快慢指针. i 前向指针，j后向指针
    for (j = left; j < right; ++j)
    {
        if (array[j] <= pivot)
        {
            swap(array[i], array[j]);
            i++;
        }
    }
    swap(array[i], array[right]); // 从 left 至位置 i都是小于等于 基准元素的数， i位置是基准元素
    return i;
}
int Sort::random_partion(std::vector<int>& array, int left, int right)
{
    int randIdx = rand() % (right - left + 1) + left; //随机选取基准
    swap(array[randIdx], array[right]);
    return partion(array, left, right);
}
void Sort::random_quick_sort(std::vector<int>& array, int left, int right)
{
    if (left < right)
    {
        int pivot = random_partion(array, left, right);
        random_quick_sort(array, left, pivot - 1);
        random_quick_sort(array, pivot+1, right);
    }
}
std::vector<int> Sort::quick_sort(std::vector<int>& array)
{
    int length = array.size();
    if (length == 1) return array; 
    // std::srand() 定义于头文件 <cstdlib> 生成随机种子
    // std::time() 定义于头文件 <ctime>
    std::srand (std::time(NULL));
    random_quick_sort(array, 0, length - 1); // 左闭右闭区间
    return array;
}
void Sort::make_max_heap(std::vector<int>& array, int len)
{
    for (int i = (len / 2); i >= 0; --i) max_heap_fixed(array, i, len);
}
// 二叉堆是一个数组，可以被看成一个近似的完全二叉树
// 除了最底层外，该树是完全充满的
void Sort::max_heap_fixed(std::vector<int>& array, int cur_idx, int len)
{
    int lchild = (cur_idx << 1) + 1, rchild = (cur_idx << 1) + 2;
    while (lchild <= len)
    {
        int large = cur_idx;
        if (lchild <= len && array[lchild] > array[cur_idx])
        {
            large = lchild;
        }
        if (rchild <= len && array[rchild] > array[large])
        {
            large = rchild;
        }

        if (large != cur_idx) 
        {
            swap(array[cur_idx], array[large]);
            cur_idx = large;
            lchild = (cur_idx << 1) + 1;
            rchild = (cur_idx << 1) + 2;
        }
        else break;   
    }
}

std::vector<int> Sort::heap_sort(std::vector<int>& array)
{
    int length = array.size() - 1;
    make_max_heap(array, length);
    for(int i = length; i > 0; --i)
    {
        swap(array[0], array[i]);
        max_heap_fixed(array, 0, i-1);
    }  
    return array;
}

std::vector<int> Sort::count_sort(std::vector<int>& array)
{

}
std::vector<int> Sort::bucket_sort(std::vector<int>& array)
{

}
std::vector<int> Sort::radix_sort(std::vector<int>& array)
{

}

Sort::~Sort()
{
}