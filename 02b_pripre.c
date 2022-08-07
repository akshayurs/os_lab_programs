#include <stdio.h>
struct process
{
    int ID, PRI, AT, ST, BT, BT_TMP, CT, TAT, WT, IsCOMP;
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
        printf("Enter AT for process %d :", i + 1);
        scanf("%d", &P[i].AT);
        printf("Enter BT for process %d :", i + 1);
        scanf("%d", &P[i].BT);
        P[i].BT_TMP = P[i].BT;
        printf("Enter Priority for process %d :", i + 1);
        scanf("%d", &P[i].PRI);
        P[i].IsCOMP = 0;
    }
    int MIN_IND, MIN_PRI, COMP = 0, CUR_TIME = 0;
    printf("\nGantt Chart:\n");
    while (COMP != n)
    {
        MIN_IND = -1;
        MIN_PRI = 999;
        for (i = 0; i < n; i++)
        {
            if (P[i].AT <= CUR_TIME && P[i].IsCOMP == 0)
            {
                if (P[i].PRI < MIN_PRI)
                {
                    MIN_PRI = P[i].PRI;
                    MIN_IND = i;
                }
                if (P[i].PRI == MIN_PRI)
                {
                    if (P[i].AT < P[MIN_IND].AT)
                    {
                        MIN_PRI = P[i].PRI;
                        MIN_IND = i;
                    }
                }
            }
        }
        if (MIN_IND == -1)
            CUR_TIME++;
        else
        {
            P[MIN_IND].BT--;
            CUR_TIME++;
            printf("| P%d(1) %d", P[MIN_IND].ID, CUR_TIME);
            if (P[MIN_IND].BT == 0)
            {
                P[MIN_IND].CT = CUR_TIME;
                P[MIN_IND].TAT = P[MIN_IND].CT - P[MIN_IND].AT;
                P[MIN_IND].WT = P[MIN_IND].TAT - P[MIN_IND].BT_TMP;
                total_tat += P[MIN_IND].TAT;
                total_wt += P[MIN_IND].WT;
                COMP++;
                P[MIN_IND].IsCOMP = 1;
            }
        }
    }

    printf("\n\nID\tAT\tBT\tPRI\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", P[i].ID, P[i].AT, P[i].BT_TMP, P[i].PRI, P[i].CT, P[i].WT, P[i].TAT);
    }
    printf("AVG TAT : %f\n", total_tat / n);
    printf("AVG WT : %f\n", total_wt / n);
}