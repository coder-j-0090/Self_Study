import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CheckActionListener implements ActionListener
{
    Puzzle g = null;
    public CheckActionListener(Puzzle topG)
    {
        g=topG;
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        if(g.but1.getText()=="1"&&g.but2.getText()=="2"&&g.but3.getText()=="3"&&g.but4.getText()=="4"&&g.but5.getText()=="5"&&g.but6.getText()=="6"&&g.but7.getText()=="7"&&g.but8.getText()=="8"&&g.but9.getText()=="9"&&g.but10.getText()=="10"&&g.but11.getText()=="11"&&g.but12.getText()=="12"&&g.but13.getText()=="13"&&g.but14.getText()=="14"&&g.but15.getText()=="15"&&g.butEm.getText()==" ")
        {
            g.labelCheck.setText("CORRECT!");
        }
        else
        {
            g.labelCheck.setText("TRY AGAIN!");
        }
    }
}

