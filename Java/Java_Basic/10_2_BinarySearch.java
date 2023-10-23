import java.util.Scanner;

public class BinarySearch
{
    public static int[] data = new int[100];
    public static void main(String[] args)
    {
        int key, ans, i;

        for(i=0;i<100;i++)
            data[i]=i*3;

        Scanner scan = new Scanner(System.in);
        key=scan.nextInt();

        ans=bs(0,99,key);
        if(ans>0)
            System.out.println(ans);
        else
            System.out.println("no match");

        System.out.println(ans);
    }

    public static int bs(int left, int right, int key)
    {
        int mid;
        mid=(left+right)/2;

        if(data[mid]==key)
            return mid;
        else if(left+1==right)
            return -1;
        else
        {
            if(data[mid]>key)
            {
                return bs(left, mid, key);
            }
            else
            {
                return bs(mid, right, key);
            }
        }
    }
}

