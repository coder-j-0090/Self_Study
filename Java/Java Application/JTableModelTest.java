import javax.swing.*;
import java.awt.*;

public class JTableModelTest
{
    public static void main(String[]args)
    {
        //SimpleTest st = new SimpleTest();
        TableModel tm = new TableModel();
        String[] newer = new String[] {"Trump","10","20"};
        tm.dtm.addRow(newer);
        String[] newKorean = new String[] {"heo","43","85"};
        tm.dtm.addRow(newKorean);
    }
}
