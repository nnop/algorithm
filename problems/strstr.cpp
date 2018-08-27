#include <cstring>
#include <iostream>

using namespace std;

/*
 * @param source: source string to be scanned.
 * @param target: target string containing the sequence of characters to match
 * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
 */
int strStr(const char *source, const char *target) {
  if (source == nullptr || target == nullptr)
    return -1;

  if (strlen(target) == 0)
    return 0;

  char *src = (char *)source;
  for (; *src != '\0'; ++src) {
    char *p = src, *q = (char *)target;;
    for (; *p != '\0' && *q != '\0'; ++p, ++q) {
      // cout << "src: " << *p << ", dst: " << *q << endl;
      if (*p != *q)
        break;
    }
    if (*q == '\0')
      return src - source;
  }

  return -1;
}

int main(int argc, char *argv[])
{
  const char *source = "", *target = "";
  cout << strStr(source, target) << endl;
  return 0;
}
