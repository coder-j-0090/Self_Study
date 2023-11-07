import javax.swing.*;
import java.awt.*;

public class SimpleTest extends JFrame
{
    public String[]head;
    public String[][]contents;
    public JTable t;
    public JScrollPane jsp;
    public SimpleTest() {
        super("JTABLETEST");    //Super 가 JFrame 이다. 상속을 해준 부모클래스를 가르킨다. THIS 는 자기자신을 가르킨다.
        setLayout(new FlowLayout());

        head = new String[]{"Name", "Eng", "Math"};
        contents = new String[][]{
                {"Mark", "98", "99"},
                {"Rosa", "93", "88"},
                {"Alex", "99", "36"}
        };

        t = new JTable(contents, head);
        jsp = new JScrollPane(t);
        add(jsp);

        //pack();
        setSize(500, 500);
        setVisible(true);
    }
}
