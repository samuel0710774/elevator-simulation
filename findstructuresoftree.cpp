#include "findstructuresoftree.h"

FindStructuresOfTree::FindStructuresOfTree()
{
    ans = "";
}
void FindStructuresOfTree::buildPostorder(vector<char> const &inorder, int start, int end,
                   vector<char> const &preorder, int &preIndex,
                   unordered_map<char,char> &map){
    if (start > end)
        return;

    char value = preorder[preIndex++];


    if (start == end){
        //字串加字元時不能用ans+=value
        ans = ans + value;
        return;
    }
    int i = map[value];
    buildPostorder(inorder, start, i - 1, preorder, preIndex, map);
    buildPostorder(inorder, i + 1, end, preorder, preIndex, map);
    ans = ans + value;
}

void FindStructuresOfTree::findPostorder(vector<char> const &inorder, vector<char> const &preorder){
    unordered_map<char,char> map;

    for (int i = 0; i < inorder.size(); i++)
        map[inorder[i]] = i;

    int preIndex = 0;

    buildPostorder(inorder, 0, inorder.size() - 1, preorder, preIndex, map);
}

string FindStructuresOfTree::solve(string s)
{
    ans = "";
    //s = pre-order in-order
    stringstream ss;
    node first;
    string  pre, in;
    ss << s;
    ss >> pre >>in;

    vector<char> inorder  = strToVecChar(in);
    vector<char> preorder = strToVecChar(pre);
    findPostorder(inorder, preorder);
    ans.resize(s.size());
    return ans;
}
vector<char> FindStructuresOfTree::strToVecChar(string s){
    vector<char> vec(s.length());
    for(int i=0; i<s.length() ; i++){
        vec[i] = s[i];
    }
    return vec;
}
