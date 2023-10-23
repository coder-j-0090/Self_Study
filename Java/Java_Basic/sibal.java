public class sibal
{
    public static void main(String[]args)
    {
        /*
        * Warm up
        int[][] data = new int[3][4];
        int i,j;

        for(i=0;i<3;i++)
        {
            for(j=0;j<4;j++)
            {
                data[i][j] = ((i*10)+10)+j;
                System.out.print(data[i][j]+" ");
            }
            System.out.println();
        }
        */

        //ZigZag
        int [][]data=new int[5][5];
        int i,j;

        for(i=0;i<=4;i++)
        {
            for(j=0;j<=4;j++)
            {
                if(i%2==0)
                    data[i][j]=5*i+(j+1);
                else
                    data[i][j]=5*(i+1)-j;
            }
        }
        for(i=0;i<=4;i++)
        {
            for(j=0;j<=4;j++)
            {
                System.out.printf("%2d ", data[i][j]);
            }
            System.out.println();
        }

    }
}
