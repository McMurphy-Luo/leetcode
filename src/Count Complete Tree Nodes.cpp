#include "catch.hpp"
#include <deque>

using std::deque;

namespace
{
  struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  void DeleteTree(TreeNode* root) {
    if (root) {
      DeleteTree(root->left);
      DeleteTree(root->right);
      delete root;
    }
  }
}


class Solution {
public:
  int countNodes(TreeNode* root) {
    deque<TreeNode*> help_queue;
    int visited = 0;
    if (!root) {
      return 0;
    }
    help_queue.push_back(root);
    
    while (!help_queue.empty()) {
      TreeNode* top = help_queue.front();
      help_queue.pop_front();
      if (!top) {
        break;
      }
      ++visited;
      if (top->left) {
        help_queue.push_back(top->left);
      }
      if (top->right) {
        help_queue.push_back(top->right);
      }
    }
    return visited;
  }
};

TEST_CASE("Test the solution for problem \"Count Complete Tree Nodes\"") {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  Solution solution_instance;
  REQUIRE(solution_instance.countNodes(root) == 6);
  DeleteTree(root);
}
