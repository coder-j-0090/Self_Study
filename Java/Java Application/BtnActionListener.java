import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class BtnActionListener implements ActionListener
{
    public Puzzle p = null;
    public int btnx, btny;
    public String[][]test = new String[4][4];
    public BtnActionListener(Puzzle p)
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
                test[i][j]=Integer.toString(i*4+j+1);
            }
        }
        test[3][3] = "";
        boolean check = false;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                //if(Integer.toString(test[i][j]).equals(p.btns[i][j])&&p.btns[3][3].equals(""))
                if(test[i][j].equals(p.btns[i][j].getText()))
                {
                    check = true;
                }
            }
        }
        if(check==true)
        {
            new WindowTwo();
        }
        //e.getSource() method is used in the actionPerformed method to determine which button was clicked.
        String butNum = ((JButton)e.getSource()).getText();
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(butNum.equals(p.btns[i][j].getText()))
                {
                    btnx = i;
                    btny = j;
                }
            }
        }

        //up
        if( (btnx-1) >= 0 && "".equals(p.btns[btnx-1][btny].getText()))
        {
            p.btns[btnx-1][btny].setText(butNum);
            p.btns[btnx][btny].setText("");
        }
        //down
        if( (btnx+1)<=3 && "".equals(p.btns[btnx+1][btny].getText()))
        {
            p.btns[btnx+1][btny].setText(butNum);
            p.btns[btnx][btny].setText("");
        }
        //left
        if( (btny-1)>=0 && "".equals(p.btns[btnx][btny-1].getText()))
        {
            p.btns[btnx][btny-1].setText(butNum);
            p.btns[btnx][btny].setText("");
        }
        //right
        if( (btny+1)<=3 && "".equals(p.btns[btnx][btny+1].getText()))
        {
            p.btns[btnx][btny+1].setText(butNum);
            p.btns[btnx][btny].setText("");
        }
    }
}

