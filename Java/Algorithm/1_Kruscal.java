import java.util.Arrays;

public class Kruscal
{
    Edge[] graph = new Edge[10];
    Kruscal() {
        graph[0] = new Edge(1, 2, 2);       //I write only once because it can go both ways
        graph[1] = new Edge(1, 3, 6);
        graph[2] = new Edge(1, 7, 3);
        graph[3] = new Edge(2, 2, 3);
        graph[4] = new Edge(3, 4, 6);
        graph[5] = new Edge(3, 5, 4);
        graph[6] = new Edge(3, 6, 5);
        graph[7] = new Edge(3, 9, 7);
        graph[8] = new Edge(4, 4, 5);
        graph[9] = new Edge(5, 8, 7);
    }
    int[] parents = {0, 1, 2, 3, 4, 5, 6, 7};
    int v = 7;
    public static void main(String[] args) {
        Kruscal K = new Kruscal();
        K.sort();
        int sum = 0;
        int cnt = 0;
        for(Edge e : K.graph)
        {
            if(!K.find(e))
            {
                K.union(e);

                System.out.println("Used Edge for MST: (" + e.start + ", " + e.weight + ", " + e.end + ")");
                System.out.println("Parents Array: " + Arrays.toString(K.parents));
                sum+=e.weight;
                if(++cnt==K.v-1)
                    break;
            }
        }
        System.out.println("Sum of weight: " + sum);
        System.out.println("Number of Used Edge of MST: " + cnt);
    }
    void sort()
    {
        Edge temp = new Edge();
        for (int i = 0; i < graph.length - 1; i++)
        {
            for (int j = i + 1; j < graph.length; j++)
            {
                if (graph[i].weight > graph[j].weight)
                {
                    temp = graph[i];
                    graph[i] = graph[j];
                    graph[j] = temp;
                }
            }
        }
    }
    boolean find(Edge e)
    {
        if(parents[e.start]==parents[e.end])
            return true;
        else
            return false;
    }
    void union(Edge e)
    {
        if(parents[e.start]>parents[e.end])
            parents[e.start]=parents[e.end];
        else
            parents[e.end]=parents[e.start];
        union2(e);
    }
    void union2(Edge e)
    {
        for(int i=1;i<parents.length;i++)
        {
            for(int j=1;j<parents.length;j++)
            {
                if(parents[i]==j)
                    parents[i]=parents[j];
            }
        }
    }

}
