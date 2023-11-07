import java.awt.event.*;
public class AllComponentListener implements ComponentListener, FocusListener, InputMethodListener, KeyListener, MouseListener, MouseMotionListener
{
    private String source = null;
    public AllComponentListener(String source)
    {
        this.source=source;
    }
    //ComponentListener

    @Override
    public void componentResized(ComponentEvent e)
    {
        //Invoked when the component's size changes.
        System.out.println(source+ " : componentResized()");
    }

    @Override
    public void componentMoved(ComponentEvent e)
    {
        //Invoked when the component's position changes.
        System.out.println(source+ " : componentMoved()");
    }

    @Override
    public void componentShown(ComponentEvent e)
    {
        //Invoked when the component has been made visible.
        System.out.println(source+ " : componentShown()");
    }

    @Override
    public void componentHidden(ComponentEvent e)
    {
        //Invoked when the component has been made invisible
        System.out.println(source+ " : componentHidden()");
    }





    //FocusListener

    @Override
    public void focusGained(FocusEvent e)
    {
        //Invoked when a component gains the keyboard focus
        System.out.println(source+ " : focusedGained()");
    }

    @Override
    public void focusLost(FocusEvent e)
    {
        //Invoked when a component loses the keyboard focus.
        System.out.println(source+ " : focusLost()");
    }


    //InputMethodListener
    @Override
    public void inputMethodTextChanged(InputMethodEvent event)
    {
        //Invoked when the text entered through an input method has changed.
        System.out.println(source+ " : inputMethodTextChanged()");
    }

    @Override
    public void caretPositionChanged(InputMethodEvent event)
    {
        //Invoked when the caret within composed text has changed.
        System.out.println(source+ " : caretPositionChanged()");
    }





    //KeyListener

    @Override
    public void keyTyped(KeyEvent e)
    {
        //Invoked when a key has been typed.
        System.out.println(source + " : keyTyped()");
    }

    @Override
    public void keyPressed(KeyEvent e)
    {
        //Invoked when a key has pressed
        System.out.println(source+ " : keyPressed()");
    }

    @Override
    public void keyReleased(KeyEvent e)
    {
        //Invoked when a key has been released
        System.out.println(source+ " : keyReleased()");
    }





    //MouseListener

    @Override
    public void mouseClicked(MouseEvent e)
    {
        //Invoked when the mouse has been clicked on a component.
        System.out.println(source+ " : mouseClicked()");
    }

    @Override
    public void mousePressed(MouseEvent e)
    {
        //Invoked when a mouse button has been pressed on a component.
        System.out.println(source+ " : mousePressed()");
    }

    @Override
    public void mouseReleased(MouseEvent e)
    {
        //Invoked when a mouse button has been pressed on a component
        System.out.println(source+ " : mouseReleased()");
    }

    @Override
    public void mouseEntered(MouseEvent e)
    {
        //Invoked when the mouse enters a component.
        System.out.println(source+ " : mouseEntered()");
    }

    @Override
    public void mouseExited(MouseEvent e)
    {
        //Invoked when the mouse exits a component.
        System.out.println(source+ " : mouseExited()");
    }





    //MouseMotionListener

    @Override
    public void mouseDragged(MouseEvent e)
    {
        //Invoked when a mouse button is pressed on a component and then dragged.
        System.out.println(source+ " : mouseDragged()");
    }

    @Override
    public void mouseMoved(MouseEvent e)
    {
        //Invoked when the mouse button has been moved on a component(with no buttons no down)
        System.out.println(source+ " : mouseMoved()");
    }
}

