import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class EndActionListener implements ActionListener
{
    public Puzzle g = null;
    public EndActionListener(Puzzle topG)
    {
        g = topG;
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        System.exit(0);
    }
}

