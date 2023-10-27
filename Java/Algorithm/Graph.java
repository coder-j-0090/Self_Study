public class Graph
{
    int[][]graph = {
            //Vertical is starting vertex number, Horizontal is arrival vertex number of vertical.
            //  1, 2, 3, 4, 5, 6, 7
            {0, 0, 0, 0, 0, 0, 0, 0}, //0
            {0, 0, 1, 100, 100, 5, 100, 100}, //1   //두번째 숫자는 0.
            {0, 1, 0, 2, 1, 100, 100, 100}, //2     //세번째 숫자는 0
            {0, 100, 2, 0, 100, 100, 1, 100}, //3   //네번째 숫자는 0.
            {0, 100, 1, 100, 0, 2, 4, 2},  //4      //다섯번째 숫자는 0.
            {0, 5, 100, 100, 2, 0, 100, 100}, //5   //여섯번쨰 숫자는 0.
            {0, 100, 100, 1, 4, 100, 0, 3}, //6     //일곱번째 숫자는 0.
            {0, 100, 100, 100, 2, 100, 3, 0}};//7   //여덟번째 숫자는 0.
    //The numbers at the top represents the graph.
    int[]visit = new int[8];        //To check if I visited(calculated) that vertex or not
    int[]ans = {100, 100, 100, 100, 100, 100, 100, 100};
    //Start with 100 at answer array.

    int getMinVertex()      //Return the minimum vertex among not-visited vertexes. Update the weight from smallest.
    {
        int min=1000;       //Minimum value is 1000
        int minVertex=0;        //Starting Point
        for(int i=1;i<graph.length;i++)    //Use for to find the minimum value out of 8 nodes.
        {
            if(min>ans[i]&&visit[i]==0)
            {
                min = ans[i];   //min becomes the value of ans[i].
                minVertex=i;    //minVertex will become an i.
                /*
                 * If min is bigger when you compare min and ans[i], min will decrease to ans[i].
                 * Find the minimum among ans[i](i=1-8)
                 * minVertex=i finds the index value with the smallest weight.
                 */
            }
        }
        return minVertex;       //Return the smallest value of minimum Vertex.
    }
    void setVisit(int vertex)       //If the vertex is visited, add it to visit[vertex]
    {
        visit[vertex]=1;
    }
    boolean end()       //Check if it's done or not. If every value of visit array is 1, then the sum of the visit array must be 7. Otherwise, keep working.
    {
        int sum = 0;
        for(int i=1;i<graph.length;i++)
            sum+=visit[i];
        if(sum==graph.length-1)
            return true;
        else
            return false;
    }
    //key
    void dijkstra(int startVertex)
    {
        setVisit(startVertex);          //After calculating StartVertex, change the visit[startVertex] to 1.
        System.out.println("minVertex: "+startVertex);
        for(int i=1;i<graph.length;i++)
        {
            if(graph[startVertex][i]<ans[i])
                //ans[i] is 100, and when the start vertex and end vertex are not connected in 2D array, 100 was inserted instead of weight
                //So, ans[i] is always 100, and if it's smaller than 100, vertical vertex and horizontal vertex is connected.
                //In that case,
                ans[i]=graph[startVertex][i];
                //Insert the value of graph[startVertex][i] in ans array.
        }
        answerPrint();
        while(!end())       //While every vertex isn't visited, it's keep working
            //Among non-visited, find the minimum vertex, mark as visited, then update it.
        {
            int vertex = getMinVertex();    //To find the second small number(the smallest is startVertex).
            //Since startVertex is a beginning value, getMinVertex method doesn't have to be used, but after that, the program should keep looking for the minimum value, so getMinVertex must be used inside while statement.
            setVisit(vertex);
            System.out.println("minVertex: "+vertex);
            for(int i=1;i<graph.length;i++)
            {
                if (ans[vertex] + graph[vertex][i] < ans[i])
                    ans[i] = ans[vertex] + graph[vertex][i];
            }
            answerPrint();
        }
    }
    void answerPrint()    
    {
        for(int i=1;i<graph.length;i++)
        {
            System.out.printf("%3d ", ans[i]);
        }
        System.out.println();
    }

}
