public class Linked_List
{
    Node head = null;       //Head of the list.
    Linked_List(){}
    void add(String n, int a)
    {
        Node temp = new Node(n,a);      //Make name and age in the form of node. 'new' will make a new object. Save it in temporary node named 'temp'
        add(temp);              //Add the node 'temp' in the method that adds to the linked list. Name is add as well. It's called overloading
    }
    void add(Node n)        //Make add function using node
    {
        if(head!=null)
        {
            n.next=head.next;
            head.next=n;
           /*
               추가된 노드의 next 에다가 head 의 next 를 저장시키고, 그다음에 head의 next 에다 추가된 노드를 저장시킨다.
            */
        }
        else
        {
            head=n;
        }
    }
    void print()
    {
        Node temp;      //Declare temporary node 'temp'.
        temp = head;    //Put head in the value of 'temp'
        while(temp.next!=null)
        {
            System.out.print(temp.name+" ");
            System.out.println(temp.age);
            temp=temp.next;        //The next of last temp is null, so the last one won't be printed.
        }
        System.out.println(temp.name+" "+temp.age);         //Make one more.
    }
}
