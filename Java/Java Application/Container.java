import java.awt.*;

public class Container
{
    public static void main(String[]args)
    {
        Frame f = new Frame("This is title bar");
        f.addWindowListener(new ExitListener());


        FileDialog fd = new FileDialog(f,"File Dialog");
        //File Dialog fd = new FileDialog(f, "File Dialog", FileDialog.SAVE);

        //FileDialog Show
        fd.show();

        System.out.println("Selected File : "+fd.getFile());
        System.out.println("Directory : "+fd.getDirectory());

        f.setSize(200,200);
        f.setVisible(true);
    }
}
