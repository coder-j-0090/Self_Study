import java.util.Scanner;

public class WhileDo
{
    public static void main(String[]args)
    {
        //While repeats until it satisfy the certain condition.
        //do while is same as while, but whether it satisfy the condition or not, it doesn't
        int sum,i;
        sum=0;
        i=1;

        //As long as the condition is not satisfied, it repeats what's inside the bracket.
        while(i<=10)
        {
            sum+=i;
            //= 'sum=sum+i'
            i++;
            //= 'i=i+1'
        }
        System.out.println(sum);

        //Common denominator
        int num1, num2;
        Scanner scan = new Scanner(System.in);
        num1=scan.nextInt();
        num2=scan.nextInt();

        while(num1!=num2)
        {
            if(num1>num2)
            {
                num1=num1-num2;
            }
            else
            {
                num2=num2-num1;
            }
        }
        System.out.println("God : "+num1);

        //Least common multiple
        int i,num;
        Scanner scan = new Scanner(System.in);
        num=scan.nextInt();

        i=2;

        do
        {
            i=2;
            do
            {
                if(num%i==0)
                //If you found prime factor
                {
                    System.out.printf(i+" ");
                    //print the prime factor
                    num=num/i;
                    //change the number to num/i
                }
                else
                    //if you failed to find a prime factor
                {
                    i++;
                    //increase the prime factor by 1.
                }
            }while(i<=num);
            //When the number to divide is same as the original number,
        }while(num>0);
        //repeat until the number to divide is 0
    }
}
