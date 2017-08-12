#include<stdio.h>
#define INT_MAX 10000
#define V 9

int minExtract(int dist[V], int sptSet[V])
{
int min = INT_MAX, min_index; 
for(int i = 0; i<V; i++)
{
if(!sptSet[i]&& dist[i]<min)
{
min = dist[i];
min_index = i;
}
}
return min_index;
}
dijkstra(int graph[V][V], int src)
{
int dist[V];
for(int i = 0 ; i<V; i++)
{
   dist[i] = INT_MAX;
}
int sptSet[V] = {0};

dist[src] = 0;
int index;
int u,i;
for( i= 0; i<V; i++)
{
u = minExtract(dist, sptSet);
sptSet[u] = 1;

for(int j=0 ; j<V; j++)
{
if(!sptSet[j] && dist[j]>dist[u]+graph[u][j] && graph[u][j])
{
dist[j] = dist[u]+ graph[u][j];
}
}
}
for(i=0;i<V;i++)
    printf("vertix :%d    %d\n",i ,dist[i]);
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

    dijkstra(graph, 0);

    return 0;
}

