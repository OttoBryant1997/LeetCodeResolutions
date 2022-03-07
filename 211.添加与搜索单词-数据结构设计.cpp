/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
#include <string>
using namespace std;
class TrieNode
{
public:
    bool mIsWord = false;
    TrieNode *mChildren[26] = {nullptr};
};
class WordDictionary
{
public:
    WordDictionary()
    {
        mRoot = new TrieNode;
    }

    void addWord(string word)
    {
        auto node = mRoot;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->mChildren[word[i] - 'a'])
                node->mChildren[word[i] - 'a'] = new TrieNode;
            node = node->mChildren[word[i] - 'a'];
        }
        node->mIsWord = true;
    }

    bool search(string word)
    {
        return search(word.c_str(), mRoot);
    }

private:
    TrieNode *mRoot = nullptr;
    bool search(const char *word, TrieNode *node)
    {
        for (int i = 0; word[i] && node; i++)
        {
            if (word[i] != '.')
                node = node->mChildren[word[i] - 'a'];
            else
            {
                TrieNode *tmp = node;
                for (int j = 0; j < 26; j++)
                {
                    node = tmp->mChildren[j];
                    if (search(word + i + 1, node))
                        return true;
                }
            }
        }
        return node && node->mIsWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
