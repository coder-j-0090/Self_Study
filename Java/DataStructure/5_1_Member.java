class Member<T1, T2>
{
    T1 name;
    T2 height;

    Member()
    {
        name = null;
        height = null;
    }
    Member(T1 n, T2 h)
    {
        name = n;
        height = h;
    }
    public void getInfo()
    {
        System.out.print(name+ " ");
        System.out.println(height+" cm");
    }
}

