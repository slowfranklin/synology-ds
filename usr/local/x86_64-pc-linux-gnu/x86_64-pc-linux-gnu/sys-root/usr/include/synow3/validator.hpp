/* Copyright (c) 2000-2016 Synology Inc. All rights reserved.*/
#ifndef __SYNO_W3_VALIDATOR_HPP__
#define __SYNO_W3_VALIDATOR_HPP__
#ifndef __cplusplus
#error "this file is c++ only."
#endif

#include <limits>
#include <boost/core/enable_if.hpp>
#include <boost/static_assert.hpp>

namespace synow3 {

struct PortValidator;
class Validator {
public:
    template <typename T >
    static bool IsPortValid(T port) {
        typedef typename boost::is_same<PortValidator, typename boost::remove_cv<typename boost::decay<T>::type>::type> test;
        BOOST_STATIC_ASSERT_MSG(
            !test::value,
            "call PortValidator::valid, not Validator::IsPortValid"
        );
        return 0 < port && port <= 65535;
    }
    static bool IsSerNameValid(const std::string &strSrvName);
    static bool IsNetBIOSName(const std::string &);
    static bool UTF8ToPunycode(const std::string &, std::string &);
    static bool CheckSCConflict(std::set<uint16_t> &);
    static bool CheckSCConflict(uint16_t);

private:
    Validator();
    Validator(Validator&);
    Validator&operator=(Validator&);
};

struct PortValidator {
    uint16_t port;

    template <typename T>
    static uint16_t validator(T port) { return Validator::IsPortValid(port) ? static_cast<uint16_t>(port) : 0; }
    template <typename T>
    PortValidator(T port): port(validator(port)) {
        BOOST_STATIC_ASSERT_MSG(std::numeric_limits<T>::is_integer, "T must be a integer type");
    }
    PortValidator(const PortValidator & _): port(_.port) {}

    bool valid() const { return port != 0; }
    operator uint16_t() const { return port; }
};

} // namespace synow3

#endif // __SYNO_W3_VALIDATOR_HPP__
