#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> graph;
    int nodeNum;

    Solution() : nodeNum(0) {}

    // 精妙的抽象，这个函数大幅简化了编程
    void addWord(string &word) {
        if (!wordId.count(word)) {
            wordId[word] = nodeNum++;
            graph.emplace_back();
        }
    }

    void addEdge(string &word) {
        addWord(word);
        int fullWordID = wordId[word];
        for (auto &it : word) {
            char temp = it;
            it = '*';
            addWord(word);
            int subWordID = wordId[word];
            graph[fullWordID].push_back(subWordID);
            graph[subWordID].push_back(fullWordID);
            it = temp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (beginWord.empty() || endWord.empty()) {
            return 0;
        }

        for (auto word: wordList) {
            addEdge(word);
        }
        addEdge(beginWord);
        if (auto it = wordId.find(endWord); it == wordId.end()) {
            return 0;
        }

        vector<int> dis = vector<int>(wordId.size(), -1);
        dis[wordId[beginWord]] = 0;
        queue<int> q;
        q.push(wordId[beginWord]);
        int targetID = wordId[endWord];
        int res = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                int top = q.front();
                // cout << "top: " << top << endl;
                q.pop();
                if (top == targetID) {
                    return dis[top] / 2 + 1;
                }
                for (auto id : graph[top]) {
                    if (dis[id] == -1) {
                        dis[id] = dis[top] + 1;
                        q.push(id);
                    }
                }
            }
            res++;
        }
        return 0;
    }
};


/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

        // give every word an id
        int id = 0;
        unordered_map<string, int> word2id;
        for (auto word : wordList) {
            word2id[word] = id;
            id++;
        }

        // if endWord not exist in word set, return now
        if (word2id.find(endWord) == word2id.end()) {
            return 0;
        }

        // build graph, graph conn id - word.
        vector<unordered_set<string>> graph = vector<unordered_set<string>>(id);
        unordered_map<string, int> w2id;
        for (auto it : word2id) {
            string word = it.first;
            cout << "word: " << word << endl;
            for (int i = 0; i < word.size(); i++) {
                // build word - id
                graph[it.second].insert(word);
                // build subWord - id
                char temp = word[i];
                word[i] = '*';
                cout << "word[i] " << word << " it.second " << it.second << endl;
                w2id[word] = it.second;
                word[i] = temp;
            }
        }

        // for (int i = 0; i < graph.size(); i++)  {
        //     auto x = graph[i];
        //     for (auto y : x) {
        //         cout << "i: " << i << " y: " << y << endl;
        //     }
        // }

        // push subWord in queue
        queue<string> q;
        for (int i = 0; i < beginWord.size(); i++) {
            char temp = beginWord[i];
            beginWord[i] = '*';
            q.push(beginWord);
            beginWord[i] = temp;
        }

        int targetID = word2id[endWord];
        int res = 0;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                string subWord = q.front();
                cout << "subWord: " << subWord << endl;
                auto it = w2id.find(subWord);
                if (it == w2id.end()) {
                    // continue;
                    break;
                }
                if (it->second == targetID) {
                    return res;
                }
                cout << "it->first " << it->first << " it->second " << it->second << endl;
                for (auto word: graph[it->second]) {
                    for (int i = 0; i < word.size(); i++) {
                        char temp = word[i];
                        word[i] = '*';
                        q.push(word);
                        word[i] = temp;
                    }
                }
                q.pop();
            }
            res++;
        }
        return res;
    }
};
*/

/*
 * 题没读清楚就开始写...写了个成语头尾接龙的效果 :)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

        if (beginWord.empty() || endWord.empty()) {
            return 0;
        }

        vector<vector<int>> graph = vector<vector<int>>(26);
        for (int i = 0; i < wordList.size(); i++) {
            string word = wordList[i];
            // cout << "word: " << word << endl;
            int f = word[0] - 'a';
            int e = word.back() - 'a';
            // cout << "f: " << f << " e " << e << endl;
            graph[f].push_back(e);
        }

        queue<int> q;
        q.push(beginWord[0] - 'a');
        int target = endWord.back() - 'a';
        // cout << "x: " <<beginWord[0] - 'a' <<  " y " << endWord.back() - 'a';
        int res = 0;
        while (!q.empty()) {
            int qsize = q.size();
            res++;
            for (int i = 0; i < qsize; i++) {
                int top = q.front();
                if (top == target) {
                    return res;
                }
                q.pop();
                if (!graph[top].empty()) {
                    for (auto x : graph[top]) {
                        q.push(x);
                    }
                }
            }
        }
        return 0;
    }
};
*/