#include <stdio.h>
#include <string.h>
void main()
{
    FILE *f;
    char filename[100], pat[100], temp[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter pattern: ");
    scanf("%s", pat);
    f = fopen(filename, "r");
    while (!feof(f))
    {
        fgets(temp, 100, f);
        if (strstr(temp, pat))
            printf("%s", temp);
    }
    fclose(f);
}