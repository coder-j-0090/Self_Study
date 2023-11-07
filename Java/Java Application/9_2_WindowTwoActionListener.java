import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class WindowTwoActionListener implements ActionListener
{
    public WindowTwo w = null;
    public WindowTwoActionListener(WindowTwo w)
    {
        this.w = w;
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        System.exit(0);
    }
}

