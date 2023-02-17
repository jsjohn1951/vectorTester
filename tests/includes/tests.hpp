/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:30:32 by wismith           #+#    #+#             */
/*   Updated: 2023/02/12 19:09:21 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector/vector.hpp"
#include "../../includes/utils/utility.hpp"
#include "../../includes/utils/algorithm.hpp"
#include "../../includes/map/map.hpp"
#include <vector>
#include <map>
#include <cstdlib>
#include <unistd.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void	vectorTests(void);
void	vectorPushBack(void);
void	vectorPopBack(void);
void	vectorIErase(void);
void	vectorPErase(void);
void	vectorClear(void);
void	vectorNConstructor(void);
void	vectorIConstructor(void);
void	vectorValInsert(void);
void	vectorNumValInsert(void);
void	vectorIterInsert(void);
void	vectorResize(void);
void	vectorReserve(void);
void	vectorSwap(void);

namespace ft
{
	class UnLikeSize : public std::exception
	{
		const char* what() const throw()
		{
			return ("vectorCompare: Unlike Sizes");
		}
	};

	class UnLikeCapacity : public std::exception
	{
		const char* what() const throw()
		{
			return ("vectorCompare: Unlike Capacities");
		}
	};

	class UnLikeElem : public std::exception
	{
		const char* what() const throw()
		{
			return ("vectorCompare: Unlike Elements");
		}
	};

	template <class T>
	class vectorCompare
	{
		public :
			void	vectorSizeCmp(std::vector<T> &stdvec, ft::vector<T> &ftvec)
			{
				if (stdvec.size() != ftvec.size())
				{
					std::cerr << "\n\n\t\tft:vec Size:\t\t[" << KRED << ftvec.size() << KNRM << "]";
					std::cerr << "\n\t\tstd:vec Size:\t\t[" << KRED << stdvec.size() << KNRM << "]\n";
					throw ft::UnLikeSize();
				}
			}

			void	vectorCapacityCmp(std::vector<T> &stdvec, ft::vector<T> &ftvec)
			{
				if (stdvec.capacity() != ftvec.capacity())
				{
					std::cerr << "\n\n\t\tft:vec Capacity:\t\t[" << KRED << ftvec.capacity() << KNRM << "]";
					std::cerr << "\n\t\tstd:vec Capacity:\t\t[" << KRED << stdvec.capacity() << KNRM << "]\n";
					throw ft::UnLikeCapacity();
				}
			}

			void	vectorElementsCmp(std::vector<T> &stdvec, ft::vector<T> &ftvec)
			{
				typename std::vector<T>::size_type i;
				for (i = 0; i < stdvec.size() && i < ftvec.size(); i++)
					if (stdvec[i] != ftvec[i])
						throw ft::UnLikeElem();
				if (i != stdvec.size() || i != ftvec.size())
					throw ft::UnLikeSize();
			}
	};
};
