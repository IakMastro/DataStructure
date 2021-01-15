#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int am;
    char name[50];
    float grade;
    struct student *left;
    struct student *right;
} student;

// Η αρχική μεταβλήτη της λίστας head. Με αυτήν ξεκινάει η λίστα και την έχουμε
// global για εύκολη πρόσβαση σε όλο το πρόγραμμα.

student *createStudent() {
    student *student1;

    student1 = (student *)malloc(sizeof(student));
    if (student1 != NULL) {
        printf("Enter student data: ");
        scanf("%d %s %f", &student1->am, student1->name, &student1->grade);
        student1->left = NULL;
        student1->right = NULL;
    }

    return student1;
}

void addInOrder(student *root, student *new_student) {
    if (new_student->am < root->am)
        if (root->left == NULL)
            root->left = new_student;

        else
            addInOrder(root->left, new_student);

    else
        if (root->right == NULL)
            root->right = new_student;

        else
            addInOrder(root->right, new_student);
}

void showInOrder(student *root) {
    if (root != NULL) {
        showInOrder(root->left);
        printf("%d %s %f\n", root->am, root->name, root->grade);
        showInOrder(root->right);
    }
}

float maxGrade(student *root) {
    float result = -1, resultRight;

    if (root != NULL) {
        result = maxGrade(root->left);

        if (result < root->grade)
            result = root->grade;

        resultRight = maxGrade(root->right);

        if (result < resultRight)
            result = resultRight;
    }

    return result;
}

int main() {
    char ch;
    student *temp, *root = NULL;
    float mGrade = -1;

    for (;;) {
        printf("Menu\n");
        printf("1 - Insert Student\n");
        printf("2 - Show Students\n");
        printf("3 - Show Max Grade\n");
        printf("4 - Exit\n");

        scanf("%d", &ch);
        switch (ch) {
            case 1:
                temp = createStudent();

                if (temp != NULL)
                    if (root == NULL)
                        root = temp;

                    else
                        addInOrder(root, temp);

                else
                    printf("No memory left\n");

                break;

            case 2:
                printf("Tree contents\n");
                showInOrder(root);
                break;

            case 3:
                mGrade = maxGrade(root);

                if (mGrade == -1)
                    printf("Empty tree\n");

                else
                    printf("Max Grade %.1f\n", mGrade);

                break;

            case 4:
                printf("Bye!\n");
                return 0;

            default:
                printf("Try again!\n");
        }
    }
}
