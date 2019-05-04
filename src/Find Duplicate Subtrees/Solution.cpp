#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <sstream>

using std::vector;
using std::pair;
using std::map;
using std::make_pair;
using std::string;
using std::stringstream;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    map<string, vector<TreeNode*>> node_traversal_result_storage;
    TraverseTree(root, &node_traversal_result_storage);
    vector<TreeNode*> result;
    map<string, vector<TreeNode*>>::iterator it = node_traversal_result_storage.begin();
    for (; it != node_traversal_result_storage.end(); ++it) {
      if (it->second.size() > 1) {
        result.push_back(it->second.front());
      }
    }
    return result;
  }

  string TraverseTree(TreeNode* node, map<string, vector<TreeNode*>>* node_traversal_result_storage) {
    if (!node) {
      return "";
    }
    string left_child_traverse_result = TraverseTree(node->left, node_traversal_result_storage);
    string right_child_traverse_result = TraverseTree(node->right, node_traversal_result_storage);
    string me_traversal_result;
    stringstream string_stream;
    string_stream << node->val;
    me_traversal_result.append(string_stream.str());
    me_traversal_result.append(", ");
    me_traversal_result.append(left_child_traverse_result);
    me_traversal_result.append(", ");
    me_traversal_result.append(right_child_traverse_result);
    map<string, vector<TreeNode*>>::iterator it = node_traversal_result_storage->find(me_traversal_result);
    if (it == node_traversal_result_storage->end()) {
      it = node_traversal_result_storage->insert(std::make_pair(me_traversal_result, vector<TreeNode*>())).first;
    }
    it->second.push_back(node);
    return me_traversal_result;
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
  root->right->left->left = new TreeNode(4);
  Solution solution_instance;
  vector<TreeNode*> dupliate_node_list = solution_instance.findDuplicateSubtrees(root);
  REQUIRE(dupliate_node_list.size() == 2);
  REQUIRE(!(
    std::find(dupliate_node_list.begin(), dupliate_node_list.end(), root->left->left) != dupliate_node_list.end()
    &&
    std::find(dupliate_node_list.begin(), dupliate_node_list.end(), root->right->right) != dupliate_node_list.end()
  ));
  REQUIRE(!(
    std::find(dupliate_node_list.begin(), dupliate_node_list.end(), root->left) != dupliate_node_list.end()
    &&
    std::find(dupliate_node_list.begin(), dupliate_node_list.end(), root->right->left) != dupliate_node_list.end()
  ));
  DeleteTree(root);
}


TreeNode* CreateAFuckingTree() {
  TreeNode* root = new TreeNode(0);
  size_t node_count = 100;
  TreeNode* current = root;
  while (node_count > 0) {
    current->right = new TreeNode(0);
    current = current->right;
    --node_count;
  }
  return root;
}

TEST_CASE("Another test case for the problem \"Find Duplicate Subtrees\"") {
  TreeNode* root = CreateAFuckingTree();
  Solution solution_instance;
  vector<TreeNode*> result = solution_instance.findDuplicateSubtrees(root);
  REQUIRE(result.size() == 0);
  DeleteTree(root);
}