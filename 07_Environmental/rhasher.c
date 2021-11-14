#include "rhash.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <config.h>

#ifdef READLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif

int main(int argc, char *argv[]) {

	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	char *hash_algorithm_name;
	char *string_or_file_to_hash;
	
	#ifdef READLINE
	while (1) {
		if (line) {
			free(line);
		}
		line = readline(NULL);
		add_history(line);
	#else
	while ((nread = getline(&line, &len, stdin)) != -1) {
		line[nread - 1] = '\0';
	#endif
		if ((hash_algorithm_name = strtok(line, " ")) == NULL) {
			fprintf(stderr, "Hash algorithm name is missing\n");
			continue;
		}

		string_or_file_to_hash = strtok(NULL, " ");
		if (string_or_file_to_hash == NULL) {
			fprintf(stderr, "String or file to hash is missing\n");
			continue;
		}

		enum rhash_ids hash_algorithm_id;
		if ((strcasecmp(hash_algorithm_name, "sha1")) == 0) {
			hash_algorithm_id = RHASH_SHA1;
		} else if ((strcasecmp(hash_algorithm_name, "md5")) == 0) {
			hash_algorithm_id = RHASH_MD5;
		} else if ((strcasecmp(hash_algorithm_name, "tth")) == 0) {
			hash_algorithm_id = RHASH_TTH;
		} else {
			fprintf(stderr, "Unsupported hash algorithm\n");
			continue;
		}

		int output_hash_format = (hash_algorithm_name[0] == tolower(hash_algorithm_name[0])) ? RHPR_BASE64 : RHPR_HEX;

		char digest[64];
		char output[130];
		rhash_library_init();

		if (string_or_file_to_hash[0] == '"') {
			string_or_file_to_hash++;
			int res = rhash_msg(hash_algorithm_id, string_or_file_to_hash, strlen(string_or_file_to_hash), digest);
			if(res < 0) {
				fprintf(stderr, "message digest calculation error\n");
				continue;
			}
		} else {
			int res = rhash_file(hash_algorithm_id, string_or_file_to_hash, digest);
			if(res < 0) {
				fprintf(stderr, "LibRHash error: %s: %s\n", string_or_file_to_hash, strerror(errno));
				continue;
			}
		}
		rhash_print_bytes(output, digest, rhash_get_digest_size(hash_algorithm_id), output_hash_format);
		printf("%s\n", output);
	}

	return 0;
}