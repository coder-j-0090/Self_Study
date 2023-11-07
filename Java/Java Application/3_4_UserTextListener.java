import java.awt.event.TextEvent;
import java.awt.event.TextListener;

public class UserTextListener implements TextListener
{
    private String source = null;
    public UserTextListener(String source)
    {
        this.source = source;
    }
    @Override
    public void textValueChanged(TextEvent e)
    {
        //Invoked when the value of the test has changed.
        System.out.println(source+" : UserTextListener");
    }
}




