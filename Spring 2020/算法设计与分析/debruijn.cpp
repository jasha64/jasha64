#include "genome.cpp"

struct DBGEdge;

struct DBGNode : Genome {
    DBGEdge* from[4];
    DBGEdge* to[4];
    int id;
    bool rm;
    DBGNode(Genome g): rm(false), from{}, to{} { data = g.data; }
    int outd() const
    {
        int n = 0;
        for (int i = 0; i < 4; i++)
            if (to[i] != nullptr) n++;
        return n;
    }
    int ind() const
    {
        int n = 0;
        for (int i = 0; i < 4; i++)
            if (from[i] != nullptr) n++;
        return n;
    }
};

struct DBGEdge {
    DBGNode* node;
    int cvg;
    int leadToLoop;
    bool vis, rm;
    DBGEdge(DBGNode* node = nullptr, int cvg = 0)
        : node(node)
        , cvg(cvg)
        , leadToLoop(0)
        , vis(false)
        , rm(false)
    {}
};

struct DeBruijnGraph {
    vector<DBGNode*> nodes;
    map<Genome, int> toId;  // We use hash to store DBG nodes, otherwise it's costly

    vector<int> extLen;
    Config cfg;

    DBGNode* getNode(Genome mer)
    {
        if (toId.find(mer) == toId.end())
        {
            DBGNode* newNode = new DBGNode(mer);
            toId[mer] = newNode->id = nodes.size();
            nodes.push_back(newNode);
            return newNode;
        } 
        return nodes[toId[mer]];
    }
    void addEdge(DBGEdge*& edges, DBGNode* node)
    {
        if (edges == nullptr) edges = new DBGEdge(node, 0);
        edges->cvg++;
    }
    DeBruijnGraph(vector<Genome>& genomes, Config cfg)
        : cfg(cfg)
    {
        printf("deBruijn Graph in construction... "); fflush(stdout);
        for (const Genome& genome : genomes) 
            for (const Genome& kmer : genome.kmers(cfg.k))
            {
                DBGNode* prev = getNode(kmer.firstKm1mer());
                DBGNode* curr = getNode(kmer.secondKm1mer());
                if (curr->lastChar() != 'N')
                    addEdge(prev->to[c2i(curr->lastChar())], curr);
                else {
                    for (int i = 0; i < 4; i++)
                        addEdge(prev->to[i], curr);
                }
                if (prev->firstChar() != 'N')
                    addEdge(curr->from[c2i(prev->firstChar())], prev);
                else {
                    for (int i = 0; i < 4; i++)
                        addEdge(curr->from[i], prev);
                }
            }
        printf("complete\n"); fflush(stdout);
    }
    
    void walkThroughBubble(DBGNode* u, vector<pair<DBGNode*, int>>& path)
    {
        while (u->outd() == 1)
        {
            int i;
            for (i = 0; i < 4; i++)
                if (u->to[i] != nullptr) break;            
            
            path.push_back(make_pair(u, i));
            u = u->to[i]->node;
            if (u->ind() != 1) break;  // another branch
        }
    }
    void removeBubble()
    {
        int numBubble = 0;
        for (const auto& u : nodes)
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                {
                    DBGEdge* x = u->to[i];
                    DBGEdge* y = u->to[j];
                    if (i == j || x == nullptr || y == nullptr) continue;
                    if ((double)x->cvg / y->cvg < 0.7) {
                        vector<pair<DBGNode*, int>> xpath, ypath;
                        xpath.push_back(make_pair(u, i));
                        ypath.push_back(make_pair(u, j));
                        walkThroughBubble(x->node, xpath);
                        walkThroughBubble(y->node, ypath);

                        DBGNode* tgt_x = xpath.back().first->to[xpath.back().second]->node;
                        DBGNode* tgt_y = ypath.back().first->to[ypath.back().second]->node;
                        if (tgt_x != tgt_y || xpath.size() < cfg.k / 2)
                        {
                            printf("Walk node %d, %d\n", tgt_x->id, tgt_y->id);
                            continue;
                        }

                        ++numBubble;
                        DBGNode* lst = xpath.back().first;
                        DBGNode* tgt = lst->to[xpath.back().second]->node;
                        for (int k = 0; k < 4; k++)
                            if (tgt->from[k] != nullptr && tgt->from[k]->node == lst)
                                tgt->from[k] = nullptr;
                        u->to[i]->node->rm = true;  // remove node
                        u->to[i] = nullptr;
                    }
                }
        printf("Bubbles removed!\n"); fflush(stdout);
    }

