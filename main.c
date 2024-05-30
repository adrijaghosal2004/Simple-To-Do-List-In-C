#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100
#define len 50

struct Task {
    char task[max];
    int completed;
};

void addTask(struct Task list[len],int count)
{
    char task[max];
    printf("Task Description: ");
    scanf("%s", list[count].task);
    list[count].completed = 0;
}

void displayTasks(struct Task list[len], int num)
{
    printf("\nTask List:\n");
    for (int i = 0; i < num; i++)
    {
        if(list[i].completed==0)
        printf("%d. %s   Incomplete\n", i + 1, list[i]);
        else
        printf("%d. %s   Completed\n", i + 1, list[i]);
    }
}
void markComplete(struct Task list[len], int count)
{
    int index;
    displayTasks(list, count);

    printf("Enter the index of the task to mark as complete: ");
    scanf("%d", &index);

    if (index >= 1 && index <= count)
    {
        printf("\nTask \"%s\" marked as complete.\n", list[index - 1]);
        list[index-1].completed=1;
    }
    else
    {
        printf("Invalid task index.\n");
    }
}

void editTasks(struct Task list[len], int count)
{
    int index;
    displayTasks(list, count);

    printf("\nEnter the index of the task to edit: ");
    scanf("%d", &index);

    if (index >= 1 && index <= count)
    {
        printf("Enter the new description for the task: ");
        scanf("%s", list[index - 1].task);
        printf("Task updated successfully.\n");
    }
    else
    {
        printf("Invalid task index.\n");
    }
}

int main() {
    struct Task l[len];
    int c,count =0;
    while(c!=5)
    {
        printf("\nSimple To Do List\n");
        printf("1. Add Task\n");
        printf("2. Edit Task\n");
        printf("3. Mark Task as Complete\n");
        printf("4. Display Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice between 1 to 5 : ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                addTask(l,count);
                count++;
                break;
            case 2 :
                editTasks(l,count);
                break;
            case 3:
                markComplete(l,count);
                break;
            case 4:
                displayTasks(l,count);
                break;
            case 5:
                printf("Exiting program..\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
