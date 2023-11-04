import java.awt.*;

public class WindowTest
{
    public static void main(String[]args)
    {
        //Frame : 기본 윈도우를 생성하고 관리하는 클래스
        Frame f = null;
        f=new Frame("This is test!");

        //윈도우관련 이벤트를 처리하는 event handler 등록하기
        //창에 들어갈 기본적인 윈도우를 추가해주겠다.
        f.addWindowListener(new ExitListener());

        //윈도우의 넓이 높이 지정
        f.setSize(300,200);

        //설정된 값으로 윈도우를 보이기
        f.setVisible(true);
    }

}
