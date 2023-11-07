import java.awt.*;

public class ComponentTest
{
    public static void main(String[]args)
    {
        Frame f = new Frame();
        f.addWindowListener(new ExitListener());

        f.setLayout(new GridLayout(4,1));

        Label l = new Label("이름");
        f.add(l);

        //We can write 30 letters.
        TextField text = new TextField("이름을 입력하세요",30);
        f.add(text);

        l = new Label("암호");
        f.add(l);

        text = new TextField(30);
        //Textfield to enter password
        text.setEchoChar('*');
        f.add(text);


        TextArea ta = new TextArea("이것은 테스트 입니다");
        f.add(ta);

        f.pack();       //For stability.
        //Multiple CPU works simultaneously, so use pack to make them one, then write the code '.setvisible'
        f.setVisible(true);

    }
}
