/*
    ผู้ใช้กรอกชื่อและความสูงของคนในโรงเรียนในห้อง A และห้อง B และเรียงลำดับของคนที่ตัวเล็กที่สุดไปยังตัวใหญ่ที่สุดในแต่ละห้อง และเรียงลำดับของคนทั้งโรงเรียนจากตัวที่ใหญ่ที่สุดมายังตัวเล็กที่สุด

    Test case:
        Room A
        Name : 
            John
        Height (cm) : 
            176.6
        Name : 
            Job
        Height (cm) : 
            177.5
        Name : 
            Aim
        Height (cm) : 
            149.8
        Name : 
            Mon
        Height (cm) : 
            158.9
        Name : 
            Ammy
        Height (cm) : 
            151.0
        Name : 
            A
        Height (cm) : 
            169.7
        Name : 
            -1

        Room B
        Name : 
            Komsam
        Height (cm) : 
            176.1
        Name : 
            Samart
        Height (cm) : 
            165.4
        Name : 
            Sunu
        Height (cm) : 
            168.1
        Name : 
            -1

    Output:
        Room A -> Aim Ammy Mon A John Job
        Room B -> Samart Sunu Komsam
        School -> Job John Komsam A Sunu Samart Mon Ammy Aim
*/

#include <stdio.h>
#include <string.h>

// Structure to represent a person
struct Person {
    char name[50];
    float height;
};

// Function to input people in a room
void inputRoom(struct Person room[]) {
    int i = 0;
    while (1) {
        printf("Name (Enter -1 to finish): ");
        scanf("%s", room[i].name);
        if (strcmp(room[i].name, "-1") == 0)
            break;
        printf("Height (cm): ");
        scanf("%f", &room[i].height);
        i++;
    }
}

// Function to sort people in a room by height
void sortRoom(struct Person room[], int n) {
    int i, j;
    struct Person temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (room[j].height > room[j + 1].height) {
                temp = room[j];
                room[j] = room[j + 1];
                room[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Person roomA[100], roomB[100];
    int nA, nB;

    printf("Room A\n");
    inputRoom(roomA);
    nA = 0;
    while (strcmp(roomA[nA].name, "-1") != 0) {
        nA++;
    }

    printf("\nRoom B\n");
    inputRoom(roomB);
    nB = 0;
    while (strcmp(roomB[nB].name, "-1") != 0) {
        nB++;
    }

    sortRoom(roomA, nA);
    sortRoom(roomB, nB);

    printf("\nRoom A -> ");
    for (int i = 0; i < nA; i++) {
        printf("%s ", roomA[i].name);
    }

    printf("\nRoom B -> ");
    for (int i = 0; i < nB; i++) {
        printf("%s ", roomB[i].name);
    }

    printf("\nSchool -> ");
    for (int i = nA - 1; i >= 0; i--) {
        printf("%s ", roomA[i].name);
    }
    for (int i = nB - 1; i >= 0; i--) {
        printf("%s ", roomB[i].name);
    }

    return 0;
}
