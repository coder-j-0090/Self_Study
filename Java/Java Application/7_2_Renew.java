import javax.swing.*;
import javax.swing.table.*;

import java.awt.*;
import java.awt.event.*;

public class Renew extends JFrame
{
    public DefaultTableModel dtm = null;
    public JLabel bookName = null;
    public JLabel bookAuthor = null;
    public JLabel bookISBN = null;
    public JTextField tfBookName = null;
    public JTextField tfBookAuthor = null;
    public JTextField tfBookISBN = null;
    public JLabel empty1 = null;
    public JButton add = null;
    public JLabel empty2 = null;
    public JTable jt = null;
    public JScrollPane jsp = null;
    public String[]jtHead = null;
    public String[][] jtContents = null;

    public Renew()
    {
        super("JLabel Test");
        setLayout(new GridLayout(2,1,10,10));
        bookName = new JLabel("Name");
        bookAuthor = new JLabel("Author");
        bookISBN = new JLabel("ISBN");
        tfBookName = new JTextField(10);
        tfBookAuthor = new JTextField(10);
        tfBookISBN = new JTextField(10);
        empty1 = new JLabel("");
        add = new JButton("ADD");
        add.addActionListener(new UserActionListener(this));
        empty2 = new JLabel("");
        Panel upUpPanel = new Panel();
        upUpPanel.setLayout(new GridLayout(3,3,10,10));
        upUpPanel.add(bookName);
        upUpPanel.add(bookAuthor);
        upUpPanel.add(bookISBN);
        upUpPanel.add(tfBookName);
        upUpPanel.add(tfBookAuthor);
        upUpPanel.add(tfBookISBN);
        upUpPanel.add(empty1);
        upUpPanel.add(add);
        upUpPanel.add(empty2);
        jtHead = new String[] {"Name","Author","ISBN"};
        jtContents = new String[][] {
                {"Harry Potter","J.K.Rowling","923992399"},
                {"Fast and Furious","Justin Lin","9239483923"},
                {"Matrix","Andrew Tate","9438923834"}
        };
        //이 밑에 3줄의 순서가 중요하
        dtm = new DefaultTableModel(jtContents, jtHead);
        jt = new JTable(dtm);
        jsp = new JScrollPane(jt);
        add(jsp);

        Panel downPanel = new Panel();
        downPanel.add(jsp);
        add(upUpPanel);
        add(downPanel);

        pack();
        setSize(500,500);
        setVisible(true);
    }

    public static void main(String[] args)
    {
        Renew j = new Renew();
    }

}

