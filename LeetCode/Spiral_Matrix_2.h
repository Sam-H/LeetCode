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
					Vector & vecAll = *(result.begin() + nQuotient);
					for (Vector::iterator it = vecAll.begin() + nQuotient; it != vecAll.end() - nQuotient; ++it)
					{
						*it = nCounter;
						++nCounter;
					}

					for (Matrix::iterator it = result.begin() + nQuotient + 1; it != (result.end() - nQuotient); ++it)
					{
						*((*it).rbegin() + nQuotient) = nCounter;
						++nCounter;
					}

				}
				else
				{
					Vector & vecAll = *(result.rbegin() + nQuotient);

					for (Vector::reverse_iterator it = vecAll.rbegin() + nQuotient + 1; it != vecAll.rend() - nQuotient; ++it)
					{
						*it = nCounter;
						++nCounter;
					}

					for (Matrix::reverse_iterator it = result.rbegin() + nQuotient + 1; it != result.rend() - (nQuotient + 1); ++it)
					{
						*((*it).begin() + nQuotient) = nCounter;
						++nCounter;
					}
				}

				++nSweeps;
			}

		}

		return result;
	}
};