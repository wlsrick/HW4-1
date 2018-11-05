#include <stdio.h>
#include <stdlib.h>
#define STUDENT 3
#define EXAMS 4

int mininum(const int grades[][EXAMS], int pupils, int tests);
int maxinum(const int grades[][EXAMS], int pupils, int tests);
double average(const int set0fGrades[], int tests);
void printArray(const int grades[][EXAMS], int pupils, int tests);

int main() {
	int student;
	const int studentGrades[STUDENT][EXAMS] = {
		{77,68,86,73},{96,87,89,78},{70,90,86,81}
	};
	printf("The array is:\n");
	printArray(studentGrades, STUDENT, EXAMS);
	printf("\n\nLowest grade: %d\nHighest grade: %d\n",
	mininum(studentGrades, STUDENT, EXAMS),
	maxinum(studentGrades, STUDENT, EXAMS));
	for (student = 0;student < STUDENT;student++) {
		printf("The average grade for student %d is %2.f\n", student, average(studentGrades[student], EXAMS));
	}
	system("pause");
	return 0;
}
int mininum(const int grades[][EXAMS], int pupils, int tests) {
	int i, j, lowGrade = 100;
	for (i = 0;i < pupils;i++) {
		for (j = 0;j < tests;j++) {
			if (grades[i][j] < lowGrade) {
				lowGrade = grades[i][j];
			}
		}
	}
	return lowGrade;
}
int maxinum(const int grades[][EXAMS], int pupils, int tests) {
	int i, j, highGrade = 0;
	for (i = 0;i < pupils;i++) {
		for (j = 0;j < tests;j++) {
			if (grades[i][j] > highGrade) {
				highGrade = grades[i][j];
			}
		}
	}
	return highGrade;
}
double average(const int set0fGrades[], int tests) {
	int i, total = 0;
	for (i = 0;i < tests;i++) {
		total += set0fGrades[i];
	}
	return (double)total / tests;
}
void printArray(const int grades[][EXAMS], int pupils, int tests) {
	int i, j;
	printf("              [0]  [1]   [2]  [3]");
	for (i = 0;i < pupils;i++) {
		printf("\nstudentGrade[%d]", i);
		for (j = 0;j < tests;j++) {
			printf("%-5d", grades[i][j]);
		}
	}
}