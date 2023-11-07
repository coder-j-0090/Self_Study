import java.awt.*;

public class Label_TextField_Panel extends Panel
{
    //필드의 객체변수
    public TextField tf_name = null;
    public TextField tf_age = null;
    public TextField tf_weight = null;
    public Label name_label = null;
    public Label age_label = null;
    public Label weight_label = null;
    public Label empty1 = null;
    public Button btn = null;
    public Label empty2 = null;
    public Label_TextField_Panel()
    {
        Label_and_TextField();
    }
    public Label_TextField_Panel(LayoutManager layout)      //grid
    {
        super(layout);
        Label_and_TextField();
    }
    public void Label_and_TextField()
    {
        name_label = new Label("이름");
        add(name_label);
        age_label = new Label("나이");
        add(age_label);
        weight_label = new Label("몸무게");
        add(weight_label);
        tf_name = new TextField();
        add(tf_name);
        tf_age = new TextField();
        add(tf_age);
        tf_weight = new TextField();
        add(tf_weight);     //옆에다가 kg 를 추가하고 싶으면 이걸 패널로 바꾸고 borderlayout.east 로 바꾸고 적용시켜라
        empty1 = new Label("");
        add(empty1);
        btn = new Button("추가");
        btn.addActionListener(new UserActionListener());        //addActionListener 를 하면 이 버튼에다가 뒤에 추가하는 동작을 실행시켜라/
        add(btn);
        empty2 = new Label("");
        add(empty2);
    }
}
