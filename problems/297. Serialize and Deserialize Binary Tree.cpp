/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    struct DataBlock
    {
        char flag;
        int32_t val;
    };
    void serRecur(TreeNode* node, string& s)
    {
        DataBlock data;
        memset(&data,0,sizeof(data));

        if(node == nullptr)
        {
            data.flag = '#';
            s.append((char*)&data, sizeof(DataBlock));
            return;
        }
        data.flag = '@';
        data.val = node->val;
        s.append((char*)&data, sizeof(DataBlock));        

        serRecur(node->left, s);
        serRecur(node->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serRecur(root, res);
        return res;
    }

    TreeNode* deserRecur(DataBlock* baseAddr, int& index)
    {
        auto* block = ptrByIndex(baseAddr, index);
        if(block->flag == '#')
            return nullptr;

        auto* node = new TreeNode(block->val);
        ++index;
        node->left = deserRecur(baseAddr,index);
        ++index;
        node->right = deserRecur(baseAddr,index);
        return node;
    }

    DataBlock* ptrByIndex(DataBlock* baseAddr, int index)
    {
        return (DataBlock*)((long long)baseAddr + ((long long)index * (long long)sizeof(DataBlock)));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return nullptr;

        DataBlock* block = (DataBlock*)data.data();
        if(block->flag == '#')
            return nullptr;
        int dataSize = data.size();
        int objCnt = dataSize / sizeof(DataBlock);

        auto* root = new TreeNode(block->val);
        int curIndex = 0;
        ++curIndex;
        root->left = deserRecur(block, curIndex);
        ++curIndex;
        root->right = deserRecur(block, curIndex);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));