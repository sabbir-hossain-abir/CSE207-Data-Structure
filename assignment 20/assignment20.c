#include <stdio.h>
#include <stdlib.h>

/// White = 10
/// Gray = 20
/// Black = 30

int color[9] = {0, 10, 10, 10, 10, 10, 10, 10, 10};
int prev[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int d[9] = {0, 100, 100, 100, 100, 100, 100, 100, 100};
int f[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int time = 0;

int final_dfs_arr[9];

void DFS_visit(int G[9][9], int u)
{
    static counter = 1;
    color[u] = 20;
    time++;
    d[u] = time;

    /// printf("%d  ", u);
    final_dfs_arr[counter] = u;
    counter++;

    for (int v = 1; v < 9; v++)
    {
        if (G[u][v] == 1)
        {
            if (color[v] == 10)
                printf("From %d to %d = Tree\n", u, v);
            else if (color[v] == 20)
                printf("From %d to %d = Back Edge\n", u, v);
            else if (color[v] == 30)
            {
                if (d[u] < d[v])
                    printf("From %d to %d = Forward Edge\n", u, v);
                else if (d[u] > d[v])
                    printf("From %d to %d = Cross Edge\n", u, v);
            }
        }
        if (G[u][v] == 1 && color[v] == 10)
        {

            DFS_visit(G, v);
        }
    }
    color[u] = 30;
    time++;
    f[u] = time;
}

void DFS(int A[9][9], int u)
{
    for (int i = 1; i < 9; i++)
    {
        if (A[u][i] == 1 && color[i] == 10)
        {
            DFS_visit(A, u);
        }
    }

    for (int i = 1; i < 9; i++)
    {
        if (color[i] == 10)
            DFS_visit(A, i);
    }

    printf("\nResult: ");
    for (int i = 1; i < 9; i++)
    {
        printf("%d  ", final_dfs_arr[i]);
    }
    printf("\n");
}

int main()
{
    int A[9][9] =
        {
            {0, 1, 2, 3, 4, 5, 6, 7, 8},
            {1, 0, 1, 1, 0, 1, 0, 0, 0},
            {2, 0, 0, 0, 1, 1, 0, 0, 0},
            {3, 0, 0, 0, 0, 1, 0, 1, 0},
            {4, 1, 0, 0, 0, 0, 0, 0, 0},
            {5, 0, 0, 0, 1, 0, 0, 0, 0},
            {6, 0, 0, 1, 0, 0, 0, 1, 1},
            {7, 0, 0, 0, 0, 1, 0, 0, 0},
            {8, 0, 0, 0, 0, 1, 0, 0, 0},
        };

    int u;

    printf("Enter Starting Value: ");
    scanf("%d", &u);

    printf("\n");
    DFS(A, u);

    return 0;
}