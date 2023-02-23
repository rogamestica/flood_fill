#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

int grid[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

void flood_fill(int x, int y, int new_color, int old_color, int size) {
    if (x < 0 || y < 0 || x >= size || y >= size) {
        return;
    }
    if (visited[x][y] == 1 || grid[x][y] != old_color) {
        return;
    }
    grid[x][y] = new_color;
    visited[x][y] = 1;
    flood_fill(x+1, y, new_color, old_color, size);
    flood_fill(x-1, y, new_color, old_color, size);
    flood_fill(x, y+1, new_color, old_color, size);
    flood_fill(x, y-1, new_color, old_color, size);
}

int main() {
    int size, x, y, old_color, new_color;
    
    printf("Enter size of grid: ");
    scanf("%d", &size);
    
    printf("Enter the grid values:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &grid[i][j]);
            visited[i][j] = 0;
        }
    }
    
    printf("Enter the starting point (x, y): ");
    scanf("%d %d", &x, &y);
    
    printf("Enter the new color: ");
    scanf("%d", &new_color);
    
    old_color = grid[x][y];
    flood_fill(x, y, new_color, old_color, size);
    
    printf("Updated grid:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
