import java.util.Scanner;

public class Methods
{
    public static void main(String[]args)
    {
        hello();
        int a,b,s;
        double d;
        Scanner scan = new Scanner(System.in);
        a=scan.nextInt();
        b=scan.nextInt();

        s=sum(a,b);
        System.out.println("sum : "+s);
        d=average(s);
        System.out.println("average : "+d);

        bye();
    }
    public static void hello()
    {
        System.out.println("hello");
        //return c;(원래 있어야 되는데 안써도 됨)
    }
    public static int sum(int a, int b)
    {
        int c;
        c=a+b;
        return c;
    }
    public static double average(int c)
    {
        double d;
        d=c/2.0;
        return d;
    }
    public static void bye()
    {
        System.out.println("bye");
    }

}
