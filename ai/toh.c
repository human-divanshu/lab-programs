#include <stdio.h>

void toh(int disk, char start, char help, char target)
{
    if (disk > 0) {
        toh(disk - 1, start, target, help);
        printf("Move disk from %c to %c\n",start, target);
        toh(disk - 1, help, start, target);
    }
}

int main(void)
{
    int disks;

    printf("Enter the number of disks : ");
    scanf("%d", &disks);
    toh(disks, 'A', 'B', 'C');
    return 0;
}
