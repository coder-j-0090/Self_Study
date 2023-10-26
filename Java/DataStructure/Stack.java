public class Stack
{
    int[]stack = new int[10];
    int cnt=0;
    public void push(int n)
    {
        stack[cnt++]=n;
    }
    public void pop()
    {
        cnt--;
    }
    public int top()
    {
        return stack[cnt-1];
//stack 에서 마지막값을 보려면 cnt-1을 해라. 10개의 스택이 있다면 index는 0~9다. 그래서 cnt-1을 해야 마지막것이 보인다.
    }
    public boolean empty()
    {
        if(cnt!=0)
            return false;
        else
            return true;
    }
    void print()
    {
        int i;
        for(i=0;i<stack.length;i++)
        {
            System.out.println(stack[i]);
        }
    }

}
