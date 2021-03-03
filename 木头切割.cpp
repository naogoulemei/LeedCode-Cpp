
/*

字节高频面试题，木头切割

题目描述
给定长度为n的数组，每个元素代表一个木头的长度，木头可以任意截断，从这堆木头中截出至少k个相同长度为m的木块。已知k，求max(m)。

ps: 截断的长度必须是整数

输入两行，第一行n, k，第二行为数组序列。输出最大值。

输入
5 5
4 7 2 10 5
输出
4

*/


// 方法一：暴力法

// input n, k;
int maxV = max(a[0 ~ n - 1]);
int res = 0;
int m = 1;
while (m <= maxV)
{
    int cnt = 0;
    for (int i = 0; i < n; i ++ ) cnt += a[i] / m;
    if (cnt >= k) res = max(res, m);  // 如果当前可以截出来超过k段，就更新结果
    m ++;
}

cout << res << endl;

//方法二：二分法

bool isFit(vector<int>& nums, int k, int mid)
{
	int count = 0;
	for (int i = 0; i < nums.size(); ++i) {
		count += nums[i] / mid;
	}
	return count >= k;
}

int maxM(vector<int>& nums, int k)
{
	int low = 1;
	int hight = *max_element(nums.begin(), nums.end());
	
	int ans = -1;

	while (low <= hight)
	{
		int mid = low + (hight - low) / 2;
		if (isFit(nums,k,mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			hight = mid - 1; 
		}
	}
	return ans;
}