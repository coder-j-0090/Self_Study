import java.awt.*;

public class Checkbox //만들어둔 클래스의 함수들을 실행시켜야 한다.
{
    public Checkbox(String s) {
    }

    public static void main(String[]args)
    {
        Frame f = new Frame("Listener Test");
        f.addWindowListener(new ExitListener());
        f.setLayout(new FlowLayout());

        Checkbox c1 = new Checkbox("Checkbox 1");
        c1.setBackground(Color.white);
        AllComponentListener listener = new AllComponentListener("Checkbox");
        c1.addItemListener(new UserItemListener("Checkbox"));
        c1.addComponentListener(listener);
        c1.addFocusListener(listener);
        c1.addInputMethodListener(listener);
        c1.addKeyListener(listener);
        c1.addMouseListener(listener);
        //b.addMouseMotionListener(new ALLListener());

        f.add(c1);

        Choice c2 = new Choice();
        c2.setBackground(Color.white);
        listener = new AllComponentListener("Select Button");
        c2.addItemListener(new UserItemListener("Select Button"));
        c2.addComponentListener(listener);
        c2.addFocusListener(listener);
        c2.addInputMethodListener(listener);
        c2.addKeyListener(listener);
        c2.addMouseListener(listener);
        //b.addMouseMotionListener(new ALLListener());
        c2.add("Option 1");
        c2.add("Option 2");
        c2.add("Option 3");

        f.add(c2);

        f.setSize(500,800);
        f.setVisible(true);
    }
}

