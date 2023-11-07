import java.awt.*;
public class Reg
{
    public static void main(String[]args)
    {
        Frame f = new Frame("This is practice title bar!");
        f.addWindowListener(new ExitListener());
        f.setLayout(new GridLayout(2,1,20,20));

        Panel myPanel = new Panel();
        myPanel.setLayout(new GridLayout(3,3,20,20));
        Label lName = new Label("Name");
        lName.setAlignment(Label.CENTER);
        myPanel.add(lName);
        Label lAge = new Label("Age");
        lAge.setAlignment(Label.CENTER);
        myPanel.add(lAge);
        Label lWeight = new Label("Weight");
        lWeight.setAlignment(Label.CENTER);
        myPanel.add(lWeight);
        TextField tfName = new TextField();
        myPanel.add(tfName);
        TextField tfAge = new TextField();
        myPanel.add(tfAge);
        kgPanel kp = new kgPanel();
        myPanel.add(kp);
        Label empty = new Label("");
        myPanel.add(empty);
        Button addBtn = new Button("Add");
        addBtn.addActionListener(new UserActionListener());
        myPanel.add(addBtn);
        Label empty2 = new Label("");
        myPanel.add(empty2);
        f.add(myPanel);

        TextArea ta = new TextArea();
        f.add(ta);

        f.pack();
        f.setSize(500,500);
        f.setVisible(true);
    }
}

