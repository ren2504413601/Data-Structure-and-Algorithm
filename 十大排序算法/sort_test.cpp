#include"sort.h"
int main()
{
    std::vector<int> test = {5, 2, 7, 6, 3, 1};
    Sort sol;
    std::vector<int> ans = sol.heap_sort(test);
    sol.print(ans);
    return 0;
}