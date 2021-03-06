/*
 * MITags.h
 * Date: 2012-07-31
 * Author: Karsten Ahnert (karsten.ahnert@gmx.de)
 * Copyright: Karsten Ahnert
 *
 * Use, modification and distribution is subject to the Boost Software License,
 * Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef AMBOSS_MITAGS_H_INCLUDED
#define AMBOSS_MITAGS_H_INCLUDED


#include <boost/multi_index_container.hpp>

namespace Amboss {
namespace Shapefile {

namespace mi = boost::multi_index;

struct ById { };
struct ByIndex { };
struct ByName { };



} // namespace Shapefile
} // namespace Amboss


#endif // AMBOSS_MITAGS_H_INCLUDED
