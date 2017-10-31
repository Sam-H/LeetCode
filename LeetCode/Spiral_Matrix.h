#include <vector>
#include <algorithm>
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


			for (int nSweeps = 0; nSweeps < std::min(nNbRows, nNbCols); ++nSweeps)
			{
				bool bForwardSweep = nSweeps % 2 == 0;
				int  nQuotient     = nSweeps / 2;

				if (bForwardSweep)
				{
					// Add all remaining elements of starting row.
					const Vector & vecAll = *(std::next(matrix.begin(), nQuotient));
					for (Vector::const_iterator it = std::next(vecAll.begin(), nQuotient); it != std::prev(vecAll.end(), nQuotient); ++ it)
					{
						result.push_back(*it);
					}

					for (Matrix::const_iterator it = std::next(matrix.begin(), nQuotient + 1); it != std::prev(matrix.end(), nQuotient);++it)
					{
						result.push_back(*(std::next((*it).rbegin(), nQuotient)));
					}
	
				}
				else
				{
					const Vector & vecAll = *(std::next(matrix.rbegin(), nQuotient));
					// Add all remaining elements of starting row.
					for (Vector::const_reverse_iterator it = std::next(vecAll.rbegin(), nQuotient + 1); it != std::prev(vecAll.rend(), nQuotient); ++it)
					{
						result.push_back(*it);
					}

					for (Matrix::const_reverse_iterator it = std::next(matrix.rbegin(), nQuotient + 1); it != std::prev(matrix.rend(),nQuotient + 1); ++it)
					{
						result.push_back(*(std::next((*it).begin(), nQuotient)));
					}
				}
				
			}

		}

		return result;
	}
};