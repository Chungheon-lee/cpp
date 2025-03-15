#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id; // student id
    char  *name; // name
    float gpa; 
} stu;

stu * getstudent(){
    stu * temp;

    char namebuf[200];
    int tid;
    float tgpa;

    if ( scanf("%d %s %f",&tid,namebuf,&tgpa) == 3 ){
        temp = (stu *)malloc(sizeof(stu));
        temp->name = (char *)malloc(1 + strlen(namebuf));
        strcpy(temp->name, namebuf);
        temp->id = tid;
        temp->gpa = tgpa;

        return temp;
    } else {
        return 0;
    }
}

void sort_student(stu **student, int nStu){
    for ( int i=0; i<nStu; i++ ){
        for ( int j=0; j<nStu-i-1; j++ ){
            if ( student[j]->gpa < student[j+1]->gpa ){
                stu *space = student[j];
                student[j] = student[j+1];
                student[j+1] = space;
            }
        }
    }
}

void print_student(stu **student, int nStu){
    for ( int i=0; i<nStu; i++ ){
        printf("%d  %s  %.2f\n",student[i]->id,student[i]->name,student[i]->gpa);
    }
}

void removeAll(stu **student, int nStu){
    for ( int i=0; i<nStu; i++ ){
        free(student[i]->name);
        free(student[i]);
    }
    free(student);
}

int main(){
    stu **student;
    int numStu;

    printf("student number: ");
    scanf("%d",&numStu);
    student = (stu **)malloc(sizeof(stu*)*numStu); 

    // insert
    for (int i=0; i<numStu; i++){
        student[i] = getstudent();
    }

    // sort
    sort_student(student, numStu);

    // print
    print_student(student, numStu);

    // memory remove
    removeAll(student, numStu);
    
    return 0;
}

