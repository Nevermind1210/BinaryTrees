/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>
using namespace std;


BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while (m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const
{
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	//establishing new node from tree node
	TreeNode* n = new TreeNode(a_nValue);
	//if its empty establish inputted node as root
	if (IsEmpty())
	{
		m_pRoot = n;
		return;
	}
	// if node exist then these checks come in to see value
	Insert(m_pRoot, n);
}

void BinaryTree::Insert(TreeNode* parent, TreeNode* n)
{
	//if node is less than the set value then make left as parent
	if (n->GetData() < parent->GetData())
		if (parent->GetLeft() == nullptr){ 
			parent->SetLeft(n);
		}
		else Insert(parent->GetLeft(), n);
	//if node is more than set value then make right as parent
	else if (n->GetData() > parent->GetData())
		if (parent->GetRight() == nullptr){
			parent->SetRight(n);
		}
		else Insert(parent->GetRight(), n);
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent : nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	if (IsEmpty)
	{
		return;
	}

	if (a_nSearchValue = )

	return false;
}

void BinaryTree::Remove(int a_nValue)
{
	TreeNode* n = new TreeNode(a_nValue);

	if (IsEmpty)
	{
		return;
	}
	Remove(GetLeft());
	Remove(GetRight());
	delete n;
}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
	PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{

	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}