    vector<int> DFN;
    int idx;
    int dfsFindLoop(const DBGNode* u)
    {
        DFN[u->id] = ++idx;
        int uLow = DFN[u->id];
        for (int i = 0; i < 4; i++)
        {
            DBGEdge* v = u->to[i];
            if (v == nullptr) continue;
            if (DFN[v->node->id] == 0)
            {
                int vLow = dfsFindLoop(v->node);
                if (vLow < uLow)
                {
                    uLow = vLow;
                    if (u->outd() > 1) v->leadToLoop = vLow;  // branch point
                }
            }
            else uLow = min(uLow, DFN[v->node->id]);
        }
        return uLow;
    }
    void findLoop()
    {
        DFN.resize(nodes.size());
        for (const DBGNode* u : nodes)
            if (u->ind() == 0)
            {
                printf("Finding loop for node %d ... ", u->id);  fflush(stdout);
                idx = 0; fill(DFN.begin(), DFN.end(), 0);
                dfsFindLoop(u);
                printf("done\n"); fflush(stdout);
            }
    }
    void followLoopFirst(DBGNode* u, vector<char>& path)
    {
        bool hasLoop = false;
        for (int i = 0; i < 4; i++)
        {
            DBGEdge* v = u->to[i];
            if (v != nullptr && v->leadToLoop != 0 && !v->vis)
            {
                path.push_back(i2c(i));
                v->vis = true;
                followLoopFirst(v->node, path);
                hasLoop = true;
            }
        }
        if (!hasLoop)
            for (int i = 0; i < 4; i++)
            {
                DBGEdge* v = u->to[i];
                if (v != nullptr && v->leadToLoop == 0)
                {
                    path.push_back(i2c(i));
                    followLoopFirst(v->node, path);
                    break;
                }
            }
    }
    vector<Genome> exportPaths()
    {
        findLoop();
        vector<Genome> res;
        for (const auto& u : nodes)
            if (u->ind() == 0)
            {
                auto path = u->getRawData();
                followLoopFirst(u, path);
                res.push_back(string(path.begin(), path.end()));
            }
        return res;
    }

    int dfsExtLen(int curid)
    {
        if (extLen[curid] != 0) return extLen[curid];
        auto curr = nodes[curid];
        extLen[curid] = 1;
        int maxSucc = 0;
        for (int i = 0; i < 4; i++)
        {
            const DBGEdge* to = curr->to[i];
            if (to != nullptr && !to->rm)
                maxSucc = max(maxSucc, dfsExtLen(to->node->id));
        }
        extLen[curid] += maxSucc;
        return extLen[curid];
    }
    DBGNode* calcExtLen()
    {
        extLen.resize(nodes.size());
        fill(extLen.begin(), extLen.end(), 0);

        int maxLen = 0;
        DBGNode* u;
        for (int i = 0; i < nodes.size(); i++)
        {
            int len = dfsExtLen(i);
            if (maxLen < len) { maxLen = len; u = nodes[i]; }
        }

        printf("Extend length: %d\n", maxLen); fflush(stdout);
        return u;
    }
    void followMaxExtLen(DBGNode* curr, vector<char>& path)
    {
        if (extLen[curr->id] == 1) return;
        for (int i = 0; i < 4; i++)
            if (curr->to[i] != nullptr && !curr->to[i]->rm)
            {
                DBGNode* next = curr->to[i]->node;
                if (extLen[next->id] == extLen[curr->id] - 1)
                {
                    path.push_back(i2c(i));
                    curr->to[i]->rm = true;
                    followMaxExtLen(next, path);
                    break;
                }
            }
    }
    vector<Genome> exportPathsLengthFirst()
    {
        vector<Genome> res;
        while (true)
        {
            DBGNode* u = calcExtLen();
            if (extLen[u->id] < cfg.minOutputLength)  break;
            vector<char> path = u->getRawData();
            followMaxExtLen(u, path);
            res.push_back(string(path.begin(), path.end()));
        }
        return res;
    }

};
