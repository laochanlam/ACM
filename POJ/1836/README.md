[POJ-1836 Alignment](http://poj.org/problem?id=1836)
===
- LIS
- Dynamic Programming

對 左到右 及 右到左 分別做一次LIS，再從 1 - n 每個計算 LIS_left[i] + LIS_right[j] 可知每個位置(左邊和右邊)最多可以有多少人，然後再用 n 減去其人數，即為刪減的士兵。
