#ifndef FINDSTRUCTURESOFTREE_H
#define FINDSTRUCTURESOFTREE_H
#include "mytree.h"

using namespace std;
class FindStructuresOfTree : public MyTree
{
public:
    FindStructuresOfTree();
    ~FindStructuresOfTree(){}
    vector<char> strToVecChar(string);
    void buildPostorder(vector<char> const &inorder, int start, int end,
                       vector<char> const &preorder, int &preIndex,
                       unordered_map<char,char> &map);
    void findPostorder(vector<char> const &inorder, vector<char> const &preorder);
    string solve(string);
private:
    string ans;
};

#endif // FINDSTRUCTURESOFTREE_H
