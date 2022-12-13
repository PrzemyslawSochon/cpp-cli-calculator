#pragma once

inline void isBoostInstalled()
{
    ;
}

namespace mathConstants
{
}

//if any of the following booleans is set to false
//program will throw an error on a corresponding encounter
constexpr bool treat_double_asterisks_as_exponent{true};
constexpr bool treat_comma_as_decimal_fraction{true};
constexpr bool treat_braces_as_parenthesis{true};
constexpr bool treat_brackets_as_parenthesis{true};
constexpr bool treat_backward_slash_as_division{true};
constexpr bool treat_percentage_as_modulo{true};
constexpr bool treat_exclamation_as_factorial{true};
constexpr bool treat_pi_as_trig_constant{true};
constexpr bool treat_e_as_log_constant{true};
constexpr bool treat_g_as_gravitational_const{true};