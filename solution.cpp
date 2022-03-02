#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol1055;
using namespace std;

/*takeaways
  - you can loop through source multiple times to find
    the sequences that can form the target
  - source = abc, target = abcbc
    - we loop through source once
      source =[abc], target=[abc]bc
    - we loop through the source the second time
      source =a[bc], target=[abc][bc]
      - we skip the first char 'c' in S as the remaining
        subsequence in target starts with a 'b'.

  - source = abc, target = acdbc
    - iteration 1
      - source = [a]bc, target = [a]cdbc
      - source = [a]b[c], target = [a][c]dbc

    - iteration 2
      - source = abc, target = [a][c]dbc
      - we have skipped a, b, and c and still can't find
        a match. As we have skipped 3 chars, which
        means the entire source string has been scanned.
        We can't form the target string in this case
      - the char d in the target is not in the source at all

*/

int Solution::shortestWay(string source, string target)
{
  const int S = source.size();
  const int T = target.size();

  /*skips - how many chars you have to skip before
    the next match is found
  */
  auto result = 0, skips = 0, i = 0, j = 0;

  while (i < T)
  {
    if (source[j] == target[i])
      /* found a match; reset the skips */
      skips = 0, i++;
    else
    {
      skips++;
      /* we have skipped the entire source string and still can't find a match
         - that means the target must have some chars don't exist in the source
         - report -1 (not possible) in this case
      */
      if (skips == S)
        return -1;
    }

    j++;
    /*  */
    if (j == S || i == T)
      result++, j = 0;
  }

  return result;
}