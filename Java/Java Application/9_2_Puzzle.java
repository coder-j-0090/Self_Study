import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class Puzzle extends JFrame
{
    public JButton[][]btns = new JButton[4][4];
    public JPanel bord = null;
    public JPanel masPanel = null;
    public int[][]arr = new int[4][4];
    public int[]num = new int[16];
    public JButton master = null;

    public Puzzle()
    {
        //기본 세팅
        super("Dream Comp Puzzle");
        setLayout(new GridLayout(2,1,10,10));
        bord = new JPanel();
        add(bord);
        bord.setLayout(new GridLayout(4,4,10,10));
        masPanel = new JPanel();
        masPanel.setLayout(new FlowLayout());
        //마스터버튼
        master = new JButton("Master");
        master.addActionListener(new MasterActionListener(this));
        Dimension btnSize = new Dimension(482,216);
        master.setPreferredSize(btnSize);
        masPanel.add(master);
        add(masPanel);


        //j버튼 16개 만들고 1개는 빈걸로 해서 1~15까지 만들기
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                btns[i][j]= new JButton(Integer.toString(i*4+j+1));
                btns[i][j].addActionListener(new BtnActionListener(this));
                bord.add(btns[i][j]);
            }
        }
        btns[3][3].setText("");

        //우선 1차원 배열에 랜덤숫자 때려넣고
        Random rd = new Random();
        for(int i=0;i<num.length;i++)
        {
            num[i]=rd.nextInt(16)+1;
            for(int j=0;j<i;j++)
            {
                if(num[i]==num[j])
                {
                    i--;
                }
            }
        }   //여기까진 맞고

        //TODO: 1차원배열을 2차원 배열의 형태로 바꾸자 : 빈 2차원 배열에 1차원 배열값을 집어넣기(2차원배열을 1차원배열로 바꾸자)
        //1D 에서 2D로 바꾸는건 보고했다...
        int count = 0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(count==num.length)
                    break;
                arr[i][j] = num[count];
                count++;
            }
        }

        //TODO: 이제 arr 2차원배열을 setText 로 JButton 에 집어넣어보자
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                btns[i][j].setText(Integer.toString(arr[i][j]));
                if(btns[i][j].getText().equals("16"))
                {
                    btns[i][j].setText("");
                }
            }
        }



        pack();
        setSize(600,600);
        setVisible(true);
    }
    public static void main(String[]args)
    {
        Puzzle p = new Puzzle();
    }
}
