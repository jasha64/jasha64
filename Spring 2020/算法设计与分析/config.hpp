#include <string>
using namespace std;

struct Config
{
    string root, longPath, shortPath1, shortPath2, resultPath;
    int k, minOutputLength;
    Config(string name, int k, int minOutputLength = 400) : k(k), minOutputLength(minOutputLength)
    {
        root = "./";
        longPath = "./" + name + "/long_repair.fasta";  // DEPRECATED
        shortPath1 = "./" + name + "/short_1.fasta";
        shortPath2 = "./" + name + "/short_2.fasta";
        resultPath = "./" + name + "/result.fasta";
    }
};

#ifdef DATA1
Config cfg("data1", 29);
#endif
#ifdef DATA2
Config cfg("data2", 31);
#endif
#ifdef DATA3
Config cfg("data3", 23);
#endif
#ifdef DATA4
Config cfg("data4", 23);
#endif

