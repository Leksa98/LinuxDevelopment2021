#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "./po"

int main(int argc, char *argv[]) {
	setlocale (LC_ALL, "");
	bindtextdomain ("guess", LOCALE_PATH);
	textdomain ("guess");

	printf(_("Guess a number between from 1 to 100\n"));

	int low = 1;
	int high = 100;
	char answer[128];

	while(1) {
		int middle = (low + high) / 2;
		if (low == high) {
			printf(_("The number is %d!\n"), middle);
			break;
		}
		printf(_("Is the number bigger than %d? (yes/no)\n"), middle);
		scanf("%s", answer);
		if (strcmp(answer, _("yes")) == 0) {
			low = middle + 1;
		} else if (strcmp(answer,_("no")) == 0) {
			high = middle;
		} else {
			printf(_("Please try again. If your guess number is bigger than %d, print 'yes', otherwise print 'no'\n"), middle);
		}
	}
	return 0;
}
