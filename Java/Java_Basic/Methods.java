import java.util.Scanner;

public class Methods
{
    public static void main(String[]args)
    {
        hello();
        int a,b,c,f,s;
        double d;
        Scanner scan = new Scanner(System.in);
        System.out.print("국어 : "); a=scan.nextInt();
        System.out.print("수학 : "); b=scan.nextInt();
        System.out.print("영어 : "); c=scan.nextInt();

        s=sum(a,b,c);									//Combines the three values and add them up.
        System.out.println("sum : "+s);
        d=average(s);									//Finding average using one variable.
        System.out.println("average : "+d);
        f=grade(a);										//Finding the letter grade with one variable.
        System.out.printf("grade : %c",f);
        System.out.println();
        bye();
    }
    //Void type of method that doesn't return anything.
    public static void hello()
    {
        System.out.println("성적 처리 프로그램");
    }
    public static int sum(int a, int b, int c)
    {
        int d;
        d=a+b+c;
        return d;
    }
    public static double average(int d)
    {
        double c;
        c=d/3.0;
        return c;
    }
    public static char grade(double a)
    {
        if(a>=90)
        {
            return 'A';									//return 'A' -> use ' ' for char type
        }
        else if(a>=80)
        {
            return 'B';
        }
        else if(a>=70)
        {
            return 'C';
        }
        else if(a>=60)
        {
            return 'D';
        }
        else
        {
            return 'F';
        }
    }
    public static void bye()
    {
        System.out.println("bye");
    }


}
