#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 100

typedef struct
{
    int count;
    int front;
    int rear;
    int item[MAXQUEUE];
} QUEUE;

QUEUE antrean;

void inisialisasi(QUEUE *Q)
{
    Q->count = 0;
    Q->front = 0;
    Q->rear = 0;
}

int isEmpty(QUEUE *Q)
{
    int hasil = 0;
    if (Q->count == 0)
    {
        hasil = 1;
    }
    return hasil;
}

int isFull(QUEUE *Q)
{
    int hasil = 0;
    if (Q->count == MAXQUEUE)
    {
        hasil = 1;
    }
    return hasil;
}

void insert(QUEUE *Q, int data)
{
    if (!isFull(Q))
    {
        Q->item[Q->rear] = data;
        Q->rear = (Q->rear + 1) % MAXQUEUE;
        Q->count++;
        printf("\nmasukan %d\n", data);
    }
    else
    {
        printf("Antrian penuh!\n");
    }
}

void hapus(QUEUE *Q)
{
    if (!isEmpty(Q))
    {
        int data = Q->item[Q->front];
        Q->front = (Q->front + 1) % MAXQUEUE;
        Q->count--;
        printf("Menghapus %d dari antrean\n", data);
    }
    else
    {
        printf("Antrian kosong!\n");
    }
}

void printQueue(QUEUE *Q)
{
    if (!isEmpty(Q))
    {
        printf("\nIsi antrean: ");
        for (int i = Q->front; i < Q->front + Q->count; i++)
        {
            printf("%d ", Q->item[i % MAXQUEUE]);
        }
        printf("\n");
    }
    else
    {
        printf("\nAntrian kosong!\n");
    }
}

int main()
{
    inisialisasi(&antrean);

    int inputAngka;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Masukkan angka\n");
        printf("2. Hapus dari antrean\n");
        printf("3. Tampilkan antrean\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda (1-4): ");

        int pilihan;
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan angka: ");
            scanf("%d", &inputAngka);
            insert(&antrean, inputAngka);
            break;
        case 2:
            hapus(&antrean);
            break;
        case 3:
            printQueue(&antrean);
            break;
        case 4:
            printf("\nKeluar dari program.\n");
            return 0;
        default:
            printf("\nPilihan tidak valid.\n");
        }
    }

    return 0;
}
