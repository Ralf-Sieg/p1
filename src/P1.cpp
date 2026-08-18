// P1.cpp : Incremental Residue-Class Method for Generating Prime Numbers
//

#include <iostream>
#include "DecimalCounter.h"
#include "Counter.h"

int main()
{
    std::vector<CPrimeDigit> vec_prime_digits;

    CBase256Counter counter(1); // counts in base-256 system, initialized with '0'
    // To display a number in prime number system in readable format in decimal system, two increments are necessary at the same time:
    // One in the prime number system and the other in decimal system.
    CDecimalCounter decimal_counter('2'); // counts in decimal system

    ++counter; // 2 (stored as '1')
    vec_prime_digits.emplace_back(counter.GetCounted()); // add a new position with the digit ‘0’ for prime number 2

    while (true) // endlessly generating prime numbers
    {
        bool b_is_prime = true;

        // All positions of the prime number system are incremented by 1
        for (auto& digit : vec_prime_digits)
        {
            ++digit;
            if (b_is_prime && digit.IsZero()) // If, after incrementing, at least one position has the value '0', then the number is not prime
            {
                b_is_prime = false;
            }
        }
        
        // iterate both counters
        ++counter;
        ++decimal_counter;

        if (b_is_prime)
        {
            vec_prime_digits.emplace_back(counter.GetCounted()); // For each newly discovered prime, a new position with digit '0' is added
            std::cout << decimal_counter.ToString() << "\n"; // Output the number readable format in decimal system
        }
    }
}
