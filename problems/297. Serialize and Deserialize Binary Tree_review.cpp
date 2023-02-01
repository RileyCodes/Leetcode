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

    // Encodes a tree to a single string.

    struct Data
    {
        bool isData = false;
        int val;
    };

    void _serialize(TreeNode* node, stringstream& s)
    {
        if(node == nullptr)
        {
            Data data;
            s.write((char*)&data,sizeof(data));
            return;
        }
        Data data;
        data.isData = true;
        data.val = node->val;
        s.write((char*)&data,sizeof(data));
        _serialize(node->left, s);
        _serialize(node->right, s);
    }

    string serialize(TreeNode* root) {
        stringstream ss;
        _serialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.

    TreeNode* _deserialize(string& input, const char*& in)
    {
        Data data;

        memcpy((void*)&data , in, sizeof(data));
        in = (char*)((long long)in + sizeof(Data));
        if(!data.isData)
            return nullptr;
        TreeNode* node = new TreeNode(data.val);
        node->left = _deserialize(input, in);
        node->right = _deserialize(input, in);

        return node;
    }

    TreeNode* deserialize(string data) {
        const char* in = data.c_str();
        return _deserialize(data, in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));