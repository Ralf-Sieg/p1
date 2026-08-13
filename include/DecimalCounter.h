#pragma once
#include <vector>

constexpr char zero_decimal_char = '0';
constexpr char one_decimal_char = '1';
constexpr char max_decimal_char = (zero_decimal_char + 9);

// used to count in decimal system
class CDecimalCounter final
{
	std::vector<char> mvec_digits;

public:
	CDecimalCounter(char c)
	{
		mvec_digits.assign(1, c);
	}

	inline CDecimalCounter& operator++ ()
	{
		for (auto& digit : mvec_digits)
		{
			if (digit == max_decimal_char)
			{
				digit = zero_decimal_char;
			}
			else
			{
				digit++;
				return *this;
			}
		}

		mvec_digits.emplace_back(one_decimal_char);

		return *this;
	}

	inline std::string ToString() const
	{
		std::string str_ret;

		if (!mvec_digits.empty())
		{
			auto n = mvec_digits.size() - 1;
			while (true)
			{
				str_ret += mvec_digits[n];
				if (n == 0)
					break;
				if (n % 3 == 0)
					str_ret += '.';
				n--;
			}
		}

		return str_ret;
	}
};