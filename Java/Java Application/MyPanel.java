import java.awt.*;

public class MyPanel extends Panel
{
    public MyPanel()
    {
        panelReset();
    }
    public MyPanel(LayoutManager layout)
    {
        super(layout);
        panelReset();
    }
    public void panelReset()
    {
        setLayout(new FlowLayout());

        Button btn = new Button("Btn1");
        add(btn);

        btn = new Button("Btn2");
        add(btn);

        btn = new Button("Btn3");
        add(btn);
    }
}

