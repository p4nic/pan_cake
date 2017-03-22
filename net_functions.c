#include <stdio.h>
#include <curl/curl.h>
#include "net_functions.h"

// WRITING DATA

size_t WriteData(void *ptr, size_t size, size_t nmemb, FILE *stream) {
	size_t written = fwrite(ptr, size, nmemb, stream);
	return written;
}

// DIY WGET

int DownloadFiles(const char * url, const char * outfile) {

	CURL *curl;
	FILE *fp;
	CURLcode res;

	//char *url = "http://cnc.com/pubkey.pub"; 
	//char outfile[FILNAME_MAX] = "/tmp/pubkey.pub";

	curl = curl_easy_init();

	if(curl) {
		fp = fopen(outfile, "wb");

		curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
        fclose(fp);
	}
  
	return 0;
}
