# 无重复字符串的最长子串

## 题目：
给定一个字符串s，请你找出其中不含有重复字符的最长子串的长度

## 关键词：
1. **连续子串**
2. **求解最长长度**

## 题目分析：
根据常见题型分析用不定长滑动窗口，处理不重复问题用一个ASCII容量的的计数数组
1. 右指针右移改变了什么状态（`count[s[right]]+=1`）
2. 什么情况下触发左指针右移（`count[s[right]]>1`）
3. 移动左指针之前要改变什么状态（`count[s[left]]-=1`）
4. 在什么位置更新全局答案：
>这道题目是滑动窗口求最大值类型，全局答案更新要放在while外侧
>while相当于审查员严格维护窗口合法性，只有当窗口绝对合法才能收集答案

## 代码：
- CPP
```
int func(string s)
{
    if(s.empty())
    {
        return 0;
    }
    int left=0,right=0;
    vector<char> count(256,0);
    int ans=0;
    for(right;right<s.size();right+=1)
    {
        count[s[right]]+=1;
        while(count[s[right]]>1)
        {
            count[s[left]]-=1;
            left+=1;
        }
        ans=max(ans,right-left+1);
    }
    return ans;
}
```
- PY
```
def func(s):
    if not s:
        return 0
    
    lookup = set()
    left = 0
    ans = 0
    
    for right in range(len(s)):
        # 只要当前字符已经在窗口里，就不断缩小左边界
        while s[right] in lookup:
            lookup.remove(s[left])
            left += 1
            
        lookup.add(s[right])
        ans = max(ans, right - left + 1)
        
    return ans
```
    

