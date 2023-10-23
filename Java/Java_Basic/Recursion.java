import java.util.Scanner;

public class Recursion
{
    public static void main(String[] args)
    {
        //fibonacci
        int num,ans;
        Scanner scan = new Scanner(System.in);
        num=scan.nextInt();
        ans=fibo(num);
        System.out.println(ans);
    }
    public static int fibo(int num)		//0,1,2 로 셀 경우
    {
        if(num==0)
            return 0;
        else if(num==1)
            return 1;
        else
            return fibo(num-1)+fibo(num-2);
    }


}
