#include <stdio.h>
#include <stdlib.h>

/*
 * Gets and returns a valid fraction as its result
 * A valid fraction is of this form: integer/positive integer
 * Pre: none
 */
void
scan_fraction(int *nump, int *denomp)
{
	char slash;			/* charactor between numerator and denominator 分子和分母*/
	int status;			/* status code returned by scanf indicating number of valid values obtained */
	int error;			/* flag indicating presence of an error */
	char discard;		/* unproccessed charactor from input line */

	do {
		/* no error detected yet */
		error = 0;

		/* Get a fraction from the user */
		printf("Enter a common fraction as two integer seperated ");
		printf("by a slash> ");
		status = scanf("%d%c%d", nump, &slash, denomp);

		/* Validate the fraction   */
		if (status < 3) {
			error = 1;
			printf("Invalid-please read direction carefully\n");
		} else if (slash !='/') {
			error = 1;
			printf("Invalid-seperated numerator and denominator by a slash(/)\n");
		} else if (*denomp <= 0) {
			error = 1;
			printf("Invalid-denominator must be positive\n");
		}

		/* Discard extra input charactors  */
		do {
			scanf("%c", &discard);
		} while (discard != '\n');

	} while (error);
}

int main()
{
	int num, denom;
	scan_fraction(&num, &denom);
	printf("the numerator is %d and the denominator is %d.\n", num, denom);
	return 0;
}



/*
 * 如果直接用指针, 会报警告: 指针在使用前没有初始化, 导致运行失败
int main()
{
	int *nump, *denomp;
	scan_fraction(nump, denomp);
	printf("the numerator is %d and the denominator is %d.\n", *nump, *denomp);
}
*/
