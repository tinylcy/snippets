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
