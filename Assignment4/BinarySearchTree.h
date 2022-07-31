#pragma once

#include <memory>
#include <vector>
#include <cassert>

#include "TreeNode.h"

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		BinarySearchTree() = default;

		BinarySearchTree(const BinarySearchTree& other) = default;
		void operator=(const BinarySearchTree& rhs) = delete;

		BinarySearchTree(BinarySearchTree&& other) = default;
		void operator=(BinarySearchTree&& rhs) = delete;

		~BinarySearchTree() = default;

		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		static bool deleteRecursive(std::shared_ptr<TreeNode<T>>& startNode, const T& data);
		static std::shared_ptr<TreeNode<T>> getMaxNode(std::shared_ptr<TreeNode<T>> root);

		static void traverseInOrderRecursive(std::vector<T>& out, const std::shared_ptr<TreeNode<T>> startNode);

		std::shared_ptr<TreeNode<T>> mRoot;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<TreeNode<T>>(std::move(data));
			return;
		}

		std::shared_ptr<TreeNode<T>> root = mRoot;
		while (root != nullptr)
		{
			if (*(root->Data) < *data)
			{
				if (root->Right == nullptr)
				{
					root->Right = std::make_shared<TreeNode<T>>(root, std::move(data));
					return;
				}

				root = root->Right;
				continue;
			}
			else
			{
				assert(*data <= *(root->Data));

				if (root->Left == nullptr)
				{
					root->Left = std::make_shared<TreeNode<T>>(root, std::move(data));
					return;
				}

				root = root->Left;
				continue;
			}
		}

		assert(false);
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> root = mRoot;
		while (root != nullptr)
		{
			if (*(root->Data) == data)
			{
				return true;
			}
			else if (*(root->Data) < data)
			{
				root = root->Right;
				continue;
			}
			else
			{
				assert(data < *(root->Data));

				root = root->Left;
				continue;
			}
		}

		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return deleteRecursive(mRoot, data);
	}

	template<typename T>
	bool BinarySearchTree<T>::deleteRecursive(std::shared_ptr<TreeNode<T>>& startNode, const T& data)
	{
		std::shared_ptr<TreeNode<T>> root = startNode;
		while (root != nullptr)
		{
			if (*(root->Data) == data)
			{
				std::shared_ptr<TreeNode<T>> parent = root->Parent.lock();
				if (parent == nullptr)
				{
					assert(root == startNode);

					if (startNode->Right == nullptr && startNode->Left == nullptr)
					{
						startNode = nullptr;
					}
					else if (startNode->Right == nullptr)
					{
						startNode->Left->Parent.reset();
						startNode = startNode->Left;
					}
					else if (startNode->Left == nullptr)
					{
						startNode->Right->Parent.reset();
						startNode = startNode->Right;
					}
					else
					{
						std::shared_ptr<TreeNode<T>> maxNode = getMaxNode(startNode->Left);
						startNode->Data.swap(maxNode->Data);

						deleteRecursive(maxNode, data);
					}

					return true;
				}

				if (root->Right == nullptr && root->Left == nullptr)
				{
					if (parent->Left == root)
					{
						parent->Left = nullptr;
					}
					else
					{
						parent->Right = nullptr;
					}
				}
				else if (root->Right == nullptr)
				{
					if (parent->Left == root)
					{
						parent->Left = root->Left;
					}
					else
					{
						parent->Right = root->Left;
					}

					root->Left->Parent = parent;
				}
				else if (root->Left == nullptr)
				{
					if (parent->Left == root)
					{
						parent->Left = root->Right;
					}
					else
					{
						parent->Right = root->Right;
					}

					root->Right->Parent = parent;
				}
				else
				{
					std::shared_ptr<TreeNode<T>> maxNode = getMaxNode(root->Left);
					root->Data.swap(maxNode->Data);

					deleteRecursive(maxNode, data);
				}

				return true;
			}
			else if (*(root->Data) < data)
			{
				root = root->Right;
				continue;
			}
			else
			{
				assert(data < *(root->Data));

				root = root->Left;
				continue;
			}
		}

		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		v.reserve(32);

		traverseInOrderRecursive(v, startNode);
		return v;
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::getMaxNode(std::shared_ptr<TreeNode<T>> root)
	{
		std::shared_ptr<TreeNode<T>> max = root;
		while (root != nullptr)
		{
			max = root;
			root = root->Right;
		}

		return max;
	}

	template<typename T>
	void BinarySearchTree<T>::traverseInOrderRecursive(std::vector<T>& out, const std::shared_ptr<TreeNode<T>> startNode)
	{
		if (startNode == nullptr)
		{
			return;
		}

		if (startNode->Left != nullptr)
		{
			traverseInOrderRecursive(out, startNode->Left);
		}

		out.emplace_back(*startNode->Data);

		if (startNode->Right != nullptr)
		{
			traverseInOrderRecursive(out, startNode->Right);
		}
	}
}