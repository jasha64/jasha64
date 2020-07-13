#include "config.hpp"
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

inline char comp(char c)
{
    switch (c)
    {
        case 'A': return 'T';
        case 'G': return 'C';
        case 'C': return 'G';
        case 'T': return 'A';
        case 'N': return 'N';
    }
    throw new invalid_argument("Input should be 'A', 'G', 'C', 'T', 'N'");
}

inline int c2i(char c)
{
    switch (c)
    {
        case 'A': return 0;
        case 'T': return 1;
        case 'G': return 2;
        case 'C': return 3;
    }
    throw new invalid_argument("Input should be 'A', 'G', 'C', 'T'");
}

inline char i2c(int i)
{
    switch (i)
    {
        case 0: return 'A';
        case 1: return 'T';
        case 2: return 'G';
        case 3: return 'C';
    }
    throw new invalid_argument("Input should be 0~3");
}

class Genome {
public:
    string data;
    Genome() {}
    Genome(string t): data(t) {}
    Genome reverse() const
    {
        Genome ret(this->data);
        std::reverse(ret.data.begin(), ret.data.end());
        return ret;
    }
    Genome complement() const
    {
	    Genome ret(this->data);
        for (int i = 0; i < ret.data.size(); i++) ret.data[i] = comp(ret.data[i]);
        return ret;
    }
    friend bool operator <  (const Genome& a, const Genome& b) { return a.data < b.data; }
    friend bool operator == (const Genome& a, const Genome& b) { return a.data == b.data; }
    vector<Genome> kmers(int k) const
    {
        vector<Genome> ret;
        for (int i = 0; i + k <= data.length(); i++)
            ret.push_back(Genome(data.substr(i, k)));
        return ret;
    }
    Genome firstKm1mer() const { return Genome(data.substr(0, data.length() - 1)); }
        // Km1mer: K-1 mer (K minus 1 mer)
    Genome secondKm1mer() const { return Genome(data.substr(1, data.length())); }
    const char lastChar() { return data[data.length() - 1]; }
    const char firstChar() { return data[0]; }
    vector<char> getRawData() const
    {
        vector<char> ret;
        for (const char c : data) ret.push_back(c);
        return ret;
    }
};

void extendGenomes(vector<Genome>& genomes)
{
    // reverse
    vector<Genome> rev;
    for (const Genome& g : genomes) rev.push_back(g.reverse());
    genomes.insert(genomes.end(), rev.begin(), rev.end());
    
    // complement and reverse complement
    int sz = genomes.size();
    for (int i = 0; i < sz; i++)
        genomes.push_back(genomes[i].complement());
}

vector<Genome> readFasta(string path)
{
    auto f = fopen(path.c_str(), "r");
    char s[1001];

    vector<Genome> ret;
    while (fscanf(f, "%*s\n%s\n", s) != EOF) ret.push_back(Genome(s));

    printf("%d genomes read from %s\n", (int)ret.size(), path.c_str());
    return ret;
}

void writeFasta(const vector<Genome>& genomes, string path, int threshold)
{
    auto f = fopen(path.c_str(), "w");
    int minLen = 0x3f3f3f3f, maxLen = 0, totLen = 0;
    for (int i = 0; i < genomes.size(); i++)
    {
        int len = genomes[i].data.length();
        if (len < threshold) continue;
        minLen = min(minLen, len); maxLen = max(maxLen, len); totLen += len;
    	fprintf(f, "> %d\n", i); fprintf(f, "%s\n", genomes[i].data.c_str());
    }
    printf("avg len %d, max %d, min %d\n", totLen / (int)genomes.size(), maxLen, minLen); fflush(stdout);
}

