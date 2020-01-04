#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH_PATH 100

int m,n;
int row[] =    {-1, 0, 1, 0};
int column[] = { 0, 1, 0,-1};
int lab_exit(int i,int j);
void display_path(int path_x[],int path_y[],int path_index);
void backtrack(int * labyrinth,int * path_x,int * path_y);
void labyrinth_paths(int ** labyrinth,int i,int j,int * no_traces,int path_index, int path_x[MAX_LENGTH_PATH],int path_y[MAX_LENGTH_PATH]);
int main() {
    FILE * lab;
    lab = fopen("../labyrinth.txt","r");
    //read the encoded labyrinth from file
    int **labyrinth;
    fscanf(lab,"%d%d",&m,&n);
    labyrinth = (int**)malloc(m * sizeof(int*));
    for (int i=1;i<=m;i++){
        labyrinth[i] = (int*)malloc(n * sizeof(int));
        for (int j=1;j<=n;j++){
            fscanf(lab,"%d",&labyrinth[i][j]);
        }
    }
    fclose(lab);
    //reading the initial position
    int i,j;
    printf("Choose initial position:\n"
           "Value of i:\n");
    scanf("%d",&i);
    getchar();
    printf("Value of j:\n");
    scanf("%d",&j);
    getchar();
    //displaying all the possible paths
    int path_x[MAX_LENGTH_PATH],path_y[MAX_LENGTH_PATH],path_index = 0,no_traces=0;
    labyrinth_paths(labyrinth,i,j,&no_traces,path_index,path_x,path_y);
    //printing no of traces
    printf("The number of traces is: %d",no_traces);
    for(int k=1;k<=m;k++){
        free(labyrinth[k]);
    }
    free(labyrinth);
    return 0;
}
int lab_exit(int i,int j){
    //verifies if we reached the exit
    if(i==1 || i==m || j==1 || j==n) return 1;
    return 0;
}
void display_path(int path_x[],int path_y[],int path_index){
    for(int k=0;k<path_index;k++){
        printf("(%d %d) -> ",path_x[k],path_y[k]);
    }
    printf("(%d %d)\n",path_x[path_index],path_y[path_index]);
}
void backtrack(int * labyrinth,int * path_x,int * path_y){
    (*labyrinth) = 1;
    (*path_x) = 0;
    (*path_y) = 0;
}
void labyrinth_paths(int ** labyrinth,int i,int j,int * no_traces,int path_index, int path_x[],int path_y[]){
    labyrinth[i][j] = 0;
    path_x[path_index] = i;
    path_y[path_index] = j;
    //if we reached the exit it will display path
    if(lab_exit(i,j)){
        display_path(path_x,path_y,path_index);
        //counting traces
        (*no_traces)++;
        //backtrack
        backtrack(&labyrinth[i][j],&path_x[path_index],&path_y[path_index]);
        return;
    }
    for(int k=0;k<4;k++){
        int new_i = i + row[k];
        int new_j = j + column[k];
        if(labyrinth[new_i][new_j] == 1){
            labyrinth_paths(labyrinth,new_i,new_j,no_traces,path_index+1,path_x,path_y);
        }
    }
    //backtrack
    backtrack(&labyrinth[i][j],&path_x[path_index],&path_y[path_index]);
}