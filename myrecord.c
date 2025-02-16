/**
 * -------------------------------------
 * @file  myrecord.c
 * file description
 * -------------------------------------
 * @author Myra Ribeiro, 169030590, ribe0590@mylaurier.ca
 *
 * @version 2025-02-07
 *
 * -------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#include "mysort.h"

GRADE grade(float score) {
	GRADE r = { "F" };
	// your code
	if (score >= 90)
		strcpy(r.letter_grade, "A+");
	else if (score >= 85)
		strcpy(r.letter_grade, "A");
	else if (score >= 80)
		strcpy(r.letter_grade, "A-");
	else if (score >= 77)
		strcpy(r.letter_grade, "B+");
	else if (score >= 73)
		strcpy(r.letter_grade, "B");
	else if (score >= 70)
		strcpy(r.letter_grade, "B-");
	else if (score >= 67)
		strcpy(r.letter_grade, "C+");
	else if (score >= 63)
		strcpy(r.letter_grade, "C");
	else if (score >= 60)
		strcpy(r.letter_grade, "C-");
	else if (score >= 57)
		strcpy(r.letter_grade, "D+");
	else if (score >= 53)
		strcpy(r.letter_grade, "D");
	else if (score >= 50)
		strcpy(r.letter_grade, "D-");
	else
		strcpy(r.letter_grade, "F");
	return r;
}

int import_data(FILE *fp, RECORD *dataset) {
// your code
	int count = 0;
	while (fscanf(fp, "%s %f", dataset[count].name, &dataset[count].score) == 2) {
		count++;
	}
	return count;
}

STATS process_data(RECORD *dataset, int count) {
// your code
	STATS stats = { 0, 0.0, 0.0, 0.0 };
	if (count == 0)
		return stats;

	float sum = 0.0, sum_sq = 0.0;
	for (int i = 0; i < count; i++) {
		sum += dataset[i].score;
		sum_sq += dataset[i].score * dataset[i].score;
	}

	stats.count = count;
	stats.mean = sum / count;
	stats.stddev = sqrt((sum_sq / count) - (stats.mean * stats.mean));

	quick_sort((void**) dataset, 0, count - 1);

	if (count % 2 == 0) {
		stats.median = (dataset[count / 2 - 1].score + dataset[count / 2].score)
				/ 2.0;
	} else {
		stats.median = dataset[count / 2].score;
	}

	return stats;
}
int report_data(FILE *fp, RECORD *dataset, STATS stats) {
// your code
	if (stats.count < 1)
		return 0;

	fprintf(fp, "Number of records: %d\n", stats.count);
	fprintf(fp, "Mean score: %.2f\n", stats.mean);
	fprintf(fp, "Standard Deviation: %.2f\n", stats.stddev);
	fprintf(fp, "Median score: %.2f\n", stats.median);
	fprintf(fp, "\nSorted Records:\n");

	for (int i = stats.count - 1; i >= 0; i--) {
		GRADE g = grade(dataset[i].score);
		fprintf(fp, "%s %.2f %s\n", dataset[i].name, dataset[i].score,
				g.letter_grade);
	}

	return 1;
}

