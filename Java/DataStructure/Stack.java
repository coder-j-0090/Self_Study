public class Stack
{
    int []stk = new int[10];
    int cnt=0;

    void push(int n)
    {
        stk[cnt++]=n;
    }
    void pop()
    {
        cnt--;
    }
    int top()
    {
        return stk[cnt-1];
    }
    boolean isEmpty()
    {
        if(cnt!=0)
            return false;
        else
            return true;
    }

}
