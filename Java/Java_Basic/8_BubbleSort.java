import java.util.Scanner;

public class BubbleSort
{
    public static void main(String[]args)
    {
        int [] data = new int[5];
        int i,j,t;
        Scanner scan = new Scanner(System.in);

        for(i=0;i<5;i++)  					//Enter the value
        {
            System.out.print("Enter the value of "+i);
            data[i] = scan.nextInt();
        }
        for(i=3; i>=0; i--)         //The last bubble decrease from n-1 to 0
        {
            for(j=0;j<=i;j++)       //Comparing a pair of bubble from first to ith.
            {
                if(data[j]>data[j+1])		// Compare two consecutive pair.
                {
                    t=data[j];				//Exchange
                    data[j]=data[j+1];
                    data[j+1]=t;
                }
            }
        }
        for(i=0;i<5;i++)						//Print
            System.out.println(data[i]);

        /*
        *Minimum to Maximum
        int []data= new int [5];
		int i,j,t;
		Scanner scan = new Scanner(System.in);
		for(i=0;i<5;i++)
			data[i]=scan.nextInt();
		
		for(i=3;i>=0;i--)
		{
			for(j=0;j<=i;j++)
			{
				if(data[i]>data[j])
				{
					t=data[j];
					data[j]=data[j+1];
					data[j+1]=t;
				}
			}
		}
		for(i=0;i<5;i++)
			System.out.println(data[i]);
        */
    }
}
