#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h> // To handle errors
#include <string.h> // To handle strerror

void handleErrors(int);

int main(int argc, const char* argv[])
{
  if (argc < 3) return 1;

  errno = 0;

  const int fdread = open(argv[1], O_RDONLY);

  if (fdread == -1) {
    handleErrors(errno);
    return 1;
  }

  const int fdwrite = open(argv[2], O_APPEND | O_WRONLY | O_CREAT, 0666);


  // Should build a wrapper for all the function calls, will use this for now
  if (fdwrite == -1) {
    handleErrors(errno);
    return 1;
  }

  char *buff;
  ssize_t size;

  do {
    size = read(fdread, buff, 1);
    write(fdwrite, buff, 1);
  } while (size != 0);
}

void handleErrors(int errnumber) {
  char *err = strerror(errnumber);
  write(1, err,  strlen(err));
}
