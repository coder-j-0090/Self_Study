import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
//자바의 객체변ㅇ수는 다 포인터변수다. 변수가 포인터로 객체를 가리키게끔 만들었다. 여러개를 다룰때 배열의 이름으로 접근하는게 좋다.
class NumberMixActionListener implements ActionListener
{
    public Puzzle g = null;
    //1차원배열로 만드는게 좋은 이유는 1차원이 더 간단해서.

    public NumberMixActionListener(Puzzle topG)
    {
        g=topG;
        g.btns = new JButton[][]{
                {g.but1,g.but2,g.but3,g.but4},
                {g.but5,g.but6,g.but7,g.but8},
                {g.but9,g.but10,g.but11,g.but12},
                {g.but13,g.but14,g.but15,g.butEm}
        };
        directionCalculation();
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        System.out.println( ((JButton)e.getSource()).getText() );
    }
    public void directionCalculation()
    {
        String temp = "";
        String triTemp = "";
        for(int i=0;i<g.btns.length;i++)
        {
            for(int j=0;j<g.btns[i].length;j++)
            {
                if ((i+1)<=3&&(i+1)>=0)
                {
                    if(g.btns[i + 1][j].getText().equals(temp))
                        g.btns[i][j].setText(triTemp);
                    g.btns[i+1][j].setText(g.btns[i][j].getText());
                    triTemp = g.btns[i+1][j].getText();
                }
                else if (g.btns[i][j + 1].getText() == temp)
                {
                    g.btns[i][j].setText(triTemp);
                    g.btns[i][j+1].setText(g.btns[i][j].getText());
                    triTemp = g.btns[i][j+1].getText();
                }
                else if (g.btns[i - 1][j].getText() == temp)
                {
                    g.btns[i][j].setText(triTemp);
                    g.btns[i-1][j].setText(g.btns[i][j].getText());
                    triTemp = g.btns[i-1][j].getText();
                }
                else if (g.btns[i][j - 1].getText() == temp)
                {
                    g.btns[i][j].setText(triTemp);
                    g.btns[i][j-1].setText(g.btns[i][j].getText());
                    triTemp = g.btns[i][j-1].getText();
                }
                else
                {
                    System.out.print("");
                }
            }
        }
    }
}

