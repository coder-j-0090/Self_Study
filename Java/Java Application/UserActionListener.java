import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UserActionListener implements ActionListener
{
    private String source = null;
    public UserActionListener(String source)
    {
        this.source = source;
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        //Invoked when an action occurs.
        System.out.println(source+": actionPerformed()");
    }
}

