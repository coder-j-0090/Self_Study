public class Graph {
    int[][] vertex = new int[8][8];  //정해주지 않으면 배열내의 기본값은 0이다.

    Graph() //컨스트럭터에서 정해준값은 1이 된다. 왜냐면 1로 정했기 때문에...
    {
        vertex[1][2] = 1;
        vertex[1][4] = 1;
        vertex[1][7] = 1;
        vertex[2][2] = 1;
        vertex[2][3] = 1;
        vertex[2][5] = 1;
        vertex[3][2] = 1;
        vertex[3][4] = 1;
        vertex[3][6] = 1;
        vertex[4][1] = 1;
        vertex[4][3] = 1;
        vertex[4][7] = 1;
        vertex[5][2] = 1;
        vertex[5][6] = 1;
        vertex[6][3] = 1;
        vertex[6][5] = 1;
        vertex[6][7] = 1;
        vertex[7][1] = 1;
        vertex[7][4] = 1;
        vertex[7][6] = 1;
    }

    void printy()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (vertex[i][j] == 1)
                {
                    System.out.printf("(%d, %d)", i, j);
                }
            }
            System.out.println();
        }
        System.out.println();
    }

    void printScanVertex(int v)
    {
        for(int i=0;i<8;i++)
        {
            if(vertex[v][i]==1)
                System.out.printf("%d ",i);
        }
        System.out.println();
    }

}
