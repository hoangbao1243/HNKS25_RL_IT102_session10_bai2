#include <stdio.h>

#define MAX_VE 50

struct VeSuKien {
    int maVe;
    char tenSuKien[50], loaiVe[20];
    float giaGoc;
    int isEarlyBird, daCheckIn;
};

int tim(struct VeSuKien a[], int n, int ma) {
    for (int i = 0; i < n; i++)
        if (a[i].maVe == ma) return i;
    return -1;
}

int main() {
    struct VeSuKien a[MAX_VE] = {
        {1001, "VIBE 2025", "VIP", 2000000, 1, 0},
        {1002, "VIBE 2025", "GA", 800000, 0, 0},
        {1003, "VIBE 2025", "Zone A", 1200000, 1, 0}
    };

    int n = 3, i, p;

    a[n++] = (struct VeSuKien){1004, "VIBE 2025", "VIP", 2000000, 1, 0};

    p = tim(a, n, 1001);
    if (p >= 0) {
        a[p].daCheckIn = 1;
        printf("Check-in thanh cong!\n");
    }

    p = tim(a, n, 1001);
    if (p >= 0 && a[p].daCheckIn)
        printf("Ve da check-in!\n");

    p = tim(a, n, 1002);
    if (p >= 0) {
        for (i = p; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    }

    p = tim(a, n, 9999);
    if (p < 0)
        printf("Khong tim thay ve!\n");

    printf("\nDANH SACH VE:\n");
    for (i = 0; i < n; i++)
        printf("%d | %s | %.0f VND | %s\n",
               a[i].maVe, a[i].loaiVe,
               a[i].isEarlyBird ? a[i].giaGoc * .85 : a[i].giaGoc,
               a[i].daCheckIn ? "Da check-in" : "Chua check-in");

    return 0;
}