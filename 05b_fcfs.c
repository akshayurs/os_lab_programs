#include <stdio.h>
struct process
{
    int ID, AT, BT, CT, TAT, WT;
};
void main()
{
    struct process P[10], temp;
    int n, i, j, ct;
    float total_tat, total_wt;
    printf("Enter the number of Process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        P[i].ID = i + 1;
        printf("Enter AT for %d process", i + 1);
        scanf("%d", &P[i].AT);
        printf("Enter AT for %d process", i + 1);
        scanf("%d", &P[i].BT);
        P[i].CT = 0;
        P[i].WT = 0;
        P[i].TAT = 0;
    }
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (P[j].AT > P[j + 1].AT)
            {
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
    P[0].CT = P[0].AT + P[0].BT;
    ct = P[0].BT;
    for (i = 1; i < n; i++)
    {
        if (P[i].AT > P[i - 1].CT)
            ct = P[i].AT + P[i].BT;
        else
            ct += P[i].BT;
        P[i].CT = ct;
    }
    for (i = 0; i < n; i++)
    {
        P[i].TAT = P[i].CT - P[i].AT;
        P[i].WT = P[i].TAT - P[i].BT;
        total_tat += P[i].TAT;
        total_wt += P[i].WT;
    }
    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i].ID, P[i].AT, P[i].BT, P[i].CT, P[i].WT, P[i].TAT);
    }
    printf("AVG TAT : %f\n", total_tat / n);
    printf("AVG WT : %f\n", total_wt / n);
}