import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Vector;

class UserActionListener implements ActionListener
{
    public VectorTest vt = null;
    public UserActionListener(VectorTest vtest)
    {
        vt = vtest;
    }
    @Override
    public void actionPerformed(ActionEvent e)
    {
        Vector<String> row = new Vector<String>();
        row.add(vt.tfName.getText());
        row.add(vt.tfAuthor.getText());
        row.add(vt.tfISBN.getText());
        vt.dtm.addRow(row);
        System.out.println(vt.tfName.getText()+" "+vt.tfAuthor.getText()+" "+vt.tfISBN.getText());
    }
}

