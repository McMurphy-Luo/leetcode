#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <vector>

using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    
  }
};

void DeleteTree(TreeNode* root) {
  if (root) {
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
  }
}

TEST_CASE("Test the solution for problem \"Find Duplicate Subtrees\"") {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(4);
  root->right->left = new TreeNode(2);
  root->right->left->left = new TreeNode(2);
  Solution solution_instance;
  vector<TreeNode*> dupliate_node_list = solution_instance.findDuplicateSubtrees(root);
  REQUIRE(dupliate_node_list.size() == 2);

  
}