import java.util.Hashtable;
import java.util.Map;

public class Framework
{
    public static void main(String[]args)
    {
        //Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();     //Integer, Integer 타입 선언
        Hashtable<String, String> ht = new Hashtable<String, String>();     //Hashtable 선언

        ht.put("1","Hello1");		//ht.put(key,value)
        ht.put("2","World2");
        ht.put("3","Hello3");
        ht.put("4","Wrold4");
        ht.put("2","WorldWorld2");      //key2에 덮어쓰기
        ht.remove("2");     //삭제
        System.out.println(ht);     //결과출력
        System.out.println("Size: "+ht.size());     //크기출력
        for(Map.Entry<String, String> e : ht.entrySet())        //전체출력
        {
            System.out.println("Key : "+e.getKey()+ ", Value: "+e.getValue());
        }
    }

    /*
     public class Collection
     {
         Stack<Integer> stack = new Stack<>();
         Queue<Integer> queue = new LinkedList<>();
         LinkedList<Integer> list = new LinkedList<>();
     }

    */
}
