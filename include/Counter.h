#pragma once
#include <vector>

constexpr unsigned char zero_char = 0;
constexpr unsigned char one_char = 1;
constexpr unsigned char max_char = 255; // a base-256 system is used to save storage space

// used to count in base-256 system
class CBase256Counter
{
	std::vector<unsigned char> m_digit; // several chars may be necessary to define one digit

public:
	CBase256Counter(const CBase256Counter& other)
	{
		this->m_digit = other.m_digit;
	}

	CBase256Counter(size_t size)
	{
		m_digit.assign(size, zero_char);
	}

	constexpr const std::vector<unsigned char>& GetCounted() const noexcept {return m_digit;}

	inline bool operator== (const std::vector<unsigned char>& other_count) const
	{
		if (other_count.size() == m_digit.size())
		{
			for (size_t n = 0; n < m_digit.size(); n++)
			{
				if (other_count[n] != m_digit[n])
				{
					return false;
				}
			}

			return true;
		}

		return false;
	}

	inline CBase256Counter& operator++ ()
	{
		for (auto& char_digit : m_digit)
		{
			if (char_digit == max_char)
			{
				char_digit = zero_char;
			}
			else
			{
				char_digit++;
				return *this;
			}
		}

		m_digit.emplace_back(one_char);

		return *this;
	}

	inline void SetZero()
	{
		m_digit.assign(m_digit.size(), zero_char);
	}

	inline bool IsZero() const
	{
		for (const auto char_digit : m_digit)
		{
			if (char_digit != zero_char)
			{
				return false;
			}
		}

		// all chars zero
		return true;
	}
};

// used to count in prime number system
class CPrimeDigit final : public CBase256Counter
{
	// The position in prime number system based on the prime number p consists of the digits ‘0’ through ‘p-1’.
	const std::vector<unsigned char> m_count_max; // p-1

public:

	explicit CPrimeDigit(const std::vector<unsigned char>& other_count)
		: CBase256Counter(other_count.size())
		, m_count_max(other_count)
	{ 
	}

	inline CPrimeDigit& operator++ ()
	{
		if (*this == m_count_max) // CCounter::operator==
		{ 
			SetZero(); // If the set of digits is exhausted when incrementing a place, the sequence starts again with the digit ‘0’
		}
		else
		{
			CBase256Counter::operator++();
		}

		return *this;
	}
};