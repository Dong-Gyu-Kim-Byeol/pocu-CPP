#pragma once

#include <memory>

namespace assignment4
{
	template<typename T>
	class TreeNode final
	{
	public:
		TreeNode(std::unique_ptr<T> data);
		TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data);

		TreeNode(const TreeNode& other) = delete;
		void operator=(const TreeNode& rhs) = delete;

		TreeNode(TreeNode&& other) = default;
		void operator=(TreeNode&& rhs) = delete;

		~TreeNode() = default;

		std::unique_ptr<T> Data;
		std::shared_ptr<TreeNode<T>> Left;
		std::shared_ptr<TreeNode<T>> Right;
		std::weak_ptr<TreeNode<T>> Parent;
	};

	template<typename T>
	TreeNode<T>::TreeNode(std::unique_ptr<T> data) :
		Data(std::move(data)),
		Left(),
		Right(),
		Parent()
	{
	}

	template<typename T>
	TreeNode<T>::TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data) :
		Data(std::move(data)),
		Left(),
		Right(),
		Parent(parent)
	{
	}
}