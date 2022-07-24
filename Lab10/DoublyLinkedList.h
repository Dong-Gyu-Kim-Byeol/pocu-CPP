#pragma once

#include <memory>
#include <cassert>

#include "Node.h"

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();

		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		std::shared_ptr<Node<T>> mHead;
		unsigned int mLength;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList() :
		mHead(nullptr),
		mLength(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		Insert(std::move(data), mLength);
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (mLength == 0)
		{
			std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));

			mHead = newNode;
			++mLength;
			return;
		}

		if (0 == index)
		{
			std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));
			newNode->Next = mHead;
			mHead->Previous = newNode;

			mHead = newNode;
			++mLength;
			return;
		}

		std::shared_ptr<Node<T>> node = mHead;
		if (mLength < index)
		{
			index = mLength;
		}

		while (node != nullptr)
		{
			if (1 == index)
			{
				std::shared_ptr<Node<T>> preNode = node;
				std::shared_ptr<Node<T>> nextNode = node->Next;
				std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));

				preNode->Next = newNode;
				newNode->Previous = preNode;

				if (nextNode != nullptr)
				{
					newNode->Next = nextNode;
					nextNode->Previous = newNode;
				}

				++mLength;
				break;
			}

			--index;
			node = node->Next;
		}
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> node = mHead;
		while (node != nullptr)
		{
			if (*node->Data == data)
			{
				std::shared_ptr<Node<T>> preNode = node->Previous.lock();
				std::shared_ptr<Node<T>> nextNode = node->Next;

				if (preNode != nullptr)
				{
					preNode->Next = nextNode;
				}
				if (nextNode != nullptr)
				{
					nextNode->Previous = preNode;
				}
				if (mHead == node)
				{
					mHead = nextNode;
				}

				--mLength;
				return true;
			}

			node = node->Next;
		}

		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> node = mHead;
		while (node != nullptr)
		{
			if (*node->Data == data)
			{
				return true;
			}

			node = node->Next;
		}

		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (mLength <= index)
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> node = mHead;
		while (node != nullptr)
		{
			if (0 == index)
			{
				break;
			}

			--index;
			node = node->Next;
		}

		return node;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		/*unsigned int len = 0;
		std::shared_ptr<Node<T>> node = mHead;
		while (node != nullptr)
		{
			++len;
			node = node->Next;
		}

		assert(len == mLength);*/

		return mLength;
	}
}