// Copyright (c) 2022 Klemens D. Morgenstern
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef BOOST_PROCESS_V2_DETAIL_LAST_ERROR_HPP
#define BOOST_PROCESS_V2_DETAIL_LAST_ERROR_HPP

#include <boost/process/v2/detail/config.hpp>

BOOST_PROCESS_V2_BEGIN_NAMESPACE

namespace detail {

BOOST_PROCESS_V2_DECL error_code get_last_error();
BOOST_PROCESS_V2_DECL void throw_last_error();
BOOST_PROCESS_V2_DECL void throw_last_error(const char * msg);
BOOST_PROCESS_V2_DECL void throw_last_error(const std::string & msg);

}
BOOST_PROCESS_V2_END_NAMESPACE

#if defined(BOOST_PROCESS_V2_HEADER_ONLY)

#include <boost/process/v2/detail/impl/last_error.ipp>

#endif


#endif //BOOST_PROCESS_V2_DETAIL_LAST_ERROR_HPP
