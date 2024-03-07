#include <cstddef>
#include <functional>
#include <iterator>
#include <utility>
#include <vector>
//Це клас C++, який представляє матрицю з можливістю зручного доступу до її елементів за допомогою оператора [][].
template <class T>
class matrix
{
	template<class C>
	class proxy_row_vector
	{
		using reference = decltype(std::declval<C>()[0]);
		using const_reference = decltype(std::declval<C const>()[0]);

		public:
			proxy_row_vector(C &_vec ,std::size_t _r_ind,std::size_t cols)
				:vec(_vec),row_index(_r_ind),cols(cols)
			{ }
			const_reference operator[](std::size_t _col_index)const
			{
				return vec[row_index*cols+_col_index];
			}
			reference operator[](std::size_t _col_index)
			{
				return vec[row_index*cols+_col_index];
			}

		private:
			C& vec;
			std::size_t row_index;
			std::size_t cols;	

	};

	using const_proxy = proxy_row_vector<const std::vector<T>>;
        using proxy = proxy_row_vector<std::vector<T>>;
public: 
	matrix() :mtx(),rows(0),cols(0)
	{ }
	matrix(std::size_t rows,std::size_t cols)
		:mtx(rows*cols),rows(rows),cols(cols)
	{ }
	const_proxy operator[](std::size_t _row_index)const
	{
		return const_proxy(mtx,_row_index,cols);
	}
	proxy operator[](std::size_t _row_index)
	{
		return proxy(mtx,_row_index,cols);
	}

private:
	std::vector<T> mtx;
	std::size_t rows;
	std::size_t cols;

};













