import java.util.LinkedList;

public class Framework
{
    public static void main(String[]args)
    {
        LinkedList<Integer> list = new LinkedList<Integer>();
        list.addFirst(1);       //가장 앞에 데이터 추가
        list.addLast(2);        //가장 뒤에 데이터 추가
        list.add(3);                //데이터 추가
        list.add(1,10);     //인덱스 1에 데이터 10 추가
        list.removeFirst();             //가장 앞의 데이터 제거
        list.removeLast();              //가장 뒤의 데이터 제거
        list.remove();                  //생략시 0번째 index 제거
        list.remove(1);           //index 1 제거
        list.clear();                   //모든 값 제거
        System.out.println(list.get(0));        //0번째 인덱스 출력
        System.out.println(list.contains(1));   //list 에 1이 있는지 검색: true
        System.out.println(list.indexOf(1));    //1이 있는 index 반환 없으면 -1
        for(Integer i : list)       //for 문을 통한 전체출력
        {
            System.out.println(i);
        }
    }

}
