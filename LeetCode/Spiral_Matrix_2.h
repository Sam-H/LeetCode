#include <vector>

class Solution {

public:

	using Matrix = std::vector<std::vector<int>>;
	using Vector = std::vector<int>;

	Matrix generateMatrix(int n)
	{

		Matrix result;

		if (n > 0)
		{
			result = Matrix(n, Vector(n, 0));

			int nSweeps = 0;
			int nCounter = 1;

			while (nCounter != n * n + 1)
			{
				bool bForwardSweep = nSweeps % 2 == 0;
				int  nQuotient = nSweeps / 2;

				if (bForwardSweep)
				{
					Vector & vecAll = *std::next(result.begin(), nQuotient);
					for (Vector::iterator it = std::next(vecAll.begin(),nQuotient); it != std::prev(vecAll.end(), nQuotient); ++it)
					{
						*it = nCounter;
						++nCounter;
					}

					for (Matrix::iterator it = std::next(result.begin(), nQuotient + 1); it != std::prev(result.end(), nQuotient); ++it)
					{
						*(std::next((*it).rbegin(), nQuotient)) = nCounter;
						++nCounter;
					}

				}
				else
				{
					Vector & vecAll = *std::next(result.rbegin(), nQuotient);

					for (Vector::reverse_iterator it = std::next(vecAll.rbegin(), nQuotient + 1); it != std::prev(vecAll.rend(), nQuotient); ++it)
					{
						*it = nCounter;
						++nCounter;
					}

					for (Matrix::reverse_iterator it = std::next(result.rbegin(), nQuotient + 1); it != std::prev(result.rend() ,nQuotient + 1); ++it)
					{
						*(std::next((*it).begin(), nQuotient)) = nCounter;
						++nCounter;
					}
				}

				++nSweeps;
			}

		}

		return result;
	}
};