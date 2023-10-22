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
        System.out.println("sum : "+sum);
    }
}
