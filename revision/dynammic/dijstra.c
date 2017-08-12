#include<stdio.h>
#define V 9
#define INT_MAX 123456

int minIndex(int dist[V],int spt[V])
{
int min = INT_MAX, index;
for (int i = 0 ; i<V;i++)
{
   if(min>dist[i] && !spt[i])
   {
     min = dist[i];
     index =i;
   }
}
return index;
}

void dijkstra(int graph[V][V],int src)
{
int dist[V];
for(int i=0;i<V;i++)
{
dist[i] = INT_MAX;
}
dist[src] = 0;
int spt[V] = {0};
for(int i=0; i<V;i++)
{
    int u = minIndex(dist,spt);
    spt[u] = 1;
    for(int j= 0; j<V;j++)
    {
       if(!spt[j]&& dist[j]>(dist[u]+graph[u][j]) && graph[u][j])
       {
          dist[j] = dist[u]+graph[u][j];
       }
    }
}
for(int i = 0;i<V;i++)
{
    printf("%d,",dist[i]);
}
printf("\n");
}

int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
for(int i=0;i<V;i++)
    dijkstra(graph, i);

    return 0;
}


