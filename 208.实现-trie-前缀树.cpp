/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 * 实现前缀树 要先实现节点
 */

// @lc code=start
#include <string>
using namespace std;
class TrieNode
{
public:
    TrieNode()
    {
    }
    TrieNode *mChildren[26] = {nullptr};
    bool mIsWord = false;
};
class Trie
{
public:
    Trie()
    {
        mRoot = new TrieNode;
    }

    void insert(string word)
    {
        TrieNode *node = mRoot;
        for (int i = 0; i < word.size(); i++)
        {
            auto c = word.at(i);
            if (!node->mChildren[c - 'a'])
            {
                node->mChildren[c - 'a'] = new TrieNode;
            }
            node = node->mChildren[c - 'a'];
        }
        node->mIsWord = true;
    }

    bool search(string word)
    {
        bool result = true;
        TrieNode *node = mRoot;
        for (int i = 0; i < word.size(); i++)
        {
            auto c = word.at(i);
            if (node->mChildren[c - 'a'])
                node = node->mChildren[c - 'a'];
            else
                return false;
        }
        return node->mIsWord;
    }

    bool startsWith(string prefix)
    {
        bool result = true;
        TrieNode *node = mRoot;
        for (int i = 0; i < prefix.size(); i++)
        {
            auto c = prefix.at(i);
            if (node->mChildren[c - 'a'])
                node = node->mChildren[c - 'a'];
            else
            {
                result = false;
                break;
            }
        }
        return result;
    }

private:
    TrieNode *mRoot = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
