int neighbors[50][49];
int dist[50];
void dfs(int x, int d , int* N_Cities)
    {
        dist[x] = d;
        for (int y=0;y<N_Cities[x]; y++)
        {
            if (dist[neighbors[x][y]] == -1)
            {
                dfs(neighbors[x][y], d + 1 , N_Cities);
            }
        }
    }
int numberOfWays(int roads_rows, int roads_columns, int** roads) {
    
    int* N_Cities = (int*) calloc(roads_rows + 1, sizeof(int));
    int road_count = roads_rows;
    int city_count=road_count+1;
    
    int ans=0;
    
    for(int i=0;i<road_count;i++)
    {
        neighbors[roads[i][0]-1][N_Cities[roads[i][0]-1]]=roads[i][1]-1;
        N_Cities[roads[i][0]-1]++;
        neighbors[roads[i][1]-1][N_Cities[roads[i][1]-1]]=roads[i][0]-1;
        N_Cities[roads[i][1]-1]++;
    }

    
    
    for (int i=0;i<city_count-2;i++)
    {
        for (int j=i+1;j<city_count-1;j++)
        {
            for (int k=j+1;k<city_count;k++)
            {
                for (int z=0;z<city_count;z++) 
                {
                    dist[z]=-1;
                }
                dfs(i, 0, N_Cities);
                if (dist[j] != dist[k])
                {
                    continue;
                }
                for (int z=0;z<city_count;z++) 
                {
                    dist[z]=-1;
                }
                dfs(j, 0, N_Cities);
                if (dist[i] == dist[k])
                {
                    ans += 1;
                }
            }
        }
    }
    return ans;
}