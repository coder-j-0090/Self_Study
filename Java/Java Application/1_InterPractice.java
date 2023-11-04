public class InterPractice
{
    public static void main(String[]args)
    {
        MSWord msdoc = new MSWord("test.doc");
        HMP_Word hmp = new HMP_Word("test.hmp");
        Photo pic = new Photo("James Miller","Monalisa");
        System.out.println("MS Doc");
        Printer.print(msdoc);
        System.out.println("HMP Word");
        Printer.print(hmp);
        System.out.println("Printer");
        Printer.print(pic);
    }
}
