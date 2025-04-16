#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define student structure
struct Student {
    int rollNo;
    char name[50];
    float marks;
    struct Student* next;
};

// Head of the linked list
struct Student* head = NULL;

// Function to create a new student node
struct Student* createStudent(int rollNo, char name[], float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

// Add student at end
void addStudent(int rollNo, char name[], float marks) {
    struct Student* newStudent = createStudent(rollNo, name, marks);

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }
    printf("Student added successfully.\n");
}

// View all students
void viewStudents() {
    struct Student* temp = head;
    if (temp == NULL) {
        printf("No records found.\n");
        return;
    }
    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", temp->rollNo, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Search by roll number
void searchStudent(int rollNo) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            printf("Record Found: Roll No: %d, Name: %s, Marks: %.2f\n", temp->rollNo, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Student with Roll No %d not found.\n", rollNo);
}

// Delete by roll number
void deleteStudent(int rollNo) {
    struct Student *temp = head, *prev = NULL;

    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with Roll No %d not found.\n", rollNo);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Student with Roll No %d deleted.\n", rollNo);
}

// Main menu
int main() {
    int choice, rollNo;
    char name[50];
    float marks;

    do {
        printf("\n--- Student Record Management ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll No: ");
                scanf("%d", &rollNo);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Marks: ");
                scanf("%f", &marks);
                addStudent(rollNo, name, marks);
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                printf("Enter Roll No to Search: ");
                scanf("%d", &rollNo);
                searchStudent(rollNo);
                break;

            case 4:
                printf("Enter Roll No to Delete: ");
                scanf("%d", &rollNo);
                deleteStudent(rollNo);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}