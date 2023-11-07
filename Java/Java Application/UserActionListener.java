import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
class UserActionListener implements ActionListener
{
    public Coupang cp = null;
    /*
     * Book 과 Coupang 의 차이는 Coupang 같은게 여러개 있을때 딱 하나의 Frame 에 맞춰야될거다. 그래서 정확하게 해야되서 Coupang cp 를 만든거고
     * Book 은 그냥 타입 설정을 위해서 쓴거라 구지 새로 이렇게 만들 필요 없다.
     */
    public UserActionListener(Coupang coupang)
    {
        cp = coupang;
    }
    /*
     * 버튼에 추가하는 actionListener 의 객체를 생성할 때, jFrame 에 객체 this 를 전달하여 주기 때문에
     *
     * ActionListener 의 생성자에 전달된 객체는 버튼을 클릭했을때 실행되는 ActionPerformed 메소드에서 알 수 있게 하기 위해 class 의 field 로
     * 선언해놓은 field 에 전달하여 actionPerformed 메소드를 JFrame 의 컴포넌트에 실행할 수 있게 한다.
     */
    @Override
    public void actionPerformed(ActionEvent e)
    {
        System.out.println(cp.tfName.getText());    //getText() 를 써줘야 안의 내용을 가져온다.
        System.out.println(cp.tfAuthor.getText());
        System.out.println(cp.tfIsbn.getText());
        //new book() 을 만들어서 객체를 생성해야 arraylist 가 돌아간다. arraylist 는 book 이라는 객체를 추가 할 수 있는것 이기 때문에.
        cp.contents.add(new Book(cp.tfName.getText(),cp.tfAuthor.getText(),cp.tfIsbn.getText()));
        for(Book book : cp.contents)
            System.out.println(book.bookName +"/"+ book.bookAuthor + "/" + book.bookIsbn);
    }
}

