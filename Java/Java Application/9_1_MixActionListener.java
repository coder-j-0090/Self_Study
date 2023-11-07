import javax.swing.*;
import java.awt.event.*;
import java.util.*;
public class MixActionListener implements ActionListener
{
    public Puzzle g = null;
    public MixActionListener(Puzzle topG)
    {
        g = topG;
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        mix();
    }
    public void mix()
    {
        g.butEm = new JButton(" ");
        int a[] = new int[15];
        Random r = new Random();
        for(int i=0;i<15;i++)
        {
            a[i]=r.nextInt(15)+1;
            for(int j=0;j<i;j++)
            {
                if(a[i]==a[j])
                {
                    i--;
                }
            }
        }
        //JButton j[] = {g.but1,g.but2,g.but3,g.but4,g.but5,g.but6,g.but7,g.but8,g.but9,g.but10,g.but11,g.but12,g.but13,g.but14,g.but15};
        Collections.shuffle(Arrays.asList(a));
        String[]strArr = new String[a.length];
        for(int i=0;i<strArr.length;i++)
        {
            strArr[i]=String.valueOf(a[i]);
        }
        for(int i=0;i<15;i++)
        {
            g.oneDBtns[i].setText(strArr[i]);
            //j[i] = new JButton(strArr[i]);  왜틀렷누?
            //System.out.println(j[i].getText());
        }
    }
}
