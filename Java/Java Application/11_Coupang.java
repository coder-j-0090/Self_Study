import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.util.ArrayList;

//arraylist 에다가 저장하는 것(Book)
public class Coupang extends JFrame
//다른 컴포넌트를 포함하는 클래스를 컨테이너 컴포넌트라 한다.
        //Extends 해놓으면 JFrame 이 된다. is a
{
    public JLabel bookName = new JLabel("Book Name");
    public JLabel bookAuthor = new JLabel("Book Author");
    public JLabel bookIsbn = new JLabel("ISBN");
    public JTextField tfName = new JTextField(10);
    public JTextField tfAuthor = new JTextField(10);
    public JTextField tfIsbn = new JTextField(10);
    public JLabel empty1 = new JLabel("");
    public JButton addButton = new JButton("Add");
    public JLabel empty2 = new JLabel("");
    public JLabel empty3 = new JLabel("");
    public String[]header = {"Book Name", "Book Author", "ISBN"};
    public String[][] printableContents = new String[8][8];
    //순서가 중요하다.
    public JTable table = new JTable(printableContents, header);
    public JLabel empty4 = new JLabel("");
    public ArrayList<Book>contents = new ArrayList<>();
    /*
     * ArrayList 를 사용해야 한다. Book 클래스의 객체의 갯수는 추가하거나 삭제 할 수 있어야 하므로 배열보다는 arraylist 가 적합하다.
     * Book 클래스의 객체는 string 세개를 필드로 가지므로 클래스로 선언해서 arraylist 에 삽입하여야 한다.
     */

    public Coupang()        //생성자는 프로그램이 시작할떄 실행된다.
    {
        setLayout(new GridLayout(4,3,10,10));

        add(bookName);

        add(bookAuthor);

        add(bookIsbn);

        add(tfName);
        add(tfAuthor);
        add(tfIsbn);

        add(empty1);

        addButton.addActionListener(new UserActionListener(this));
        add(addButton);

        add(empty2);

        add(empty3);

        add(table);

        add(empty4);

        pack();
        setSize(500,700);
        setVisible(true);
    }

    public static void main(String[]args)
    {
        Coupang cp = new Coupang();
    }
}

