#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
int main ()
{
char one[]={'h','e','l','l','o'};
char two[]={'h','o',' ','h','o'};

int len = strlen(one);
one[len]=toupper(one[len]);

cout << one << endl;

return 0;

}
