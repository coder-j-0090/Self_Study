public class Dijkstra
{
    public static void main(String[]args)
    {
        Graph g= new Graph();       //그래프 객체 생성
        g.dijkstra(1);
        g.answerPrint();
    }
}
