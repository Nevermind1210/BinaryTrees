#pragma once

class TreeNode
{
public:
	TreeNode(int value);
	~TreeNode();

	bool HasLeft() { return (m_left != nullptr); }
	bool HasRight() { return (m_right != nullptr); }

	int GetData() { return m_value; }
	TreeNode* GetLeft() { return m_left; }
	TreeNode* GetRight() { return m_right; }

	void SetData(int value) {  }
	void SetLeft(TreeNode* node) { this->m_left = node; }
	void SetRight(TreeNode* node) { this->m_right = node; }

	void Draw(int x, int y, bool selected = false);

	// this could also be a pointer to another object if you like
	int m_value;

private:
	
	// node's children
	TreeNode* m_left;
	TreeNode* m_right;
};
