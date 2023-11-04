public class Photo extends Picture implements PrintableObj
{
    public Photo(String name, String photoname)
    {
        super(name,photoname);
    }
    public String getObjName()
    {
        return picName;
    }
    public void print()
    {
        System.out.println("Artist Name : "+artistName);
        System.out.println("Picture Name : "+picName);
        System.out.println("사진출력!");
    }

}
