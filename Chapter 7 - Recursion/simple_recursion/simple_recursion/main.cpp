#include <iostream>
#include <chrono>
#include <cassert>

using namespace std::literals::chrono_literals;

constexpr unsigned ITERATIONS = 1000;

// Timer class calculates duration when in scope.
struct timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;

	timer() { start = std::chrono::high_resolution_clock::now(); }

	~timer()
	{
		std::chrono::duration<float> duration = std::chrono::high_resolution_clock::now() - start;
		std::cout << "Timer: " << duration.count()*1000.0f << "ms" << std::endl;
	}
};

// Iterative factorial.
unsigned long long iFactorial(unsigned long long n)
{
	if (n <= 1)
		return 1;

	for (unsigned long long i = n; i > 1; i--)
		n *= (i - 1);

	return n;
}

// Recursive factorial.
unsigned long long rFactorial(unsigned long long n)
{
	if (n <= 1)
		return 1;

	return rFactorial(n - 1) * n;
}

// Return value of esp register.
__inline uint32_t getESP() { __asm { mov eax, esp } }

// Recursive factorial with stack report.
unsigned long long rFactorialX(unsigned long long n, uint32_t& min)
{
	uint32_t s;
	if ((s = getESP()) < min)
		min = s;

	//std::cout << "n: " << n << std::hex << " 0x" << s << std::dec << std::endl;

	if (n <= 1)
		return 1;

	return rFactorialX(n - 1, min) * n;
}

int main()
{
	const unsigned long long n = 20;

	assert(rFactorial(n) == iFactorial(n));

	// Compare time of recursive vs. iterative versions.
	std::cout << "Iterative method ";
	{
		timer time;
		for (unsigned i = 0; i < ITERATIONS; i++)
			iFactorial(n);
	}

	std::cout << "Recursive method ";
	{
		timer time;
		for (unsigned i = 0; i < ITERATIONS; i++)
			rFactorial(n);
	}

	// Estimate stack use.
	uint32_t top = getESP(), bottom = top;
	for (unsigned long long i = 1; i <= n; i++)
	{
		std::cout << i << "! = " << rFactorialX(i, bottom);
		std::cout << ", stack used = " << (top - bottom) << "\n";
	}
}
