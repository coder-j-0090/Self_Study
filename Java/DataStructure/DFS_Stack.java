public class DFS_Stack
{
    public static void main(String[]args)
    {
        Stack s = new Stack();
        int[]tree = {0,10,30,80,60,150,160,180,280,290};
        s.push(1);      //Push 1 to start.
        while(!s.isEmpty())
        {
            int idx = s.top();          //Push the 'top'(the value at the top) into temporary variable idx
            s.pop();
            System.out.println(tree[idx]);          //Print the value of idx from the tree array
            if(idx*2+1<tree.length)                 //If the value of idx*2+1 is smaller than the length of tree array
                //idx*2+1(right side of the tree) was pushed first, so it can be printed at last and the left one will be printed when you print at the end.
                s.push(idx * 2 + 1);
            if(idx*2<tree.length)                   //If the value of idx*2 is smaller than the length of tree array
                s.push(idx * 2);
           /*
           while loop에서는 조건이 만족되지 않는한 last statement가 끝나고 다시 위로 올라간다.(18번에서 다시 11로 올라가서
           idx*2+1과 idx*2가 tree.length보다 짧은동안 계속 실행된다.
            */
        }
    }

}
