#pragma once

size_t WriteData(void *ptr, size_t size, size_t mnemb, FILE *stream);
int DownloadFiles(const char * url, const char *outfile);