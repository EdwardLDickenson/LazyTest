//=============================================================================
//---	Authorship And Copyright	-------------------------------------------
//=============================================================================

/*
Name:	Lazy Test
Author:	Edward Lloyd Dickenson

	This software is provided under the standard GNU v3 license. For more
	information see either the included license or visit:
	https://www.gnu.org/licenses/gpl-3.0.en.html
*/

//=============================================================================
//---	Preprocessors	-------------------------------------------------------
//=============================================================================

#pragma once

#ifndef LAZYTEST_HPP
#define LAZYTEST_HPP

//=============================================================================
//---	Dependencies	-------------------------------------------------------
//=============================================================================

//#include "lazydeps.hpp"
#include "Assert.hpp"
#include "testSuite.hpp"




//	TODO:
//
//	Definitely a bullet point in the future iterations, but currently unfeasible
//
//	When a test group fails the report does not explain how many units passed.
//	This is a bug
//
//	The library should be wrapped inside a namespace
//
//	Add support for signed/unsigned comparisons. These shouldn't be compared
//	without warning the user that the comparison can lose precision. But
//	many times it does not matter and, for example, writing 10U in a comparison
//	can be very annoying. Consider writing something like unsignedEquals
//
//	Some capacity to check for infinite loops would be nice. Something like
//	a run time cap for a while loop would work very nicely as a utility
//
//
//


#endif	//	LAZYTEST_HPP
