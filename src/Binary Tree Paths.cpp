#include "catch.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using std::vector;
using std::string;
using std::stringstream;
using std::find;

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    vector<TreeNode*> path;
    Visit(root, path, result);
    return result;
  }

  void Visit(TreeNode* node, vector<TreeNode*>& path, vector<string>& result) {
    if (!node) {
      return;
    }
    path.push_back(node);
    bool is_leaf = true;
    if (node->left) {
      Visit(node->left, path, result);
      is_leaf = false;
    }
    if (node->right) {
      Visit(node->right, path, result);
      is_leaf = false;
    }
    if (is_leaf) {
      stringstream stream;
      for (size_t index = 0; index < path.size(); ++index) {
        if (index != 0) {
          stream << "->";
        }
        stream << path.at(index)->val;
      }
      result.push_back(stream.str());
    }
    path.pop_back();
  }
};

void FreeTree(TreeNode* root) {
  if (root) {
    FreeTree(root->left);
    FreeTree(root->right);
    delete root;
  }
}

TEST_CASE("Test the solution for problem 'Binray Tree Paths'") {
  Solution sln_instance;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  vector<string> result = sln_instance.binaryTreePaths(root);
  REQUIRE(find(result.cbegin(), result.cend(), "1->2->5") != result.cend());
  REQUIRE(find(result.cbegin(), result.cend(), "1->3") != result.cend());
  FreeTree(root);
}