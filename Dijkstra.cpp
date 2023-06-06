#include <iostream>
#include <fstream>

/*Tam thoi*/

using namespace std;

#define INF 1000

int getLeast(int *arr, bool *visited, int n)
{
    int MIN = 1000;
    int index = -1;
    for(int i = 0; i < n; i++)
    {
        if(visited[i])
            continue;
        else
        {
            if(arr[i] < MIN)
            {
                index = i;
                MIN = arr[i];
            }
        }
    }
    return index;
}

void DijkstraAl(string fileName)
{
    ifstream ifs(fileName, ios_base::in);
    int numOfVertices;
    int *w = nullptr;
    if(!ifs.is_open())
    {
        cout << "Fail to open file!";
        exit(1);
    }
    else
    {
        ifs >> numOfVertices;
        w = new int[numOfVertices*numOfVertices];
        for(int i = 0; i < numOfVertices; i++)
        {
            for(int j = 0; j < numOfVertices; j++)
            {
                ifs >> w[i*numOfVertices + j];
                if(w[i*numOfVertices + j] < 0)
                {
                    cout << "Sorry, weighted of edge must be positive!";
                    exit(1);
                }
            }
        }
        ifs.close();
    }
    int *arr = new int[numOfVertices];
    for(int i = 0; i < numOfVertices; i++)
    {
        if(i == 0)
            arr[i] = 0;
        else    
            arr[i] = INF;
    }
    bool visited[20] = {false};
    int parent[20] = {};
    for(int i = 0; i < numOfVertices; i++)
    {
        int v = getLeast(arr, visited, numOfVertices);
        if(v == -1)
        {
            break;
        }
        else
        {
            visited[v] = true;
            for(int k = 0; k < numOfVertices; k++)
            {
                if(w[v*numOfVertices+k] + arr[v] < arr[k])
                {
                    arr[k] = w[v*numOfVertices+k] + arr[v];
                    parent[k] = v;
                }
            }
        }
    }

    for(int i = 0; i < numOfVertices; i++)
    {
        cout << "A -> " << char(i + 65) << ": " << arr[i] 
             << " from " << char(parent[i]+65) << endl;
    }
    delete[]arr;
    arr = nullptr;
    delete[]w;
    w = nullptr;
}
int main()
{
    DijkstraAl("weightInput.txt");
    return 0;
}