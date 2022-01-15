#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#include <stdbool.h>

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "./po"

/// Array with roman numbers from 1 to 100
char *roman_numbers[] = {
	"I","II","III","IV","V","VI","VII","VIII","IX","X",
	"XI","XII","XIII","XIV","XV","XVI","XVII","XVIII","XIX","XX",
	"XXI","XXII","XXIII","XXIV","XXV","XXVI","XXVII","XXVIII","XXIX","XXX",
	"XXXI","XXXII","XXXIII","XXXIV","XXXV","XXXVI","XXXVII","XXXVIII","XXXIX","XL",
	"XLI","XLII","XLIII","XLIV","XLV","XLVI","XLVII","XLVIII","XLIX","L",
	"LI","LII","LIII","LIV","LV","LVI","LVII","LVIII","LIX","LX",
	"LXI","LXII","LXIII","LXIV","LXV","LXVI","LXVII","LXVIII","LXIX","LXX",
	"LXXI","LXXII","LXXIII","LXXIV","LXXV","LXXVI","LXXVII","LXXVIII","LXXIX","LXXX",
	"LXXXI","LXXXII","LXXXIII","LXXXIV","LXXXV","LXXXVI","LXXXVII","LXXXVIII","LXXXIX","XC",
	"XCI","XCII","XCIII","XCIV","XCV","XCVI","XCVII","XCVIII","XCIX","C"
};

/**
* Convert integer number from 1 to 100 to roman one
* @param[in] number integer numer
* @param[out] roman numer or NULL if integer number < 0 or > 100
*/
char* convert_int_to_roman(int number) {
	if (number > 0 && number < 101) {
		return roman_numbers[number - 1];
	}
	return NULL;
}

/**
* Convert roman number from I to L to integer one
* @param[in] roman_number roman number
* @param[out] integer number or 0 if roman number < 0 or > 100
*/
int convert_roman_to_int(char* roman_number) {
	for (int i = 1; i <= 100; i++) {
		if (strcmp(roman_number, roman_numbers[i]) == 0) {
			return i;
		}
	}
	return 0;
}

/**
* Print --help
*/
void print_help() {
	printf(_("The program guesses the number from 1 to 100\n"));
	printf(_("Usage: ./guess [-r]\n"));
}

int main(int argc, char *argv[]) {
	bool roman_numbers = false;

	if (argc == 2 && strcmp(argv[1], "-r") == 0) {
		roman_numbers = true;
	} else if (argc == 2 && strcmp(argv[1], "--help") == 0) {
		print_help();
		return 0;
	}

	setlocale (LC_ALL, "");
	bindtextdomain ("guess", LOCALE_PATH);
	textdomain ("guess");

	if (roman_numbers) {
		printf(_("Guess a number between from I to L\n"));
	} else {
		printf(_("Guess a number between from 1 to 100\n"));
	}

	int low = 1;
	int high = 100;
	char answer[128];

	while(1) {
		int middle = (low + high) / 2;
		if (low == high) {
			if (roman_numbers) {
				printf(_("The number is %s!\n"), convert_int_to_roman(middle));
			} else {
				printf(_("The number is %d!\n"), middle);
			}
			break;
		}
		if (roman_numbers) {
			printf(_("Is the number bigger than %s? (yes/no)\n"), convert_int_to_roman(middle));
		} else {
			printf(_("Is the number bigger than %d? (yes/no)\n"), middle);
		}
		scanf("%s", answer);
		if (strcmp(answer, _("yes")) == 0) {
			low = middle + 1;
		} else if (strcmp(answer,_("no")) == 0) {
			high = middle;
		} else {
			if (roman_numbers) {
				printf(_("Please try again. If your guess number is bigger than %s, print 'yes', otherwise print 'no'\n"), convert_int_to_roman(middle));
			} else {
				printf(_("Please try again. If your guess number is bigger than %d, print 'yes', otherwise print 'no'\n"), middle);
			}
			
		}
	}
	return 0;
}
