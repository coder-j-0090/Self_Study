import java.util.Scanner;

public class Methods
{
    public static void main(String[]args)
    {
        hello();
        int a,b;
        Scanner scan = new Scanner(System.in);
        a=scan.nextInt();
        b=scan.nextInt();

        sum(a,b);
        average(a,b);
        bye();
    }
    public static void hello()
    {
        System.out.println("hello");
    }
    public static void sum(int a, int b)
    {
        int c;
        c=a+b;
        System.out.println(c);
    }
    public static void average(int a, int b)
    {
        double d;
        d=(a+b)/2.0;
        System.out.println(d);
    }
    public static void bye()
    {
        System.out.println("bye");
    }
}
