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
void BinaryTree::Insert(int a_nValue)
{
	TreeNode* newNode = new TreeNode(a_nValue);
	TreeNode* currentNode = m_pRoot;
	//if list is empty root node is new node
	if (IsEmpty() == true)
	{
		m_pRoot = newNode;
		return;
	}
	// Finding an empty node
	while (currentNode != nullptr)
	{
		// If the value is less, go left
		if (a_nValue < currentNode->GetData())
		{
			// If the node has no left child, we have found an empty spot and we break out of the loop
			if (!currentNode->HasLeft())
			{
				break;
			}
			// Make the current node the left one
			currentNode = currentNode->GetLeft();
		}

		// If the value is greater, go right
		else if (a_nValue > currentNode->GetData())
		{
			// If the node has no right child, we have found an empty spot and we break out of the loop
			if (!currentNode->HasRight())
			{
				break;
			}
			// Make the current node the right one
			currentNode = currentNode->GetRight();
		}
		// If the number already exists
		else if (a_nValue == currentNode->GetData())
		{
			cout << "Number already exists in list " << endl;
			return;
		}
	}
	// Once the empty node has been found, set the value
	if (a_nValue < currentNode->GetData())
	{
		currentNode->SetLeft(newNode);
	}
	else
	{
		currentNode->SetRight(newNode);
	}
}

//insert a node into a tree when given a node
void BinaryTree::reInsert(TreeNode* node)
{
	TreeNode* currentNode = m_pRoot;
	if (IsEmpty() == true)
	{
		m_pRoot = node;
		return;
	}
	// Finding empty node
	while (currentNode != nullptr)
	{
		// If the value is less, go left
		if (node->GetData() < currentNode->GetData())
		{
			// If the node has no left child, we have found an empty spot and we break out of the loop
			if (currentNode->HasLeft() == false)
			{
				break;
			}
			// Make the current node the left one
			currentNode = currentNode->GetLeft();
		}
		// If the value is greater, go right
		else if (node->GetData() > currentNode->GetData())
		{
			// If the node has no right child, we have found an empty spot and we break out of the loop
			if (!currentNode->HasRight() == true)
			{
				break;
			}
			// Make the current node the right one
			currentNode = currentNode->GetRight();
		}
		// If the number already exists
		else if (node->GetData() == currentNode->GetData())
		{
			std::cout << "Number already exists in the tree." << std::endl;
			return;
		}
	}
	// Once the empty node has been found, set the value
	if (node->GetData() < currentNode->GetData())
	{
		currentNode->SetLeft(node);
	}
	else
	{
		currentNode->SetRight(node);
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = m_pRoot;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent : nullptr;
}

//Find the node with the specified value.
bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	TreeNode* currentNode = ppOutParent;
	TreeNode* currentParent = nullptr;

	//while current node != null
	while (currentNode != nullptr)
	{
		//if searchValue equals the value in current node
		if (a_nSearchValue == currentNode->GetData())
		{
			ppOutNode = currentNode;
			ppOutParent = currentParent;
			//return the node you are finding and its parent
			return true;
		}

		//if searchValue is less then the value in current node
		else if (a_nSearchValue < currentNode->GetData())
		{
			//set current parent to current node
			currentParent = currentNode;

			//if current has a left node set currentnode to left node
			if (currentNode->HasLeft() == true)
			{
				currentNode = currentNode->GetLeft();
			}
			else
			{
				break; //go back to top of while loop
			}
		}
		//if searchValue is greater then the value in current node
		else if (a_nSearchValue > currentNode->GetData())
		{
			currentParent = currentNode;

			//if current has a left node set currentnode to left node
			if (currentNode->HasRight() == true)
			{
				currentNode = currentNode->GetRight();
			}
			else
			{
				break; //go back to top of while loop
			}
		}
	}
	//couldnt find node return false exit function
	return false;
}


//remove selected node from tree
void BinaryTree::Remove(int a_nValue)
{
	//if list is empty return out of function
	if (IsEmpty())
	{
		return;
	}
	//set current and parent default pos in tree
	currentNode = nullptr;
	currentParent = m_pRoot;
	//create a copy to store 3 nodes into
	TreeNode* tempNode;
	TreeNode* leftChild;
	TreeNode* rightChild;

	//return currentnode to remove and its parent
	FindNode(a_nValue, currentNode, currentParent);
	//sets left temp as currents leftChild
	leftChild = currentNode->GetLeft();
	//sets right temp as currents rightChild
	rightChild = currentNode->GetRight();

	//if current parent is not null
	if (currentParent != nullptr)
	{
		//remove the currentparent attatchments to current node
		if (currentParent->GetLeft() == currentNode)
		{
			currentParent->SetLeft(nullptr);
		}
		else if (currentParent->GetRight() == currentNode)
		{
			currentParent->SetRight(nullptr);
		}
	}
	//remove root node if root is node we are removing
	if (currentNode == m_pRoot)
	{
		m_pRoot = nullptr;
	}
	//remove current node from tree
	currentNode = nullptr;

	// if left child not null resinsert function handles where to place node back into tree
	if (leftChild != nullptr)
	{
		reInsert(leftChild);
	}
	// if right child not null resinsert function handles where to place node back into tree
	if (rightChild != nullptr)
	{
		reInsert(rightChild);
	}

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