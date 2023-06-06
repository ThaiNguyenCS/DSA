#include <iostream>
#include <fstream>

using namespace std;

#define INF 1000

void BellmanFord(string fileName)
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
        ifs >> numOfVertices;   // Get number of vertices
        w = new int[numOfVertices*numOfVertices]; // 2D array in 1D array contains weighted edge
        for(int i = 0; i < numOfVertices; i++)
        {
            for(int j = 0; j < numOfVertices; j++)
            {
                ifs >> w[i*numOfVertices + j];
            }
        }
        ifs.close();
    }

    int *arr = new int[numOfVertices]; // array contains shortest-path
    for(int i = 0; i < numOfVertices; i++)
    {
        if(i == 0)
            arr[i] = 0;
        else    
            arr[i] = INF;
    }

    for(int loop = 0; loop < numOfVertices -1; loop++) // Loop at most n - 1 times
    {
        bool ifChange = false;
        for(int i = 0; i < numOfVertices; i++)
        {
            if(arr[i] == INF)
                continue;
            else
            {
                for(int j = 0; j < numOfVertices; j++)
                {
                    if(arr[i] + w[i*numOfVertices+j] < arr[j])
                    {
                        arr[j] = arr[i] + w[i*numOfVertices+j];
                        ifChange = true; // Check if there're any changes
                    }
                    if(arr[0] < 0)
                    {
                        cout << "Exists a negative circuit!";
                        exit(1);
                    }
                }
            }
        }
        if(!ifChange)
            break;
    }
    for(int i = 0; i < numOfVertices; i++)
    {
        cout << "A -> " << char(i + 65) << ": " << arr[i] << endl;
    }
    // Deallocate heap memory
    delete[]arr;
    arr = nullptr;
    delete[]w;
    w = nullptr;
}
int main()
{
    BellmanFord("weightInput.txt");
    return 0;
}