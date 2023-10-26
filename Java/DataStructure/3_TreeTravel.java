public class TreeTravel
{
    public static void main(String[]args)
    {
        int[]tree = {0,10,30,35,50,60,80,90};       //Insert 0 at the front, so the array will begin from 10(=tree[1])
        Queue q = new Queue();      //Make queue
        q.push(1);                  //Push 1 to start
        while(!q.empty())
        {
            int idx = q.pop();      //Take out the value of queue and save somewhere(variable idx), then add left child and right child, then print after pop
            //큐에 있는 값을 꺼내서 어딘가(인덱스)에 저장해 놓고, 인덱스의 왼쪽 자식과 오른쪽 자식을 추가 한 다음, 큐에서 꺼낸 사람을 출력한다.
            if(idx*2<tree.length)       //Left child
                q.push(idx*2);       //Push idx*2 if it matches the condition
            if(idx*2+1<tree.length)     //Right Child
                q.push(idx*2+1);     //Push idx*2+1 if it matches the condition
            System.out.println(tree[idx]);
        }
    }

}
