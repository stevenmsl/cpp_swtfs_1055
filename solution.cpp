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
  -

*/

int Solution::shortestWay(string source, string target)
{
  const int S = source.size();
  const int T = target.size();
  auto result = 0, skips = 0, i = 0, j = 0;

  while (i < T)
  {
    if (source[j] == target[i])
      skips = 0, i++;
    else
    {
      skips++;
      if (skips == S)
        return -1;
    }

    j++;
    if (j == S || i == T)
      result++, j = 0;
  }

  return result;
}