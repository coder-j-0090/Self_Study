import java.util.Scanner;

public class StackTest
{
    public static void main(String[]args)
    {
        Stack stack = new Stack();
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter the number: ");
        int num = scan.nextInt();
        while(num>0)
        {
            int num1=num%2;     //나머지를 계산하고
            num=num/2;          //숫자를 줄여라
            stack.push(num1);   //그리고 스택에 넣어라
        }
        //stack.print();
        //for(int i=stack.cnt;i>=0;i--)    //Stack 클래스에서 index가 하나씩 늘때마다 cnt도 늘려놔서 스택의 전체길이를 보여준다.

        while(!stack.empty())
        {
            System.out.printf("%d",stack.top());
            stack.pop();
        }
    }

}
