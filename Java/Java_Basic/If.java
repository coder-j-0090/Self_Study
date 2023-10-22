import java.util.Scanner;

public class If
{
    public static void main(String[]args)
    {
        //Find if the student is passed or failed. Also, each score should be higher than 40 and the total score of the test must be over 180.
        int a,b,c;
        Scanner scan = new Scanner(System.in);
        System.out.println("1. Enter the value of the first test: ");
        a=scan.nextInt();
        System.out.println("2. Enter the value of the second test: ");
        b=scan.nextInt();
        System.out.println("3. Enter the value of the third test: ");
        c=scan.nextInt();

        if(a>40&&b>40&&c>40&&(a+b+c)>180)
        {
            System.out.println("Pass");
        }
        else
        {
            System.out.println("Fail");
        }

    }
}
