/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:32:25 by wismith           #+#    #+#             */
/*   Updated: 2023/02/09 16:55:53 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/tests.hpp"

/*
!	@brief: Main test function for vector
!
!	note: tests different aspects and implementation for the
!		fortytwo vector, and compares to the origin standard vector
*/
void	vectorTests(void)
{
	std::cout << std::endl;
	std::cout << KMAG << "FT Vector Tests:" << KNRM << std::endl;
	std::cout << std::endl;
	{
		vectorIConstructor();
		vectorNConstructor();
		vectorPushBack();
		vectorPopBack();
		vectorIErase();
		vectorPErase();
		vectorClear();
		vectorValInsert();
		vectorNumValInsert();
		vectorIterInsert();
		vectorResize();
		vectorReserve();
		vectorSwap();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << KMAG << " ------------- " << KNRM << std::endl;
	std::cout << std::endl;
}

/*
*	@brief: Tests the (Iterator constructor)
?
?	note: Compares constructors from the std vector and fortytwo vector
?		iterators
*/
void	vectorIConstructor(void)
{
	std::vector<int> stdvec;
	ft::vector<int>	ftvec;
	std::cout << KCYN << "\tft::vector:\t  IConstructor:" << KNRM;
	for (int i = 0; i < 100; i++)
	{
		stdvec.push_back(i);
		ftvec.push_back(i);
	}
	std::vector<int> stdvecTest(stdvec.begin(), stdvec.end());
	ft::vector<int>	ftvecTest(ftvec.begin(), ftvec.end());
	ft::vectorCompare<int>	cmp;
	try
	{
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the (Number / Value constructor)
?
?	note: Compares constructors from the std vector and fortytwo vector
?		with the same arguments
*/
void	vectorNConstructor(void)
{
	std::vector<int> stdvec(5, 10);
	ft::vector<int>	ftvec(5, 10);
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\t  NConstructor:" << KNRM;
	try
	{
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector Push_back
?
?	note: Compares the push_back() functions of both std vector
?		and fortytwo vector. Uses a for loop to push to both, comparing
?			size and capacity at each iteration. Afterwhich
?				we compare the elements inside each.
*/
void	vectorPushBack(void)
{
	std::vector<int> stdvec;
	ft::vector<int>	ftvec;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\t     push_back:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			stdvec.push_back(i);
			ftvec.push_back(i);
			cmp.vectorSizeCmp(stdvec, ftvec);
			cmp.vectorCapacityCmp(stdvec, ftvec);
			cmp.vectorElementsCmp(stdvec, ftvec);
		}
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector Pop_back
?
?	note: Compares the pop_back() functions of both std vector
?		and fortytwo vector. Uses a for loop to pop both, comparing
?			size and capacity at each iteration. Afterwhich
?				we compare the elements inside each.
*/
void	vectorPopBack(void)
{
	std::vector<int> stdvec;
	ft::vector<int>	ftvec;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\t      pop_back:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			stdvec.push_back(i);
			ftvec.push_back(i);
		}
		for(int i = 0; i < 30; i++)
		{
			stdvec.pop_back();
			ftvec.pop_back();
			cmp.vectorSizeCmp(stdvec, ftvec);
			cmp.vectorCapacityCmp(stdvec, ftvec);
			cmp.vectorElementsCmp(stdvec, ftvec);
		}
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector iterator erase
?
?	note: Compares the erase() functions of both std vector
?		and fortytwo vector.
*/
void	vectorIErase(void)
{
	std::vector<int> stdvec;
	ft::vector<int>	ftvec;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\tIterator erase:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			stdvec.push_back(i);
			ftvec.push_back(i);
		}
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.erase(stdvec.begin() + 1, stdvec.end() - 5);
		ftvec.erase(ftvec.begin() + 1, ftvec.end() - 5);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector position erase
?
?	note: Compares the erase() functions of both std vector
?		and fortytwo vector.
*/
void	vectorPErase(void)
{
	std::vector<int> stdvec;
	ft::vector<int>	ftvec;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\tPosition erase:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			stdvec.push_back(i);
			ftvec.push_back(i);
		}
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.erase(stdvec.begin() + 9);
		ftvec.erase(ftvec.begin() + 9);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector position clear
?
?	note: Compares the clear() functions of both std vector
?		and fortytwo vector.
*/
void	vectorClear(void)
{
	std::vector<int> stdvec;
	ft::vector<int>	ftvec;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\t         Clear:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			stdvec.push_back(i);
			ftvec.push_back(i);
		}
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.clear();
		ftvec.clear();
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector val insert
?
?	note: Compares the clear() functions of both std vector
?		and fortytwo vector.
*/
void	vectorValInsert(void)
{
	std::vector<int> stdvec;
	ft::vector<int>	ftvec;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\t        Insert:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			stdvec.push_back(i);
			ftvec.push_back(i);
		}
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.insert(stdvec.begin() + 6, 4);
		ftvec.insert(ftvec.begin() + 6, 4);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.insert(stdvec.begin() + 12, -2);
		ftvec.insert(ftvec.begin() + 12, -2);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector Num val insert
?
?	note: Compares the clear() functions of both std vector
?		and fortytwo vector.
*/
void	vectorNumValInsert(void)
{
	std::vector<int> stdvec;
	ft::vector<int>	ftvec;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\tNum Val Insert:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			stdvec.push_back(i);
			ftvec.push_back(i);
		}
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.insert(stdvec.begin() + 6, 4, -20);
		ftvec.insert(ftvec.begin() + 6, 4, -20);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.insert(stdvec.begin() + 12, 2, 42);
		ftvec.insert(ftvec.begin() + 12, 2, 42);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector Num val insert
?
?	note: Compares the clear() functions of both std vector
?		and fortytwo vector.
*/
void	vectorIterInsert(void)
{
	int	ran = 0;
	std::vector<int> stdvec;
	std::vector<int> stdtest;
	ft::vector<int>	ftvec;
	ft::vector<int> fttest;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\t   Iter Insert:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			ran = rand() % 10;
			stdvec.push_back(ran);
			ftvec.push_back(ran);
		}
		for(int i = 0; i < 15; i++)
		{
			ran = rand() % 10;
			stdtest.push_back(ran);
			fttest.push_back(ran);
		}
		stdtest.insert(stdtest.begin(), stdvec.begin(), stdvec.end());
		fttest.insert(fttest.begin(), ftvec.begin(), ftvec.end());
		cmp.vectorSizeCmp(stdtest, fttest);
		cmp.vectorCapacityCmp(stdtest, fttest);
		cmp.vectorElementsCmp(stdtest, fttest);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector Num val insert
?
?	note: Compares the clear() functions of both std vector
?		and fortytwo vector.
*/
void	vectorResize(void)
{
	int	ran = 0;
	std::vector<int> stdvec;
	ft::vector<int>	ftvec;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\t        Resize:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			ran = rand() % 10;
			stdvec.push_back(ran);
			ftvec.push_back(ran);
		}
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		stdvec.resize(10);
		ftvec.resize(10);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.resize(15, -12);
		ftvec.resize(15, -12);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.resize(500);
		ftvec.resize(500);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.resize(20);
		ftvec.resize(20);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector reserve
?
?	note: Compares the reserve() functions of both std vector
?		and fortytwo vector.
*/
void	vectorReserve(void)
{
	std::vector<int> stdvec;
	ft::vector<int>	ftvec;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\t       Reserve:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			stdvec.push_back(i);
			ftvec.push_back(i);
		}
		stdvec.reserve(100);
		ftvec.reserve(100);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		stdvec.reserve(25);
		ftvec.reserve(25);
		cmp.vectorSizeCmp(stdvec, ftvec);
		cmp.vectorCapacityCmp(stdvec, ftvec);
		cmp.vectorElementsCmp(stdvec, ftvec);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}

/*
*	@brief: Tests the fortyTwo vector Num val insert
?
?	note: Compares the clear() functions of both std vector
?		and fortytwo vector.
*/
void	vectorSwap(void)
{
	int	ran = 0;
	std::vector<int> stdvec;
	std::vector<int> stdtest;
	ft::vector<int>	ftvec;
	ft::vector<int> fttest;
	ft::vectorCompare<int>	cmp;
	std::cout << KCYN << "\tft::vector:\t   Iter Swap:" << KNRM;
	try
	{
		for(int i = 0; i < 30; i++)
		{
			ran = rand() % 10;
			stdvec.push_back(ran);
			ftvec.push_back(ran);
		}
		for(int i = 0; i < 15; i++)
		{
			ran = rand() % 10;
			stdtest.push_back(ran);
			fttest.push_back(ran);
		}
		stdvec.swap(stdtest);
		ftvec.swap(fttest);
		cmp.vectorSizeCmp(stdtest, fttest);
		cmp.vectorCapacityCmp(stdtest, fttest);
		cmp.vectorElementsCmp(stdtest, fttest);
		stdtest.swap(stdvec);
		fttest.swap(ftvec);
		cmp.vectorSizeCmp(stdtest, fttest);
		cmp.vectorCapacityCmp(stdtest, fttest);
		cmp.vectorElementsCmp(stdtest, fttest);
		std::cout << "\n\t\t(Size / Cap) cmp ->\t[" << KGRN << "ok" << KNRM << "]\n";
		std::cout << "\t\tElements cmp\t ->\t[" << KGRN << "ok" << KNRM << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\n\t" << e.what() << " ->\t[" << KRED << "!KO" << KNRM << "]\n";
	}
}
