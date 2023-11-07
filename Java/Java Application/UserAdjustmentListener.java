import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;

public class UserAdjustmentListener implements AdjustmentListener
{
    private String source = null;
    public UserAdjustmentListener(String source)
    {
        this.source = source;
    }

    @Override
    public void adjustmentValueChanged(AdjustmentEvent e)
    {
        //Invoked when the value of the adjustable has changed.
        System.out.println(source+" : adjustmentValueChanged");
    }
}