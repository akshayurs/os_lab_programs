#include <stdio.h>
struct process
{
    int ID, AT, BT, BT_TMP, CT, TAT, WT, flag;
};
void main()
{
    struct process P[10], temp;
    int n, i, j, quantum;
    float total_tat = 0, total_wt = 0;
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
        P[i].flag = 0;
    }
    printf("Enter quantum : ");
    scanf("%d", &quantum);
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (P[j].AT > P[j + 1].AT)
            {
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
    printf("\nGantt Chart:\n");
    int COMP = 0, CUR_IND, CUR_TIME = P[0].AT, WAIT[100], f = 0, r = 0;
    WAIT[r] = 0;
    P[0].flag = 1;
    while (COMP != n)
    {
        CUR_IND = WAIT[f];
        f = (f + 1) % n;
        if (P[CUR_IND].BT > quantum)
        {
            P[CUR_IND].BT -= quantum;
            CUR_TIME += quantum;
            printf("|P%d(%d) %d", P[CUR_IND].ID, quantum, CUR_TIME);
        }
        else
        {
            CUR_TIME += P[CUR_IND].BT;
            printf("|P%d(%d) %d", P[CUR_IND].ID, P[CUR_IND].BT, CUR_TIME);
            P[CUR_IND].CT = CUR_TIME;
            P[CUR_IND].BT = 0;
            COMP++;
        }
        for (int i = 0; i < n && P[i].AT <= CUR_TIME; i++)
        {
            if (i == CUR_IND || P[i].flag == 1 || P[i].BT == 0)
                continue;
            r = (r + 1) % n;
            P[i].flag = 1;
            WAIT[r] = i;
        }
        if (P[CUR_IND].BT > 0)
        {
            r = (r + 1) % n;
            WAIT[r] = CUR_IND;
        }
        if (f > r && COMP != n)
        {
            f = 0;
            r = -1;
            int PREV = CUR_TIME;
            printf("| Idle");
            do
            {
                CUR_TIME++;
                for (int i = 1; i < n; i++)
                {
                    if (P[i].BT > 0 && P[i].AT <= CUR_TIME)
                    {
                        r = (r + 1) % n;
                        WAIT[r] = i;
                        P[i].flag = 1;
                        break;
                    }
                }
            } while (r == -1);
            printf("(%d) %d", CUR_TIME - PREV, CUR_TIME);
        }
    }
    for (i = 0; i < n; i++)
    {
        P[i].TAT = P[i].CT - P[i].AT;
        P[i].WT = P[i].TAT - P[i].BT_TMP;
        total_tat += P[i].TAT;
        total_wt += P[i].WT;
    }
    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i].ID, P[i].AT, P[i].BT_TMP, P[i].CT, P[i].WT, P[i].TAT);
    printf("AVG TAT : %.3f\n", total_tat / n);
    printf("AVG WT : %.3f\n", total_wt / n);
}