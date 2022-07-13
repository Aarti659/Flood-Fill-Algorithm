#include<iostream> 
using namespace std; 

#define M 8
#define N 8
  

void flood_Fill(int my_Screen[][N], int x, int y, int currColor, int newColor) 
{ 
    
    if (x < 0 || x >= M || y < 0 || y >= N) 
        return; 
    if (my_Screen[x][y] != currColor) 
        return; 
    if (my_Screen[x][y] == newColor) 
        return; 
  
     
    my_Screen[x][y] = newColor; 
  
    
    flood_Fill(my_Screen, x+1, y, currColor, newColor); 
    flood_Fill(my_Screen, x-1, y, currColor, newColor); 
    flood_Fill(my_Screen, x, y+1, currColor, newColor); 
    flood_Fill(my_Screen, x, y-1, currColor, newColor); 
} 
  

void findColor(int my_Screen[][N], int x, int y, int newColor) 
{ 
    int currColor = my_Screen[x][y]; 
    flood_Fill(my_Screen, x, y, currColor, newColor); 
} 
  

int main() 
{ 
    int my_Screen[M][N] = 
                    {
                      {3, 2, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
    int x = 4, y = 4, newColor = 3; 
    findColor(my_Screen, x, y, newColor); 
  
    cout << "Updated myScreen : \n"; 
    
 
    for (int j=0; j<M;j++) 
    { 
        for (int k=0;k<N; k++) 
           cout << my_Screen[j][k] << " "; 
        cout << endl; 
    } 
    return 0;
} 
