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

    string serialize(TreeNode* root) {
        if (!root) return "";

        string res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur) {
                res += to_string(cur->val) + ",";
                q.push(cur->left);
                q.push(cur->right);
            } else {
                res += "#,";
            }
        }

        return res;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<string> vals;
        string cur;

        for (char c : data) {
            if (c == ',') {
                vals.push_back(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }

        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < vals.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (vals[i] != "#") {
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }
            i++;

            if (i < vals.size() && vals[i] != "#") {
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};
