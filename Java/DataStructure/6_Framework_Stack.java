import java.util.Stack;

public class Framework
{
    public static void main(String[]args)
    {
        Stack<Integer> stack = new Stack<>();   //int 형 스택 선언
        stack.push(1);      //stack 에 1 추가
        stack.push(2);      //stack 에 2 추가
        stack.push(3);      //stack 에 3 추가
        System.out.println(stack);
        stack.peek();            //stack 의 가장 상단의 값 출력
        stack.pop();             //stack 에 값 제거
        stack.size();            //stack 의 크기 출력: 2
        stack.empty();           //stack 이 비어있는데 check(비어있다면 true)
        stack.clear();           //stack 의 전체 값 제거(초기화)
    }

}
