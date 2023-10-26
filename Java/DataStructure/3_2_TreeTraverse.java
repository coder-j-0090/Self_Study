public class TreeTraverse
{
    //If there are 3 nodes, 1 is the top, 2 is the left, and the 3 is the right.
    int[]tree={10,30,80,60,150,160,180,280,290};
    //To make recursion, many methods should know the array of tree. So, it's a main member and stays outside of the main method.
    public static void main(String[]args)
    {
        TreeTraverse t = new TreeTraverse();        //TreeTraverse t is a tree
        t.preOrder(0);                  //Push 0 in to let the t know the beginning value(0 is a node number)
        System.out.println();
        t.postOrder(0);
        System.out.println();
        t.inOrder(0);
    }
    public void preOrder(int n)      //Same as DFS
            //Root is a(1), left is b(2), right is c(3). Pre-order is a(1), b(2), c(3)
    {
        int idx=n;
        System.out.println(tree[idx]);      //1, Print out root
        if(idx*2+1<tree.length)             //2. start from 0, idx*2+1
            //선생님 설명: if you start index with 0
            preOrder(idx*2+1);
        //쌤: left is index*2+1
        if(idx*2+2<tree.length)             //3. Start from 0 idx*2+2
            //쌤: right side is idx*2+2
            preOrder(idx*2+2);
    }
    public void inOrder(int n)
    {
        int idx=n;
        if(idx*2+1<tree.length)             //2
            inOrder(idx*2+1);
        System.out.println(tree[idx]);      //1
        if(idx*2+2<tree.length)             //3
            inOrder(idx*2+2);

    }
    public void postOrder(int n)
    {
        int idx=n;
        if(idx*2+1<tree.length)             //3
            postOrder(idx*2+1);
        if(idx*2+2<tree.length)             //2
            postOrder(idx*2+2);
        System.out.println(tree[idx]);      //1
    }

}
