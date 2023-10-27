import java.util.Queue;
import java.util.LinkedList;

public class Framework
{
    public static void main(String[]args)
    {
        Queue<Integer> queue = new LinkedList<>();  //int 형 queue 선언. linkedlist 이용
        //Made Queue with LinkedList.(효율적)
        queue.add(1);       //queue 에 값 1 추가
        queue.add(2);       //queue 에 값 2 추가
        queue.offer(3);  //queue 에 값 3 추가(add 랑 똑같다)
        queue.poll();       //queue 에 첫번째 값을 반환하고 제거, 비어있다면 null.
        queue.peek();       //queue 의 첫번째 값 참조
        queue.remove();     //queue 에 첫번쨰 값 제거
        queue.clear();      //queue 초기화

    }

}
