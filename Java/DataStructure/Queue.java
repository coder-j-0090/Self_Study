public class Queue
{
    int[]queue = new int[10];
    int front=0;
    int rear=0;

    void push(int n)
    {
        queue[rear++]=n;
    }
    int pop()
    {
        int temp;
        temp=queue[front];
        front++;
        return temp;
    }
    boolean empty()
    {
        if(front==rear)
            return true;
        else
            return false;
    }

}
