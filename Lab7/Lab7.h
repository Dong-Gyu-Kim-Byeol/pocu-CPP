#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <cmath>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;

		const size_t count = std::min(keys.size(), values.size());
		for (size_t i = 0; i < count; ++i)
		{
			const K& key = keys[i];
			const V& value = values[i];

			m.emplace(key, value);
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		v.reserve(m.size());

		for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
		{
			const K& key = it->first;
			v.emplace_back(key);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		v.reserve(m.size());

		for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
		{
			const V& value = it->second;
			v.emplace_back(value);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		rv.reserve(v.size());

		for (typename std::vector<T>::const_reverse_iterator reverseIt = v.rbegin(); reverseIt != v.rend(); ++reverseIt)
		{
			const T& value = *reverseIt;
			rv.emplace_back(value);
		}

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		combined.reserve(v1.size() + v2.size());

		std::unordered_set<T> set;
		set.reserve(2 * (v1.size() + v2.size()));

		for (typename std::vector<T>::const_iterator it = v1.begin(); it != v1.end(); ++it)
		{
			const T& value = *it;
			std::pair<std::unordered_set<T>::const_iterator, bool> insert = set.emplace(value);
			if (insert.second)
			{
				combined.emplace_back(value);
			}
		}

		for (typename std::vector<T>::const_iterator it = v2.begin(); it != v2.end(); ++it)
		{
			const T& value = *it;
			std::pair<std::unordered_set<T>::const_iterator, bool> insert = set.emplace(value);
			if (insert.second)
			{
				combined.emplace_back(value);
			}
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		for (typename std::map<K, V>::const_iterator it = m1.begin(); it != m1.end(); ++it)
		{
			const K& key = it->first;
			const V& value = it->second;

			combined.emplace(key, value);
		}

		for (typename std::map<K, V>::const_iterator it = m2.begin(); it != m2.end(); ++it)
		{
			const K& key = it->first;
			const V& value = it->second;

			combined.emplace(key, value);
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); )
		{
			os << *it;

			++it;
			if (it != v.end())
			{
				os << ", ";
			}
		}

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); )
		{
			const K& key = it->first;
			const V& value = it->second;

			os << "{ " << key << ", " << value << " }";

			++it;
			if (it != m.end())
			{
				os << '\n';
			}
		}

		return os;
	}
}