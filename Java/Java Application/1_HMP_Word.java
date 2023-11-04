public class HMP_Word implements PrintableObj
{
    private String filename;

    public HMP_Word(String s) {
    }

    public String HMP_Word(String fileName)
    {
        return filename=fileName;
    }
    @Override
    public String getObjName() {
        return filename;
    }

    @Override
    public void print()
    {
        System.out.println("파일명 : "+filename);
        System.out.println("MS Word 문서 출력!");
    }
}
