import java.awt.*;

public class LayoutTest
{
    public static void main(String[]args)
    {
        Frame f = new Frame("This is title for LayoutTest 3!");
        f.addWindowListener(new ExitListener());

        //f.setLayout(new GridLayout());
        //f.setLayout(new GridLayout(6,3));         계산법 참조

        //행과 열 개수 및 수평, 수직간격을 설정(가로 세로 갭 간격)
        f.setLayout(new GridLayout(6,3,20,0));

        /*
         *행과 열 지정 생성자 호출
         * 행과 열 값이 주어지면 GridLayout 은 다음과 같은 방법으로 열과 행 개수를 개선하며
         * 화면에 컴포넌트를 배치한다.

         * [행=x, 열=0 or 행=x, 열=y 일때]
         * -즉 행 개수가 1이상일때, 지정한 열개수를 무시하고, 별도로 열개수를 계산한다.
         * 계산법
         *      열 개수=(추가한 총 컴포넌트 수/행개수)+1-(1/행개수)
         * [행 = 0, 열 = 0 일대]
         * 계산법
         *      열 개수=(추가한 총 컴포넌트 수/행개수)+1-(1/행개수)
         * [행 = 0, 열 = 0 일때]
         *      실행시간에 오류를 발생시킨다.
         */
        
        Button btn=new Button("버튼1");
        f.add(btn);

        btn=new Button("버튼2");
        f.add(btn);

        btn=new Button("버튼3");
        f.add(btn);

        btn=new Button("버튼4");
        f.add(btn);

        btn=new Button("버튼5");
        f.add(btn);

        btn=new Button("버튼6");
        f.add(btn);

        btn=new Button("버튼7");
        f.add(btn);

        f.setSize(300,200);
        f.setVisible(true);
    }
}
