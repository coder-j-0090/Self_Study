import java.util.Scanner;

public class SelectionSort
{
    public static void main(String[]args)
    {
        Scanner scan = new Scanner(System.in);
        int [] data = new int[4];
        int i,j,t;      //Declare variable t for future swap

        for(i=0;i<4;i++)
        {
            data[i] = scan.nextInt();
        }

        for(i=0;i<3;i++)
        {
            for(j=i+1;j<4;j++)
            {
                if(data[i]>data[j])
                {
                    t=data[i];
                    data[i]=data[j];
                    data[j]=t;
                }
            }
        }

        for(i=0;i<4;i++)
        {
            System.out.println(data[i]);
        }


        /*
        *Use selection sort to put the array in ascending order(smallest to largest).

        Scanner scan = new Scanner(System.in);
        int data[]= new int[4];
        int i,j,t;
        for(i=0;i<4;i++)
        data[i]=scan.nextInt();

        for(i=0;i<3;i++)
        {
            for(j=i+1;j<4;j++)
            {
                if(data[i]<data[j])
                {
                    t=data[i];
                    data[i]=data[j];
                    data[j]=t;
                }
            }
        }
        for(i=0;i<4;i++)
        {
            System.out.println(data[i]);
        }

         */

        /*
         * If the array is given.

            int []data= {23,45,67,234,5};
            int i,j,t;
            for(i=0;i<data.length-1;i++)
            {
                for(j=i+1;j<data.length;j++)
                {
                    if(data[i]>data[j])
                    {
                        t=data[i];
                        data[i]=data[j];
                        data[j]=t;
                    }
                }
            }
            for(i=0;i<data.length;i++)
            {
                System.out.println(data[i]);
            }


         */
    }
}
