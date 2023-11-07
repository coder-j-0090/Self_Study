import javax.swing.*;
import java.awt.*;

public class Puzzle extends JFrame {
    public JButton but1 = null;
    public JButton but2 = null;
    public JButton but3 = null;
    public JButton but4 = null;
    public JButton but5 = null;
    public JButton but6 = null;
    public JButton but7 = null;
    public JButton but8 = null;
    public JButton but9 = null;
    public JButton but10 = null;
    public JButton but11 = null;
    public JButton but12 = null;
    public JButton but13 = null;
    public JButton but14 = null;
    public JButton but15 = null;
    public JButton butEm = null;

    public JButton mix = null;
    public JButton reset = null;
    public JButton check = null;
    public JButton end = null;

    public JLabel labelCheck = null;

    public Panel upPanel = null;
    public Panel downPanel = null;
    public Panel belowPanel = null;

    public JButton[] oneDBtns = {but1, but2, but3, but4, but5, but6, but7, but8, but9, but10, but11, but12, but13, but14, but15};
    public JButton[][] btns = null;

    public Puzzle()
    {
        super("Dream Comp Game");
        setLayout(new BorderLayout());
        upPanel = new Panel();
        upPanel.setLayout(new GridLayout(4, 4, 5, 5));
        but1 = new JButton("1");
        but1.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but1);
        but2 = new JButton("2");
        but2.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but2);
        but3 = new JButton("3");
        but3.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but3);
        but4 = new JButton("4");
        but4.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but4);
        but5 = new JButton("5");
        but5.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but5);
        but6 = new JButton("6");
        but6.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but6);
        but7 = new JButton("7");
        but7.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but7);
        but8 = new JButton("8");
        but8.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but8);
        but9 = new JButton("9");
        but9.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but9);
        but10 = new JButton("10");
        but10.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but10);
        but11 = new JButton("11");
        but11.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but11);
        but12 = new JButton("12");
        but12.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but12);
        but13 = new JButton("13");
        but13.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but13);
        but14 = new JButton("14");
        but14.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but14);
        but15 = new JButton("15");
        but15.addActionListener(new NumberMixActionListener(this));
        upPanel.add(but15);
        butEm = new JButton(" ");
        butEm.addActionListener(new NumberMixActionListener(this));
        upPanel.add(butEm);
        add(upPanel);

        downPanel = new Panel();
        downPanel.setLayout(new FlowLayout(3, 2, 10));
        mix = new JButton("Mix");
        mix.addActionListener(new MixActionListener(this));
        downPanel.add(mix);
        reset = new JButton("Reset");
        reset.addActionListener(new ResetActionListener(this));
        downPanel.add(reset);
        check = new JButton("Check");
        check.addActionListener(new CheckActionListener(this));
        downPanel.add(check);
        end = new JButton("END");
        end.addActionListener(new EndActionListener(this));
        downPanel.add(end);
        add(downPanel);

        belowPanel = new Panel();
        belowPanel.setLayout(new FlowLayout());
        labelCheck = new JLabel("");
        belowPanel.add(labelCheck);
        add(belowPanel);

        pack();
        setSize(500, 500);
        setVisible(true);
    }

    public static void main(String[] args)
    {
        Puzzle g = new Puzzle();
    }
}
