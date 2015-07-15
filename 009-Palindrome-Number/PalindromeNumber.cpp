/*
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x<0)
        {
            return false;
        }
        int index=1;
        while(x/index>=10)
        {
            index*=10;
        }
        while(x!=0)
        {
            int first=x/index;
            int last=x%10;
            if(first!=last)
            {
                return false;
            }
            x=x%index/10;
            index/=100;
        }
        return true;
    }
};

int main()
{
    Solution object;
    cout<<object.isPalindrome(146787641)<<endl;
}
