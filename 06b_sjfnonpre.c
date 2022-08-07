#include <stdio.h>
struct process
{
    int ID, AT, BT, CT, TAT, WT;
};
void main()
{
    struct process P[10];
    int n, i, j;
    float total_tat = 0, total_wt = 0;
    printf("Enter the number of Process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        P[i].ID = i + 1;
        printf("Enter AT for %d process :", i + 1);
        scanf("%d", &P[i].AT);
        printf("Enter BT for %d process :", i + 1);
        scanf("%d", &P[i].BT);
    }
    printf("\nGantt Chart:\n");
    int MIN_IND, MIN_BT, COMP, CUR_TIME = 0;
    while (COMP != n)
    {
        MIN_IND = -1;
        MIN_BT = 999;
        for (i = 0; i < n; i++)
        {
            if (P[i].AT <= CUR_TIME && P[i].BT > 0)
            {
                if (P[i].BT < MIN_BT)
                {
                    MIN_BT = P[i].BT;
                    MIN_IND = i;
                }
                if (P[i].BT == MIN_BT)
                {
                    if (P[i].AT < P[MIN_IND].AT)
                    {
                        MIN_BT = P[i].BT;
                        MIN_IND = i;
                    }
                }
            }
        }
        if (MIN_IND == -1)
            CUR_TIME++;
        else
        {
            CUR_TIME += P[MIN_IND].BT;
            P[MIN_IND].CT = CUR_TIME;
            P[MIN_IND].TAT = P[MIN_IND].CT - P[MIN_IND].AT;
            P[MIN_IND].WT = P[MIN_IND].TAT - P[MIN_IND].BT;
            total_tat += P[MIN_IND].TAT;
            total_wt += P[MIN_IND].WT;
            COMP++;
            printf("| P%d(%d) %d", P[MIN_IND].ID, P[MIN_IND].BT, CUR_TIME);
        }
    }

    printf("\n\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i].ID, P[i].AT, P[i].BT, P[i].CT, P[i].WT, P[i].TAT);
    }
    printf("AVG TAT : %.3f\n", total_tat / n);
    printf("AVG WT : %.3f\n", total_wt / n);
}