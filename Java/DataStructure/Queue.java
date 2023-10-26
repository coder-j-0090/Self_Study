public class Queue
{
    int[]queue = new int[10];
    int front=0;        //It's for location of front in the queue
    int rear=0;         //You push and pop the data from rear and front. Both of them are at the beginning, so they are 0.

    void push(int n)
    {
        queue[rear++]=n;      //Push n into the array.
        /*
        전처리는 rear++, 후처리는 ++rear. 전처리를 하면 rear에 n을 넣고 ++(1 증가)한다.
        그래서 queue.push를 줄이면 queue[rear++]=n;이 된다. rear에 n 넣고 1 증가하라는 소리이기에.
        */
        //큐 안에서 원래 rear칸에 n을 넣고 rear를 한칸뒤로 미룬다
    }
    int pop()           //Combine and pop and top from stack and made pop from queue.
    {
        int temp;
        //Declare temporary variable.
        temp=queue[front];
        //Push temporary variable 'temp' at the location of front in the queue.
        front++;
        //Add extra queue.
        return temp;
        //Return temporary variable temp.
    }
    boolean empty()
    {
        if(front==rear)
            return true;
        else
            return false;
    }

}
