import java.awt.*;

public class LayoutTest
{
    public static void main(String[]args)
    {
        //Frame :  기본 윈도우를 생성하고 관리하는 클래스
        Frame f = new Frame("이것은 타이틀에 제목입니다!");

        //윈도우 관련 이벤트를 처리하는 event handler 등록하기
        f.addWindowListener(new ExitListener());

        //Layout Manager 를 FlowLayout(가로(기본으로 가운데)로 배치된다) 으로 설정
        //f.setLayout(new FlowLayout());
        //오른쪽에 배치한다.
        //f.setLayout(new FlowLayout(FlowLayout.RIGHT));
        //왼쪽에 배치한다. 20은 가로왼쪽에 20px 여백, 50은 위에 50px 여백
        f.setLayout(new FlowLayout(FlowLayout.LEFT,20,50));

        //버튼 생성 및 버튼에 나타날 텍스트 지정
        Button btn = new Button("버튼 1");

        //버튼이 나타남(x,y) 위치및 넓이, 높이 지정
        //Layout Manager 가 설정되면 setBounds() 메소드는 무시된다.
        btn.setBounds(10,10,100,50);

        //버튼을 프레임 윈도우에 삽입
        f.add(btn);

        btn=new Button("버튼2");
        f.add(btn);

        btn=new Button("버튼3");
        f.add(btn);

        //윈도우 넓이 높이 지정
        f.setSize(300,200);

        //설정된 값으로 윈도우를 보이기
        f.setVisible(true);

    }

}
