#ifndef ft_mat_H
#define ft_mat_H
#include "ft_vec.hpp"
#include <iostream>
#include <stdexcept>
#include "iterators.hpp"

namespace ft
{
	template <typename T>
    class Matrix {

	public:
        typedef vector<vector<T> > Container;
		typedef T value_type;
        typedef typename Container::iterator iterator;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

	protected:
		Container mat;
        size_type m;
        size_type n;
    
    public:

    Matrix(size_type n, size_type m, const value_type &val = value_type()) : mat(n, vector<T>(m, val)), m(m), n(n) {}
    ~Matrix() {}
    Matrix(const Matrix &other) : mat(other.mat), m(other.m), n(other.n) {}
    Matrix &operator=(const Matrix &other) {
        mat = other.mat;
        m = other.m;
        n = other.n;
        return *this;
    }

    reference at (size_type  i, size_type j) {
        if ((n <= i) || (m <= j))
            throw std::out_of_range("Matrix");
        return mat[i][j];
    }

    reference at (size_type  i, size_type j) const {
        if ((n <= i) || (m <= j))
            throw std::out_of_range("Matrix");
        return mat[i][j];
    }

    reference operator[] (size_type  i) {
        if (i >= n)
            throw std::out_of_range("Matrix");
        return mat[i];
    }

    const_reference operator[] (size_type i) const  {
        if (i >= n)
            throw std::out_of_range("Matrix");
        return mat[i];
    }


    iterator begin() {return (mat.begin());}
    iterator end() {return (mat.end());}


    Matrix &operator+=(const Matrix &other) {
        if ((n != other.n) || (m != other.m))
            throw std::invalid_argument("Matrix");
        for (size_type i = 0; i < n; i++)
            for (size_type j = 0; j < m; j++)
                mat[i][j] += other.mat[i][j];
        return *this;
    }

    Matrix &operator-=(const Matrix &other) {
        if ((n != other.n) || (m != other.m))
            throw std::invalid_argument("Matrix");
        for (size_type i = 0; i < n; i++)
            for (size_type j = 0; j < m; j++)
                mat[i][j] -= other.mat[i][j];
        return *this;
    }

    Matrix &operator*=(const Matrix &other) {
        if (m != other.n)
            throw std::invalid_argument("Matrix");
        Matrix tmp(n, other.m);
        for (size_type i = 0; i < n; i++)
            for (size_type j = 0; j < other.m; j++)
                for (size_type k = 0; k < m; k++)
                    tmp.mat[i][j] += mat[i][k] * other.mat[k][j];
        mat = tmp.mat;
        m = tmp.m;
        n = tmp.n;
        return *this;
    }

    Matrix &operator*=(const value_type &val) {
        for (size_type i = 0; i < n; i++)
            for (size_type j = 0; j < m; j++)
                mat[i][j] *= val;
        return *this;
    }

    Matrix &operator/=(const value_type &val) {
        if (val == 0)
            throw std::invalid_argument("Matrix");
        for (size_type i = 0; i < n; i++)
            for (size_type j = 0; j < m; j++)
                mat[i][j] /= val;
        return *this;
    }

    Matrix &operator%=(const value_type &val) {
        if (val == 0)
            throw std::invalid_argument("Matrix");
        for (size_type i = 0; i < n; i++)
            for (size_type j = 0; j < m; j++)
                mat[i][j] %= val;
        return *this;
    }


    friend std::ostream &operator<<(std::ostream &os, Matrix &mat) {
        for (size_type i = 0; i < mat.n; i++) {
            os << "| ";
            for (size_type j = 0; j < mat.m - 1; j++) {
                os << mat[i][j] << " ,";
            }
            if (mat.m > 0) os << mat[i][mat.m - 1];
            os << "|" << std::endl;
        }
        return os;
    }

    //Non-member functions
    friend bool operator==(const Matrix& lhs, const Matrix& rhs) {
            return (lhs.mat == rhs.mat);
        }

    friend bool operator!=( const Matrix& lhs,
                    const Matrix& rhs ) {
                        return !(lhs.mat == rhs.mat);
              }
    };


    //--------------------------------------Iterators--------------------------------------------//

    template <typename T>
        class matrix_iterator : public iterator<bidirectional_iterator_tag, T>
        {
        public:
          typedef typename iterator<bidirectional_iterator_tag, T>::iterator_category     iterator_category;
          typedef typename iterator<bidirectional_iterator_tag, T>::value_type            value_type;
          typedef typename iterator<bidirectional_iterator_tag, T>::difference_type       difference_type;
          typedef typename vector<vector<T> >::pointer                                            pointer;
          typedef typename vector<vector<T> >::reference                                          reference;
          typedef typename vector<vector<T> >::size_type                                          size_type;

        private :
          vector< vector<T> >          *mat;
          unsigned int                  m;
          unsigned int                  n;

        public :
          matrix_iterator(Matrix<T> &mat, bool mode = false): mat(&mat.mat),m(m),n(n) {;}


          matrix_iterator(size_type m, size_type n, Matrix<T>  &mat, bool mode = false):mat(&mat.mat),m(m),n(n) {
            ;}
          matrix_iterator(const matrix_iterator &cpy):mat(0) {mat = cpy.mat; m = cpy.m; n = cpy.n; }
          matrix_iterator &operator=(const matrix_iterator &cpy) {mat = cpy.mat; m = cpy.m; n = cpy.n; return *this;}

          reference operator  *() {return &mat[m][n];}
          pointer   operator ->()  {return &mat[m][n];}
         
          matrix_iterator  operator ++() {
            if (n < (*mat)[m].size() - 1)
                ++n;
            else {
                n = 0;
                if (m < (*mat).size() - 1)
                    ++m;
            }
            return (*this);
          }

          matrix_iterator operator --() {
            if (n > 0)
                --n;
            else {
                if (m > 0) {
                    --m;
                    n = (*mat)[m].size() - 1;
                }
            }
            return (*this);
          }

          matrix_iterator operator ++(int) {
            matrix_iterator out(*this);
            ++(*this);
            return out;
          }
          matrix_iterator operator --(int) {
            matrix_iterator out(*this);
            --(*this);
            return out;
          }
          friend bool operator==(const matrix_iterator &a, const matrix_iterator &b) {return *(a.mat) == *(b.mat) &&  a.n * *(a.mat).m + a.n == a.b * *(b.mat).m + b.n;}
          friend bool operator!=(const matrix_iterator &a, const matrix_iterator &b) {return *(a.mat) == *(b.mat) &&  a.n * *(a.mat).m + a.n != a.b * *(b.mat).m + b.n;}
          friend bool operator<(const matrix_iterator  &a, const matrix_iterator &b) {return *(a.mat) == *(b.mat) &&  a.n * *(a.mat).m + a.n <  a.b * *(b.mat).m + b.n;}
          friend bool operator<=(const matrix_iterator &a, const matrix_iterator &b) {return *(a.mat) ==  *(b.mat) &&  a.n * *(a.mat).m + a.n <= a.b * *(b.mat).m + b.n;}
          friend bool operator>(const matrix_iterator  &a, const matrix_iterator &b) {return *(a.mat) == *(b.mat) &&  a.n * *(a.mat).m + a.n >  a.b * *(b.mat).m + b.n;}
          friend bool operator>=(const matrix_iterator &a, const matrix_iterator &b) {return *(a.mat) ==  *(b.mat) &&  a.n * *(a.mat).m + a.n >= a.b * *(b.mat).m + b.n;}
        };

}
#endif