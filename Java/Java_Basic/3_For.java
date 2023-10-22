import java.util.Scanner;

public class For
{
    public static void main(String[]args)
    {
        //Count number 1 - 10
        int i;
        for(i=1;i<=10;i++)
        {
            System.out.println(i);
        }

        //2 Times Multiplication(1-9)
        i=0;
        for(i=1;i<=9;i++)
        {
            System.out.println("2X"+i+"="+i*2);
        }

        //Find the sum of number 1 to 10.
        i = 0;
        int sum=0;
        for(i=1;10>=i;i++)
        {
            sum=sum+i;
        }
        System.out.println("sum from 1 - 10 : "+sum);

        //Among the number from a to b, add the number to the variable 'sum' if the i is divisible by 3.
        int a = 0;
        int b = 0;
        i = 0;
        sum = 0;

        Scanner scan = new Scanner(System.in);
        System.out.println("The beginning value: ");
        a=scan.nextInt();
        System.out.println("The final value: ");
        b=scan.nextInt();

        for(i=a;i<b;i++)
        {
            if(i%3==0)
            {
                sum=sum+i;
            }
        }
        System.out.println("sum : "+sum);

    }
}
