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

void BinaryTree::reInsert(TreeNode* Node)
{
	//if its empty establish inputted node as root

	TreeNode* currentNode = m_pRoot;
	if (IsEmpty() == true)
	{
		m_pRoot = Node;
		return;
	}

	while (currentNode != nullptr)
	{
		//the value is less, go left
		if (Node->GetData() < currentNode->GetData())
		{
			if (currentNode->HasLeft() == false)
			{
				break;
			}
			currentNode = currentNode->GetLeft();
		}
		else if (Node->GetData() > currentNode->GetData())
		{
			if (currentNode->HasRight() == false)
			{
				break;
			}
			currentNode = currentNode->GetRight();
		}
		else if (Node->GetData() == currentNode->GetData())
		{
			cout << "Number already exist in the tree." << endl;
			return; 
		}
	}
	if (Node->GetData() < currentNode->GetData())
	{
		currentNode->SetLeft(Node);
	}
	else
	{
		currentNode->SetRight(Node);
	}
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
	ppOutParent = nullptr;
	ppOutNode = m_pRoot;

	while (a_nSearchValue != ppOutNode->GetData())
	{
		if (a_nSearchValue < ppOutNode->GetData() )
		{
			if(ppOutNode->GetLeft() != nullptr)
			{
				ppOutParent = ppOutNode;
				ppOutNode = ppOutNode->GetLeft();
		    }   
			else
			{
				return false;
			}
		}
		else if (a_nSearchValue > ppOutNode->GetData())
		{
			if (ppOutNode->GetRight() != nullptr)
			{
				ppOutParent = ppOutNode;
				ppOutNode = ppOutNode->GetRight();
			}
			else
			{
				return false;
			}
		}
	}
}

void BinaryTree::Remove(int a_nValue)
{
	
	currentNode = nullptr;
	currentParent = m_pRoot;
	////create a copy to store 2 nodes into
	TreeNode* leftChild;
	TreeNode* rightChild;
	
	//return current to remove and its parents
	FindNode(a_nValue, currentNode, currentParent);

	if (currentNode == nullptr)
	{
		return;
	}
	
	leftChild = currentNode->GetLeft();
	rightChild = currentNode->GetRight();

	if (currentParent != nullptr)
	{
		if (currentParent->GetLeft() == currentNode)
		{
			currentParent->SetLeft(nullptr);
		}
		else if (currentParent->GetRight() == currentNode)
		{
			currentParent->SetRight(nullptr);
		}
	}
		
	
	if (currentNode == m_pRoot)
	{
		m_pRoot = nullptr;
	}

	currentNode = nullptr;


	if (leftChild != nullptr)
	{
		reInsert(leftChild);
	}

	if (rightChild != nullptr)
	{
		reInsert(rightChild);
	}
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