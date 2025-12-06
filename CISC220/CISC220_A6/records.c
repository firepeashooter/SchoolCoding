#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "records.h"

/*
    RULES:
    - Use fgets() to read lines.
    - Treat ONLY ' ' (and '\n', '\r') as whitespace.
    - Do NOT use: sscanf, strtok, atoi, strtol.
    - All parsing must be done manually.
*/

/* ============================================================
   parse_int
   Convert a numeric string into an integer manually.
   Return 1 if valid, 0 otherwise.
   (Some guidance provided)
   ============================================================ */
int parse_int(const char *str, int *value) {
    int i = 0;
    int len = strlen(str);
    int num = 0;
    int has_digit = 0;

    /* Skip leading spaces or '\r' */
    while (i < len && (str[i] == ' ' || str[i] == '\r')) {
        i++;
    }

    /* TODO: extract digits and compute num */
	while (i < len && isdigit(str[i])){
		num = num * 10 + (str[i] - '0');
		i++;
		has_digit = 1;
	}


    /* TODO: require at least one digit */
	if (!has_digit){
		return 0;
	}

    /* TODO: assign *value */
	*value = num;

    return 1; /* replace when implemented */
}

/* ============================================================
   parse_name
   Extract alphabetic name starting at *index.
   Update *index.
   Return 1 if valid name, 0 otherwise.
   (Some guidance, less than above)
   ============================================================ */
int parse_name(const char *line, char *name, int *index) {
    int i = *index;
    int len = strlen(line);
    int j = 0;

    /* Skip LEADING spaces and '\r' */
    while (i < len && (line[i] == ' ' || line[i] == '\r')) {
        i++;
    }

    /* TODO: copy alphabetic characters into name[] */
	while (i < len && isalpha(line[i]) ){
		name[j] = line[i];
		j++;
		i++;
	}


    name[j] = '\0';
    *index = i;

    /* TODO: return 1 if name length > 0 */
	if (strlen(name)){
		return 1;
	}

    return 0;
}

/* ============================================================
   parse_grade
   Extract next token, convert with parse_int,
   validate it is between 0 and 100.
   (Minimal guidance)
   ============================================================ */
int parse_grade(const char *line, int *grade, int *index) {
    int i = *index;
    int len = strlen(line);
    char buf[50];
    int j = 0;

    //* Skip LEADING spaces and '\r' */
    while (i < len && (line[i] == ' ' || line[i] == '\r')) {
        i++;
    }


    /* TODO: extract token into buf[] */

	while(line[i] != ' ' && line[i] != '\r' && line[i] != '\n'){

		buf[j] = line[i];
		j++;
		i++;
	}

    buf[j] = '\0';
    *index = i;

    /* TODO: call parse_int and check range */
	if (parse_int(buf, grade)){
		if(*grade >= 0 && *grade <= 100){
			return 1;

		}

	}

    return 0;
}

/* ============================================================
   process_file
   Students MUST write:
   - opening the input file
   - opening output file
   - reading lines with fgets()
   - calling parse_name + parse_grade
   - counting valid/invalid
   - computing avg
   - writing summary.txt
   - closing both files

   (Almost no code provided — they write everything)
   ============================================================ */
void process_file(const char *input_filename, const char *output_filename) {

    /* TODO:
       - open input file with fopen()
       - check if NULL → print error and return
    */

	FILE* input = fopen(input_filename, "r");
	if (!input){
		perror("fopen() failed opening input file");
		exit(EXIT_FAILURE);
	}

    /* TODO:
       - open output file with fopen()
       - check if NULL → close input file and return
    */
	FILE* output = fopen(output_filename, "w");
	if (!output){
		perror("fopen() failed opening output file");
		exit(EXIT_FAILURE);
	}

    /* Suggested local variables: */
    char line[200];
    int valid = 0;
    int invalid = 0;
    int sum = 0;
	char formattedOutput[200];

    /* TODO:
       - While fgets(...) succeeds:
           int idx = 0;
           char name[50];
           int grade;

           - Call parse_name
           - If OK, call parse_grade
           - Update valid/invalid and sum
    */
	while (fgets(line, 200, input)){
		//We have to reset these each time so it doesn't keep grade the same in memory
		int idx = 0;
		char name[50] = "";
		int grade = 0;

		printf("Line: %s", line);

		if(parse_name(line, name, &idx) && parse_grade(line, &grade, &idx)){

			printf("Name: %s\n", name);
			printf("Grade: %d\n", grade);
			valid++;
			sum += grade;


		}else{
			puts("Invalid Line");
			invalid++;
		};

	}
	
    /* TODO:
       - compute average
       - write correct output format to summary file
    */
	double avg = (double)sum / valid;

	fprintf(output, "Valid: %d\n", valid);
	fprintf(output, "Invalid: %d\n", invalid);
	fprintf(output, "Average: %.2f\n", avg);


    /* TODO:
       - close files
    */
	fclose(input);
	fclose(output);
}

