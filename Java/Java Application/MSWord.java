public class MSWord implements PrintableObj
{
    private String filename = null;
    public MSWord(String fileName)
    {
        filename = fileName;
    }
    @Override
    public String getObjName()
    {
        return filename;
    }
    @Override
    public void print()
    {
        System.out.println("File Name : "+filename);
        System.out.println("MS_Word 문서 출력!");
    }
}
