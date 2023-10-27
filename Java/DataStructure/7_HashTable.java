public class HashTable      //메모리를 투자해서 속도를 높인다.
{
    //If data field is outside of main method, it can be an easy access to any methods.
    int[]data = {127,34,69,83,28,7,54,19,68,92};
    int[][]hashtable = new int[2][10];         //Set the value of them. Otherwise, it's all 0.
    //객체 안만들고 쓰는게 static
    public static void main(String[]args)
    {
        HashTable ht = new HashTable();
        for(int i=0;i<ht.data.length;i++)
            ht.hashFunction(ht.data[i]);
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<10;j++)
                System.out.printf("%3d ",ht.hashtable[i][j]);
            System.out.println();
        }
    }
    void hashFunction(int n)
    {
        int row = 0;
        int index = n%10;

        if(hashtable[row][index]==0)        //If it's empty, it must be 0.
            hashtable[row][index]=n;        //insert the value of n to 'hashtable[row][index]'.
        else
            hashtable[row+1][index]=n;      //if it's not 0(empty), then +1 to the row(write it at the next row).
    }

}
