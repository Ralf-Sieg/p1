// P1.cpp : Incremental counting method for generating prime numbers
//

#include <iostream>
//#include <chrono>
#include "DecimalCounter.h"
#include "Counter.h"

int main()
{
    //std::chrono::steady_clock::duration max_duration = std::chrono::minutes(5);
    //const auto time_start = std::chrono::steady_clock::now();
    
    std::vector<CPrimeDigit> vec_prime_digits;

    CBase256Counter counter(1); // counts in base-256 system, initialized with '0'
    // To display a number in prime number system in readable format in decimal system, two increments are necessary at the same time:
    // One in the prime number system and the other in decimal system.
    CDecimalCounter decimal_counter('2'); // counts in decimal system

    ++counter; // 2 (stored as '1')
    vec_prime_digits.emplace_back(counter.GetCounted()); // add a new place with the digit ‘0’ for prime number 2

    while (true) // endlessly generating prime numbers
    {
        bool b_is_prime = true;

        // Unlike the place-value system, when incrementing a number in this system, always all places are incremented by 1
        for (auto& digit : vec_prime_digits)
        {
            ++digit;
            if (b_is_prime && digit.IsZero()) // if one digit is zero, it is not a prime number
            {
                b_is_prime = false;
            }
        }
        
        // iterate both counters
        ++counter;
        ++decimal_counter;

        if (b_is_prime)
        {
            vec_prime_digits.emplace_back(counter.GetCounted()); // add a new place with the digit ‘0’ for the given prime number
            std::cout << decimal_counter.ToString() << "\n"; // Output the number readable format in decimal system

            //const auto time_measure = std::chrono::steady_clock::now();
            //if (const auto minutes = std::chrono::duration_cast<std::chrono::minutes>(time_measure - time_start); minutes >= max_duration)
            //{
            //    break;
            //}
        }
    }
}
