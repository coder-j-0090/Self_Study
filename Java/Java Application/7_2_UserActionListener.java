import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class UserActionListener implements ActionListener
{
    public Renew cpjt = null;
    public UserActionListener(Renew cpjtbl)
    {
        cpjt = cpjtbl;
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        System.out.println(cpjt.tfBookName.getText()+"\n"+cpjt.tfBookAuthor.getText()+"\n"+cpjt.tfBookISBN.getText()+"\n");
        String[]test = new String[] {cpjt.tfBookName.getText(), cpjt.tfBookAuthor.getText(), cpjt.tfBookISBN.getText()};
        //cpjt.dtm.insertRow(3,test);
        cpjt.dtm.addRow(test);
    }

}

