import java.awt.*;

public class Container
{
    public static void main(String[]args)
    {
        Frame f = new Frame("This is title bar!");
        f.addWindowListener(new ExitListener());
        f.setLayout(new BorderLayout());

        Button btn = new Button("WEST");
        f.add(btn,BorderLayout.WEST);

        Label l = new Label("상태바 입니다.");
        l.setBackground(Color.gray);
        f.add(l, BorderLayout.SOUTH);

        MyPanel myPanel = new MyPanel();
        f.add(myPanel, BorderLayout.CENTER);

        f.pack();
        f.setVisible(true);
    }

}
