#include <vector>

class Solution {

public:

	using Matrix = std::vector<std::vector<int>>;
	using Vector = std::vector<int>;

	Vector spiralOrder(Matrix& matrix) 
	{
		Vector result;

		if (matrix.size() != 0)
		{
			int nNbRows = matrix.size();
			int nNbCols = matrix[0].size();

			result.reserve(nNbCols * nNbCols);

			int nSweeps = 0;

			while (result.size() != nNbRows *nNbCols)
			{
				bool bForwardSweep = nSweeps % 2 == 0;
				int  nQuotient     = nSweeps / 2;

				if (bForwardSweep)
				{
					// Add all remaining elements of starting row.
					Vector & vecAll = *(matrix.begin() + nQuotient);
					for (Vector::const_iterator it = vecAll.begin() + nQuotient; it != vecAll.end() - nQuotient; ++ it)
					{
						result.push_back(*it);
					}

					for (Matrix::const_iterator it = matrix.begin() + nQuotient + 1; it != (matrix.end() - nQuotient);++it)
					{
						result.push_back(*((*it).rbegin() + nQuotient));
					}
	
				}
				else
				{
					Vector & vecAll = *(matrix.rbegin() + nQuotient);

					// Add all remaining elements of starting row.
					for (Vector::const_reverse_iterator it = vecAll.rbegin() + nQuotient + 1; it != vecAll.rend() - nQuotient; ++it)
					{
						result.push_back(*it);
					}

					for (Matrix::const_reverse_iterator it = matrix.rbegin() + nQuotient + 1; it != matrix.rend() - (nQuotient + 1); ++it)
					{
						result.push_back(*((*it).begin() + nQuotient));
					}
				}
				
				++nSweeps;
			}

		}

		return result;
	}
};