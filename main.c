#include <stdio.h>
#include <string.h>


struct Student {
    int id;
    char name[50];
    int age;
};


struct Student students[100];
int studentCount = 0;


void loadStudents() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) return;

    while(fscanf(file, "%d %s %d", 
                 &students[studentCount].id,
                 students[studentCount].name,
                 &students[studentCount].age) == 3) {
        studentCount++;
    }

    fclose(file);
}


void saveStudents() {
    FILE *file = fopen("students.txt", "w");
    for(int i = 0; i < studentCount; i++) {
        fprintf(file, "%d %s %d\n", 
                students[i].id,
                students[i].name,
                students[i].age);
    }
    fclose(file);
}


void addStudent() {
    printf("Enter ID: ");
    scanf("%d", &students[studentCount].id);

    printf("Enter name: ");
    scanf("%s", students[studentCount].name);

    printf("Enter age: ");
    scanf("%d", &students[studentCount].age);

    studentCount++;
    saveStudents();
    printf("Student added!\n");
}

void showStudents() {
    if(studentCount == 0) {
        printf("No students found.\n");
        return;
    }

    for(int i = 0; i < studentCount; i++) {
        printf("\nID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
    }
}


void menu() {
    int choice;
    while(1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add student\n");
        printf("2. Show all students\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if(choice == 1) addStudent();
        else if(choice == 2) showStudents();
        else if(choice == 3) {
            printf("Exiting program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
}


int main() {
    printf("Welcome to the Student Management System!\n");
    loadStudents();
    menu();
    return 0;
}
