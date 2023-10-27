public class Generic
{
    public static void main(String[]args)
    {
        Member<String, Integer> person = new Member<String, Integer>("Kim",175);
        person.getInfo();

        Member<String, Double> person2 = new Member<String, Double>("Kang",181.3);
        person2.getInfo();
    }
}
