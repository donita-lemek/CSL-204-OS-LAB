#include <stdio.h>
#define MAX 15

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    
    printf("First Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d allocated to Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d cannot be assigned\n", i + 1);
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    
    printf("Best Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d allocated to Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d cannot be assigned\n", i + 1);
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
    
    printf("Worst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("Process %d allocated to Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d cannot be assigned\n", i + 1);
    }
}

int main() {
    int blockSize[MAX], processSize[MAX];
    int m, n;
    
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter size of each memory block: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter size of each process: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &processSize[i]);
    
    int tempBlockSize[MAX];
    int c=0;
    while(c==0){
    printf("MENU\n");
    printf("1.firstfit\t2.bestfit\t3.worsefit\t4.exit\n");
    printf("enter choice : ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
    for (int i = 0; i < m; i++) tempBlockSize[i] = blockSize[i];
    firstFit(tempBlockSize, m, processSize, n);
    }
    else if (choice==2){
    for (int i = 0; i < m; i++) tempBlockSize[i] = blockSize[i];
    bestFit(tempBlockSize, m, processSize, n);
    }
    else if(choice==3){
    for (int i = 0; i < m; i++) tempBlockSize[i] = blockSize[i];
    worstFit(tempBlockSize, m, processSize, n);
    }
    else if(choice==4){
    c=1;
    printf("end of program\n");
   }
    else{
    printf("wrong choice\n");
  }
    }
    return 0;
   
}
