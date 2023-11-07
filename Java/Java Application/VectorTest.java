import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.util.Vector;
public class VectorTest extends JFrame
{
    public JLabel Name = null;
    public JLabel Author = null;
    public JLabel ISBN = null;
    public JTextField tfName = null;
    public JTextField tfAuthor = null;
    public JTextField tfISBN = null;
    public JLabel empty1 = null;
    public JButton add = null;
    public JLabel empty2 = null;
    public JLabel empty3 = null;
    public JTable jt = null;
    public JScrollPane jsp = null;
    public DefaultTableModel dtm = null;
    public Vector<String>vecHead = new Vector();
    public Vector jtContents = null; //제네릭을 안한 이유는 벡터라 스트링이 몇개 들어갈지 몰라서 타입정의 불가능. 그래서 제너릭 안썻다.
    public JLabel empty4 = null;
    Panel upPanel = null;
    Panel downPanel = null;
    public MenuBar mbar = null;
    public Menu menu = null;
    public MenuItem addmenu = null;
    public void setMenu()
    {
        mbar = new MenuBar();
        menu = new Menu("Edit");
        addmenu = new MenuItem("ADD DATA");
        setMenuBar(mbar);
        mbar.add(menu);
        menu.add(addmenu);
        addmenu.addActionListener(new UserActionListener(this));
    }
    public VectorTest()
    {
        super("Vector Test");
        setLayout(new GridLayout(2,1,10,10));
        Panel upPanel = new Panel();
        upPanel.setLayout(new GridLayout(3,3,10,10));
        Name = new JLabel("Name");
        upPanel.add(Name);
        Author = new JLabel("Author");
        upPanel.add(Author);
        ISBN = new JLabel("ISBN");
        upPanel.add(ISBN);
        tfName = new JTextField(10);
        upPanel.add(tfName);
        tfAuthor = new JTextField(10);
        upPanel.add(tfAuthor);
        tfISBN = new JTextField(10);
        upPanel.add(tfISBN);
        empty1 = new JLabel("");
        upPanel.add(empty1);
        add = new JButton("ADD");
        add.addActionListener(new UserActionListener(this));
        upPanel.add(add);
        empty2 = new JLabel("");
        upPanel.add(empty2);
        Panel downPanel = new Panel();
        downPanel.setLayout(new GridLayout(1,1,10,10));
// empty3 = new JLabel("");
// downPanel.add(empty3);
        vecHead = new Vector();
        vecHead.add("Hello");
        vecHead.add("Jim");
        vecHead.add("Bow");
        jtContents = new Vector(); //이건 2차
        Vector<String>row = new Vector();
        row.add("whywhy");
        row.add("worldworld");
        row.add("nononon");
        jtContents.add(row);
        dtm = new DefaultTableModel(jtContents, vecHead);
        jt = new JTable(dtm);
        jsp = new JScrollPane(jt);
        downPanel.add(jsp);
// empty4 = new JLabel("");
// downPanel.add(empty4);
        add(upPanel);
        add(downPanel);
        jt.updateUI();
        setMenu();
        pack(); //pack 은 다른거 다 하고 하는거라 updateUI 쓰고 pack 하기.
        setSize(500,500);
        setVisible(true);
    }
}

