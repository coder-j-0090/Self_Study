import java.awt.*;

public class Container
{
    public static void main(String[]args)
    {
        Frame f = new Frame("This is title bar!");
        f.addWindowListener(new ExitListener());
        Dialog dialog = new Dialog(f, "Dialog Test");

        dialog.setLayout(new FlowLayout());

        dialog.setLayout(new FlowLayout());

        Button btn = new Button("Button1");
        dialog.add(btn);

        btn = new Button("Button2");
        dialog.add(btn);

        btn = new Button("Button3");
        dialog.add(btn);

        dialog.pack();
        dialog.show();      //다이어로그를 화면에 보여주는 역활

        f.setSize(200,200);
        f.setVisible(true);
    }
}
