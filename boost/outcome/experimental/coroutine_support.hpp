/* Tells C++ coroutines about Outcome's result
(C) 2019-2022 Niall Douglas <http://www.nedproductions.biz/> (12 commits)
File Created: Oct 2019


Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef BOOST_OUTCOME_EXPERIMENTAL_COROUTINE_SUPPORT_HPP
#define BOOST_OUTCOME_EXPERIMENTAL_COROUTINE_SUPPORT_HPP

#include "../config.hpp"

#define BOOST_OUTCOME_COROUTINE_SUPPORT_NAMESPACE_BEGIN                                                                                                                                                                                                                                                                              \
  BOOST_OUTCOME_V2_NAMESPACE_BEGIN namespace experimental                                                                                                                                                                                                                                                                            \
  {                                                                                                                                                                                                                                                                                                                            \
    namespace awaitables                                                                                                                                                                                                                                                                                                       \
    {
//
#define BOOST_OUTCOME_COROUTINE_SUPPORT_NAMESPACE_EXPORT_BEGIN                                                                                                                                                                                                                                                                       \
  BOOST_OUTCOME_V2_NAMESPACE_EXPORT_BEGIN namespace experimental                                                                                                                                                                                                                                                                     \
  {                                                                                                                                                                                                                                                                                                                            \
    namespace awaitables                                                                                                                                                                                                                                                                                                       \
    {
//
#define BOOST_OUTCOME_COROUTINE_SUPPORT_NAMESPACE_END                                                                                                                                                                                                                                                                                \
  }                                                                                                                                                                                                                                                                                                                            \
  }                                                                                                                                                                                                                                                                                                                            \
  BOOST_OUTCOME_V2_NAMESPACE_END

#ifndef BOOST_NO_EXCEPTIONS
#include "status-code/system_code_from_exception.hpp"
BOOST_OUTCOME_V2_NAMESPACE_BEGIN
namespace awaitables
{
  namespace detail
  {
    inline bool error_is_set(BOOST_OUTCOME_SYSTEM_ERROR2_NAMESPACE::system_code &sc) noexcept { return sc.failure(); }
    inline BOOST_OUTCOME_SYSTEM_ERROR2_NAMESPACE::system_code error_from_exception(std::exception_ptr &&ep = std::current_exception(), BOOST_OUTCOME_SYSTEM_ERROR2_NAMESPACE::system_code not_matched = BOOST_OUTCOME_SYSTEM_ERROR2_NAMESPACE::generic_code(BOOST_OUTCOME_SYSTEM_ERROR2_NAMESPACE::errc::resource_unavailable_try_again)) noexcept
    {
      return BOOST_OUTCOME_SYSTEM_ERROR2_NAMESPACE::system_code_from_exception(static_cast<std::exception_ptr &&>(ep), static_cast<BOOST_OUTCOME_SYSTEM_ERROR2_NAMESPACE::system_code &&>(not_matched));
    }
  }  // namespace detail
}  // namespace awaitables
BOOST_OUTCOME_V2_NAMESPACE_END
#endif

#include "../detail/coroutine_support.ipp"

#undef BOOST_OUTCOME_COROUTINE_SUPPORT_NAMESPACE_BEGIN
#undef BOOST_OUTCOME_COROUTINE_SUPPORT_NAMESPACE_EXPORT_BEGIN
#undef BOOST_OUTCOME_COROUTINE_SUPPORT_NAMESPACE_END

#endif
