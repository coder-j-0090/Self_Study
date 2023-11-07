import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class WindowTwo extends JFrame
{
    public JLabel cong = new JLabel("Congratulation! You finished!");
    public JButton ok = new JButton("DONE");
    WindowTwo()
    {
        super("Congratulation!");
        setLayout(new GridLayout(2,1,10,10));
        cong.setHorizontalAlignment(JLabel.CENTER);
        add(cong);
        ok.addActionListener(new WindowTwoActionListener(this));
        add(ok);

        pack();
        setSize(300,600);
        setVisible(true);
    }
    public static void main(String[]args)
    {
        WindowTwo w = new WindowTwo();
    }

}

