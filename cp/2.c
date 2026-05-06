#include <stdio.h>
int source, v, E, visi[20];
int adj[20][20];
void DFS(int i)
{
    int j;
    visi[i] = 1;
    printf("%d->", i + 1);
    for (j = 0; j < v; j++)
    {
        if (adj[i][j] == 1 && visi[j] == 0)
            DFS(j);
    }
}
int main()
{

    int i, j, v1, v2;
    printf("Enter the no of Edge: ");
    scanf("%d", &E);
    printf("Enter the vertex : ");
    scanf("%d", &v);

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            adj[i][j] = 0;
        }
    }
    for (i = 0; i < E; i++)
    {
        printf("Enter the V1 - v2: ");
        scanf("%d %d", &v1, &v2);
        adj[v1 - 1][v2 - 1] = 1;
    }

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("Enter the start : ");
    scanf("%d", &source);

    DFS(source - 1);
    return 0;
}

int count(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}
int countSetBits(int N)
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        cnt += count(i);
    }
    return cnt; // Brian Kernighan's Algorithm:
}