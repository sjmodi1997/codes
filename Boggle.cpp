#define MAX 26
#define M 1001
#define pb push_back

vector<string> ans;
set<string> st;
bool vis[M][M];
struct TrieNode
{
    bool isEnd;
    struct TrieNode* children[MAX];
};

TrieNode* getNode()
{
    TrieNode* node = new TrieNode;
    node->isEnd = false;
    for(int i=0;i<MAX;i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

void insertTrie(TrieNode* root, string word)
{
    TrieNode* curr = root;
    for(int i=0;i<word.size();i++)
    {
        if(curr->children[word[i]-'a']==NULL)
        {
            curr->children[word[i]-'a'] = getNode();
        }
        curr = curr->children[word[i]-'a'];
    }
    curr->isEnd = true;
}

bool isSafe(int i, int j, int rows, int cols)
{
    if(i>=0 && i<rows && j>=0 && j<cols && !vis[i][j])
        return true;
    return false;
}

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void dfs(TrieNode* curr, int i, int j, vector<vector<char>> board, string str)
{
    //cout << str << endl;
    if(curr->isEnd==true)
    {
        if(st.find(str)==st.end())
            st.insert(str);
    }
    vis[i][j] = true;
    int rows = board.size();
    int cols = board[0].size();
    for(int k=0;k<4;k++)
    {
        int x = i+dx[k];
        int y = j+dy[k];
        if(isSafe(x,y,rows,cols))
        {
            //cout << i << " " << j << " " << x << " " << y << endl;
            char c = board[x][y];
            if(curr->children[c-'a']!=NULL)
            {
                dfs(curr->children[c-'a'],x,y,board,str+c);
            }
        }
    }
    vis[i][j] = false;
}


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int numOfWords = words.size();
        int rows = board.size();
        ans.clear();
        st.clear();
        if(numOfWords==0 || rows==0)
        {
            ans;
        }
        int cols = board[0].size();
        TrieNode* root = getNode();
        for(auto word:words)
        {
            insertTrie(root,word);
        }
        memset(vis,false,size(vis));
        string str = "";
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                char c = board[i][j];
                if(root->children[c-'a']!=NULL)
                {
                    str += c;
                    //cout << c << endl;
                    dfs(root->children[c-'a'],i,j,board,str);
                }
                str = "";
            }
        }
        for(auto s:st)
        {
            ans.pb(s);
        }
        return ans;
    }
};
