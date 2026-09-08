/*

Problem Link: https://leetcode.com/problems/count-commas/
Problem 3870: Count Commas


1. We want to count how many commas appear when writing numbers from 1 to n.
2. A comma appears in numbers with at least 4 digits:
   1,000
   10,000
   100,000
3. So the first number that contains a comma is:
   x = 1000;
4. Then we count how many numbers from 1000 to n have a comma:
   n - 1000 + 1
5. For the next comma position, we multiply by 1000:
   1000 → thousands
   1000000 → millions
   1000000000 → billions
6. For each such position, we add:
   n - x + 1
7. So the loop:
   for(long long x = 1000; x <= n; x *= 1000)
   checks every power of 1000 where a new comma appears.

Example: n = 5000
For 1000:
5000 - 1000 + 1 = 4001
Numbers 1000 through 5000 each have at least one comma.
There is no 1,000,000 because 1,000,000 > 5000.
So:
Answer = 4001

One-line idea
For every comma position (1000, 1000000, 1000000000...), 
count how many numbers from that position to n contain that comma, and add them.


*/

class Solution {
public:
    long long countCommas(int n) 
    {
        int ans=0;
        for(long long x=1000;x<=n;x*=1000)
        {
            ans+=n-x+1;
        }
        return ans;
        
    }
};