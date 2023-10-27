import java.util.PriorityQueue;


public class Framework
{
    public static void main(String[]args)
    {
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();   //내림차순
        //PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());   //오름차순
        priorityQueue.add(1);       //priorityQueue 값 1 추가
        priorityQueue.add(2);       //priorityQueue 값 2 추가
        priorityQueue.offer(3); //priorityQueue 값 3 추가
        priorityQueue.poll();       //priorityQueue 에 첫번째 값을 반환하고 제거 비어있다면 null
        priorityQueue.remove();     //priorityQueue 에 첫번째 값 제거
        priorityQueue.clear();      //priorityQueue 에 초기화
        priorityQueue.peek();       //priorityQueue 에 첫번째 값 참조

    }

}
