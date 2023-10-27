import java.util.Set;
import java.util.HashSet;

public class Framework
{
    public static void main(String[]args)
    {
        Set<Integer> set = new HashSet<>();     //Or TreeSet
        set.add(1);     //삽입
        set.remove(1);  //제거
        set.size();         //Set에 크기를 반환한다.
    }

}
