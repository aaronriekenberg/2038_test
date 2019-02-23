#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
  struct tm tm;
  time_t time;
  char buffer[80];

  printf("sizeof time_t = %zu\n", sizeof(time_t));

  if (strptime("2038/01/19 03:14:07", "%Y/%m/%d %H:%M:%S", &tm) == NULL) {
    printf("strptime error\n");
    abort();
  }

  time = timegm(&tm);
  printf("time = 0x%08llx\n", time);

  if (gmtime_r(&time, &tm) == NULL) {
    printf("gmtime_r error\n");
    abort();
  }

  if (strftime(buffer, 80, "%Y/%m/%d %H:%M:%S", &tm) == 0) {
    printf("strftime error\n");
    abort();
  }

  printf("time = %s\n", buffer);

  time += 1;
  printf("time + 1 = 0x%08llx\n", time);

  if (gmtime_r(&time, &tm) == NULL) {
    printf("gmtime_r error\n");
    abort();
  }

  if (strftime(buffer, 80, "%Y/%m/%d %H:%M:%S", &tm) == 0) {
    printf("strftime error\n");
    abort();
  }

  printf("time + 1 = %s\n", buffer);

  return 0;
}
