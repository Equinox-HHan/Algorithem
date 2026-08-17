这里为你整理了**冒泡排序**、**选择排序**、**插入排序**和**归并排序**的原理解析与通用的 C++ 代码模板。

---

### 一、 冒泡排序 (Bubble Sort)

*   **核心思想**：重复遍历待排序序列，两两比较相邻元素，若顺序错误则交换。每轮遍历都会将当前未排序部分的最大（或最小）元素“浮”到末尾。
*   **优化点**：引入 `swapped` 标志位，如果某一趟遍历中没有发生任何交换，说明数组已经有序，提前结束。
*   **复杂度**：时间 $O(n^2)$，空间 $O(1)$。稳定排序。

#### C++ 模板
```cpp
#include <vector>
#include <utility>

void bubbleSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        // 每一轮将最大的元素沉到最后 (n - 1 - i)
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        // 如果没有交换发生，说明已经有序
        if (!swapped) break;
    }
}
```

---

### 二、 选择排序 (Selection Sort)

*   **核心思想**：每次从未排序区间中**选择最小（或最大）的元素**，放到已排序区间的末尾（即与未排序区间的首个元素交换位置）。
*   **特点**：交换次数少（至多 $n-1$ 次），但比较次数恒定为 $O(n^2)$。
*   **复杂度**：时间 $O(n^2)$，空间 $O(1)$。**不稳定排序**。

#### C++ 模板
```cpp
#include <vector>
#include <utility>

void selectionSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i; // 记录未排序部分的最小值索引
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[minIdx]) {
                minIdx = j;
            }
        }
        // 将找到的最小值交换到已排序区间的末尾
        if (minIdx != i) {
            std::swap(nums[i], nums[minIdx]);
        }
    }
}
```

---

### 三、 插入排序 (Insertion Sort)

*   **核心思想**：类似于整理扑克牌。将整个序列划分为“已排序”和“未排序”两部分。每次取未排序部分的第一个元素，在已排序部分中**从后向前扫描**，找到合适位置插入。
*   **特点**：在数据基本有序或小规模数据时效率极高。
*   **复杂度**：最差/平均 $O(n^2)$，最优 $O(n)$，空间 $O(1)$。稳定排序。

#### C++ 模板
```cpp
#include <vector>

void insertionSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        int key = nums[i]; // 当前需要插入的元素
        int j = i - 1;
        
        // 将大于 key 的元素向后移动一位
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        // 插入到合适的位置
        nums[j + 1] = key;
    }
}
```

---

### 四、 归并排序 (Merge Sort)

*   **核心思想**：基于**分治法 (Divide and Conquer)**。
    1. **分 (Divide)**：将当前区间一分为二，递归对左右两半进行归并排序。
    2. **治 (Conquer)**：递归终止条件是区间长度为 1（天然有序）。
    3. **合 (Merge)**：将两个已排序的子区间合并成一个大的有序区间（双指针法）。
*   **复杂度**：时间复杂度恒为 $O(n \log n)$，额外空间复杂度 $O(n)$。稳定排序。

#### C++ 模板（推荐预分配辅助数组版本）
```cpp
#include <vector>

// 合并两个有序子数组 nums[left..mid] 和 nums[mid+1..right]
void merge(std::vector<int>& nums, int left, int mid, int right, std::vector<int>& temp) {
    int i = left;      // 左子数组指针
    int j = mid + 1;   // 右子数组指针
    int k = left;      // temp 数组指针

    // 比较两个子数组的头部元素，较小者放入 temp
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) { // 使用 <= 保持算法稳定性
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    // 复制剩余元素
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    // 将合并好的数据拷贝回原数组
    for (int p = left; p <= right; ++p) {
        nums[p] = temp[p];
    }
}

// 递归分治函数
void mergeSortInternal(std::vector<int>& nums, int left, int right, std::vector<int>& temp) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    // 分
    mergeSortInternal(nums, left, mid, temp);
    mergeSortInternal(nums, mid + 1, right, temp);
    // 合
    merge(nums, left, mid, right, temp);
}

// 对外接口
void mergeSort(std::vector<int>& nums) {
    if (nums.empty()) return;
    std::vector<int> temp(nums.size()); // 提前分配空间，避免频繁创建销毁
    mergeSortInternal(nums, 0, nums.size() - 1, temp);
}
```

---

### 综合对比与总结

| 排序算法 | 平均时间复杂度 | 最好时间复杂度 | 最坏时间复杂度 | 空间复杂度 | 稳定性 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **冒泡排序** | $O(n^2)$ | $O(n)$ (有优化) | $O(n^2)$ | $O(1)$ | **稳定** |
| **选择排序** | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | **不稳定** |
| **插入排序** | $O(n^2)$ | $O(n)$ | $O(n^2)$ | $O(1)$ | **稳定** |
| **归并排序** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | **稳定** |

*注：**稳定性**指序列中相等的元素在排序前后的相对顺序是否保持不变。*