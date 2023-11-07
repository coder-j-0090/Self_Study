import java.awt.*;

public class kgPanel extends Panel
{
    public TextField weightTf = null;
    public Label measurement = null;
    public kgPanel()
    {
        tfAndKg();
    }
    public kgPanel(LayoutManager layout)
    {
        super(layout);
        tfAndKg();
    }
    public void tfAndKg()
    {
        weightTf = new TextField();
        add(weightTf);
        measurement = new Label("kg");
        add(measurement);
    }
}

