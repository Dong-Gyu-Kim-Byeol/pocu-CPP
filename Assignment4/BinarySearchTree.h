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
		std::shared_ptr<TreeNode<T>> getMaxNode(std::shared_ptr<TreeNode<T>> root);
		std::shared_ptr<TreeNode<T>> getMinNode(std::shared_ptr<TreeNode<T>> root);
		void deleteChild(std::shared_ptr<TreeNode<T>>& node, std::shared_ptr<TreeNode<T>>& child);

		static void traverseInOrder(std::vector<T>& out, const std::shared_ptr<TreeNode<T>> startNode);

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
		while (true)
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
		std::shared_ptr<TreeNode<T>> root = mRoot;
		while (root != nullptr)
		{
			if (*(root->Data) == data)
			{
				if (root->Left == nullptr && root->Right == nullptr)
				{
					std::shared_ptr<TreeNode<T>> parent = root->Parent.lock();
					if (parent == nullptr)
					{
						assert(root == mRoot);
						mRoot = nullptr;
					}
					else
					{
						deleteChild(parent, root);
					}
				}
				else if (root->Right == nullptr)
				{
					assert(root->Left != nullptr);

					std::shared_ptr<TreeNode<T>> maxNode = getMaxNode(root->Left);
					root->Data = std::move(maxNode->Data);

					std::shared_ptr<TreeNode<T>> maxNodeParent = maxNode->Parent.lock();
					deleteChild(maxNodeParent, maxNode);
				}
				else
				{
					assert(root->Right != nullptr);

					std::shared_ptr<TreeNode<T>> minNode = getMinNode(root->Right);
					root->Data = std::move(minNode->Data);

					std::shared_ptr<TreeNode<T>> minNodeParent = minNode->Parent.lock();
					deleteChild(minNodeParent, minNode);
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

		traverseInOrder(v, startNode);
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
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::getMinNode(std::shared_ptr<TreeNode<T>> root)
	{
		std::shared_ptr<TreeNode<T>> min = root;
		while (root != nullptr)
		{
			min = root;
			root = root->Left;
		}

		return min;
	}

	template<typename T>
	void BinarySearchTree<T>::deleteChild(std::shared_ptr<TreeNode<T>>& node, std::shared_ptr<TreeNode<T>>& child)
	{
		assert(child->Left == nullptr);
		assert(child->Right == nullptr);

		if (node->Left == child)
		{
			node->Left = nullptr;
		}
		else
		{
			assert(node->Right == child);

			node->Right = nullptr;
		}

		child->Parent.reset();
	}

	template<typename T>
	void BinarySearchTree<T>::traverseInOrder(std::vector<T>& out, const std::shared_ptr<TreeNode<T>> startNode)
	{
		if (startNode == nullptr)
		{
			return;
		}

		traverseInOrder(out, startNode->Left);
		out.emplace_back(*startNode->Data);
		traverseInOrder(out, startNode->Right);
	}
}