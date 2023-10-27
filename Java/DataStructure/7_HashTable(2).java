public class HashTable
{
    //If I make 3 lines.
    int[]data = {27,34,69,83,28,7,54,19,68,92,17};
    int[][]hashtable = new int[3][10];
    public static void main(String[]args)
    {
        HashTable ht = new HashTable();
        for(int i=0;i<ht.data.length;i++)
            ht.hashFunction(ht.data[i]);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<10;j++)
            {
                System.out.printf("%3d ",ht.hashtable[i][j]);
            }
            System.out.println();
        }
    }
    void hashFunction(int n)
    {
        int row = 0;
        int idx = n%10;
        if(hashtable[row][idx]==0)
            hashtable[row][idx]=n;
        else if(hashtable[row+1][idx]==0)
            hashtable[row+1][idx]=n;
        else
            hashtable[row+2][idx]=n;
    }


}
