import java.awt.*;

public class LayoutTest
{
    public static void main(String[]args)
    {
        //Frame : 기본윈도우를 생성하고 관리하는 클래스
        Frame f = new Frame("이것은 타이틀바 제목입니다!");

        //윈도우 관련 이벤트를 처리하는 event handler 등록하기
        f.addWindowListener(new ExitListener());

        //컴포넌트 배지 관리자를 쓰지 않을 것을 지정.
        f.setLayout(null);

       /*
       Button 클래스
       버튼 모양의 윈도우를 화면에 표시하고 관리하는 클래스
        */
        //버튼 생성 및 버튼에 나타날 텍스트 지정
        Button btn=new Button("버튼1");
        //버튼에 나타날(x,y) 위치 및 넓이, 높이 지정
        //레이아웃이 없을때(layout 이 null 일때 사용)
        btn.setBounds(10,10,100,50);
        //버튼을 프레임 윈도우에 삽입
        f.add(btn);

        btn=new Button("버튼2");
        btn.setBounds(100,20,50,100);
        f.add(btn);

        btn=new Button("버튼3");
        btn.setBounds(200,30,70,30);
        f.add(btn);

        //윈도우의 넓이 높이 지정
        f.setSize(300,200);

        //설정된 값으로 윈도우를 보이기
        f.setVisible(true);
    }

}
