import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ResetActionListener implements ActionListener
{
    public Puzzle g = null;
    public ResetActionListener(Puzzle topG)
    {
        g = topG;
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        for(int i=0;i<g.oneDBtns.length;i++)
        {
            g.oneDBtns[i].setText(Integer.toString(i));
        }
    }
}

