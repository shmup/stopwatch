#include <stdio.h>
#include <time.h>

int main() {
  struct timespec start_time, current_time;
  clock_gettime(CLOCK_MONOTONIC, &start_time);

  while (1) {
    clock_gettime(CLOCK_MONOTONIC, &current_time);
    time_t elapsed_s = current_time.tv_sec - start_time.tv_sec;
    long elapsed_ns = current_time.tv_nsec - start_time.tv_nsec;

    if (elapsed_ns < 0) {
      elapsed_ns += 1000000000L;
      elapsed_s -= 1;
    }

    int hours = elapsed_s / 3600;
    int minutes = (elapsed_s % 3600) / 60;
    int seconds = elapsed_s % 60;
    int hundredths = elapsed_ns / 10000000;

    printf("\r%02d:%02d:%02d.%02d", hours, minutes, seconds, hundredths);
    fflush(stdout);

    // sleep for roughly the remainder of the current hundredth of a second
    struct timespec sleep_duration = {0, 10000000L - (elapsed_ns % 10000000L)};

    nanosleep(&sleep_duration, NULL);
  }

  return 0;
}
