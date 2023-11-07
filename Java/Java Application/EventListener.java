import java.awt.*;

public class EventListener
{
    public static void main(String[]args)
    {
        Frame f = new Frame("Listener Test");
        f.addWindowListener(new ExitListener());
        f.setLayout(new FlowLayout());

        Button b = new Button("This is test");
        //버튼에다가(object) 함수를 연결하기 위해서는 .add... 다양한 이름의 리스너 사용
        //이 함수는 인터페이스에서 상속받은 클래스를 가지고 오버라이딩 해준다. 그 만든걸 .add 뒤에다 써준다.
        AllComponentListener btnListener = new AllComponentListener("Button 1");
        b.addActionListener(new UserActionListener("Button 2"));
        b.addComponentListener(btnListener);
        b.addFocusListener(btnListener);
        b.addInputMethodListener(btnListener);
        b.addKeyListener(btnListener);
        b.addMouseListener(btnListener);
        //b.addMouseMotionListener(new ALLListener());
        f.add(b);

        TextField t = new TextField("This is test!");
        AllComponentListener txtListener = new AllComponentListener("Text");
        t.addTextListener(new UserTextListener("Text"));
        t.addActionListener(new UserActionListener("Text"));
        t.addComponentListener(txtListener);
        t.addFocusListener(txtListener);
        t.addInputMethodListener(txtListener);
        t.addKeyListener(txtListener);
        t.addMouseListener(txtListener);
        //t.addMouseMotionListener(new AllListener());

        f.add(t);

        f.setSize(300,200);
        f.setVisible(true);
    }

}
