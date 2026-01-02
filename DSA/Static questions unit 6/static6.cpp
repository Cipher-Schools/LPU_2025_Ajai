#include <iostream>
#include <cstdlib>

void floydWarshall(int **graph, int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main(void)
{
    int n, i, j;
    std::cin >> n;
    int **graph = (int **)std::malloc((long unsigned)n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)std::malloc((long unsigned)n * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 100;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            std::cin >> graph[i][j];
        }
    }

    floydWarshall(graph, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}