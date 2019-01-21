#include <stdio.h>
#include <time.h>

int main(int argc, char** argv) {
  struct tm tm;
  time_t time;
  char buffer[80];

  printf("sizeof time_t = %zu\n", sizeof(time_t));

  strptime("2038/01/19 03:14:07", "%Y/%m/%d %H:%M:%S", &tm);
  time = timegm(&tm);
  printf("time = 0x%08lx\n", time);

  gmtime_r(&time, &tm);
  strftime(buffer, 80, "%Y/%m/%d %H:%M:%S", &tm);
  printf("time = %s\n", buffer);

  time += 1;
  printf("time + 1 = 0x%08lx\n", time);

  gmtime_r(&time, &tm);
  strftime(buffer, 80, "%Y/%m/%d %H:%M:%S", &tm);
  printf("time + 1 = %s\n", buffer);

  return 0;
}
