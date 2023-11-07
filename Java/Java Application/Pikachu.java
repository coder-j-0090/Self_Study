import java.awt.*;

public class Pikachu extends Frame
{
    public static void main(String[]args)
    {
        Frame f = new Frame("This is title bar!");
        f.addWindowListener(new ExitListener());
        f.setLayout(new GridLayout(2,1,20,20));

        Label_TextField_Panel ltp = new Label_TextField_Panel();
        ltp.setLayout(new GridLayout(3,3,10,10));
        f.add(ltp);

        TextArea ta = new TextArea();
        f.add(ta);

        f.pack();
        f.setSize(500,500);
        f.setVisible(true);
    }
}
