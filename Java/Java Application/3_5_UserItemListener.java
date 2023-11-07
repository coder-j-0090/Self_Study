import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class UserItemListener implements ItemListener
{
    private String source = null;
    public UserItemListener(String source)
    {
        this.source=source;
    }
    @Override
    public void itemStateChanged(ItemEvent e)
    {
        //Invoked when an item has been selected or deselected.
        System.out.println(source+" : itemStateChanged");
    }
}
