import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MasterActionListener implements ActionListener
{
    public Puzzle p = null;
    public MasterActionListener(Puzzle p)
    {
        this.p = p;
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                p.btns[i][j].setText(Integer.toString(i*4+j+1));
            }
        }
        p.btns[3][3].setText("");
    }
}

