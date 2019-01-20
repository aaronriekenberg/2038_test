# 2038_test

1. Convert 2038/01/19 03:14:07 UTC to struct tm (striptime)
2. Convert struct tm to time_t (gmtime)
3. Print result time_t (0x7fffffff)
4. Convert time_t back to string with gmtime_r, strftime
5. Add 1 to time_t (0x80000000)
6. Convert time_t back to string with gmtime_r, strftime

Good result (openbsd, 64-bit linux, 64-bit macos):

```
time = 0x7fffffff
time = 2038/01/19 03:14:07
time + 1 = 0x80000000
time + 1 = 2038/01/19 03:14:08
```

Bad result (32-bit linux):

```
time = 0x7fffffff
time = 2038/01/19 03:14:07
time + 1 = 0x80000000
time + 1 = 1901/12/13 20:45:52
```
