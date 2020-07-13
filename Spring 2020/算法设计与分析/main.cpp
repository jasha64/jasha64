#include "debruijn.cpp"

int main()
{
    auto genomes = readFasta(cfg.shortPath1);
    auto tmp = readFasta(cfg.shortPath2);
    genomes.insert(genomes.end(), tmp.begin(), tmp.end());
    // tmp = readFasta(cfg.longPath);
    // genomes.insert(genomes.end(), tmp.begin(), tmp.end());

    extendGenomes(genomes);

    auto graph = new DeBruijnGraph(genomes, cfg);
    graph->removeBubble();

    auto res = graph->exportPaths();
    // auto res = graph->exportPathsLengthFirst();
    extendGenomes(res);

    writeFasta(res, cfg.resultPath, cfg.minOutputLength);
    return 0;
}

