# 两数之和

## 题目：
给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target的那两个整数并返回它们的数组下标
你可以假设每种输入只会对应一个答案并且你不能使用两次相同的元素，你可以按任意顺序返回答案

## 题目分析：
因为数组不是严格弱序的所以不能使用对撞双指针，因为题目说明元素去重并且只会对应一组答案所以可以使用哈希表
只需要查表找到是否存在一组数之和为target，最后返回两个数的下标

## 代码：
- CPP
```
vector<int> func(vector<int> &nums,int target){
    unordered_map<int,int> Hashmap;
    for(size_t i=0;i<nums.size();i+=1){
        int k=target-nums[i];
        auto it=Hashmap.find(k)
        if(it!=Hashmap.end()){
            return {it->second,static_cast<int>(i)};
        }
        Hashmap[nums[i]]=i;
    }
    return{}
}
```
- PY
```
def func(nums, target):
    Hashmap = {}
    for i, num in enumerate(nums):
        k = target - num
        if k in Hashmap:
            return [Hashmap[k], i]
        Hashmap[num] = i
    return []
```