#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Δομή Student. Με το typedef δεν χρειάζεται να ξανα γράφουμε struct κάθε φόρα που
// φτιαχνούμε μεταβλητή τύπου Student. Με το next, είναι ένας pointer που δείχνει
// στην διευθύνση ενούς αλλού Student. Με αυτό τον τρόπο, μπορούμε να φτιάξουμε μία
// δυναμική λίστα, όπου μπορούμε να αφαιρούμε και να προσθέτουμε δεδομένα.
typedef struct student {
    int am;
    char name[50];
    float grade;
    struct student *next;
} student;

// Η αρχική μεταβλήτη της λίστας head. Με αυτήν ξεκινάει η λίστα και την έχουμε
// global για εύκολη πρόσβαση σε όλο το πρόγραμμα.
student *head;

// Η συνάρτηση push είναι η συνάρτηση εισαγωγής δεδομένων μίας στοίβας. Η στοίβα είναι LIFO,
// όποτε θα βάλει στο head την νέα εγγραφή. Πρώτα φτιάχνουμε ένα νέο pointer student με σκόπο
// να πάρουμε τις τιμές του data από την main και να τις αποθηκεύσουμε στην λίστα. Στην συνέχεια
// θα δηλώσουμε ότι η επόμενη εγγραφή στην λίστα θα είναι το head και θα μεταφέρουμε το head στην
// νέα μεταβλητή για να εφαρμόσουμε LIFO.
bool push(student data) {
    student *student1;

    student1 = (student *)malloc(sizeof(student));
    if (student1 != NULL) {
        *student1 = data;
        student1->next = head;
        head = student1;
        return true;
    }

    return false;
}

// Η pop είναι η συνάρτηση που αφαίρει τις εγγραφές από την στοίβα. Επειδή είναι LIFO,
// θα αφαιρέσει πρώτα την εγγραφή που είναι πάνω πάνω (δηλαδή την head). Για αυτό φτιάχνουμε
// έναν νέο pointer temp για να μας βοηθήσει σε αυτή την περίπτωση. Αφού μεταφέρουμε το head
// στην επόμενη εγγράφη, κάνουμε free το temp που κρατάει την εγγραφή που είναι στην κορυφή της Στοίβας.
bool pop(student *data) {
    if (head != NULL) {
        student *temp;
        temp = head;

        *data = *head;
        head = head->next;

        free(temp);
        return true;
    }

    return false;
}

// Σε αυτή την συνάρτηση τυπώνουμε τις εγγράφες.
void show() {
    printf("TOP OF THE STACK\n");

    student *temp;
    temp = head;

    while (temp != NULL) {
        printf("STUDENT: %d %s %f\n", temp->am, temp->name, temp->grade);
        temp = temp->next;
    }

    printf("BOTTOM OF THE STACK\n");
}

int main() {
    student data;
    int ch;
    head = NULL;

    for (;;) {
        printf("Menu\n");
        printf("1 - Insert Student\n");
        printf("2 - Pop Student\n");
        printf("3 - Show Info\n");
        printf("4 - Exit\n");

        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter student data: ");
                scanf("%d %s %f", &data.am, data.name, &data.grade);

                if (push(data))
                    printf("Successfully pushed to stack.\n");

                else
                    printf("No memory available...\n");

                break;

            case 2:
                if (pop(&data))
                    printf("Successfully popped %d %s %f.\n", data.am, data.name, data.grade);

                else
                    printf("Empty stack.\n");

                break;

            case 3:
                show();
                break;

            case 4:
                printf("Exiting... Bye\n");
                exit(0);

            default:
                printf("Unrecognised command.. Try again\n");
                fflush(stdin);
        }
    }
}
