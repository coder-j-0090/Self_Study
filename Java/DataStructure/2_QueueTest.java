public class QueueTest
{
    public static void main(String[]args)
    {
        //Make Queue.
        Queue queue = new Queue();

        //Push in.
        queue.push(1);
        queue.push(5);
        queue.push(8);
        queue.push(13);

        //Print(pop)
        System.out.println(queue.pop());
        System.out.println(queue.pop());
        System.out.println(queue.pop());
        System.out.println(queue.pop());
    }

}
