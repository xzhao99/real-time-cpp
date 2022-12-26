﻿///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2021.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <app/benchmark/app_benchmark.h>
#include <mcal_benchmark.h>
#include <mcal_cpu.h>

namespace app { namespace benchmark {

using port_type = mcal::benchmark::benchmark_port_type;

void task_init();
void task_func();

} // namespace benchmark
} // namespace app

auto app::benchmark::task_init() -> void
{
  // Set the benchmark port pin direction to output.
  port_type::set_direction_output();
}

auto app::benchmark::task_func() -> void
{
  // Set the benchmark port pin level to high.
  port_type::set_pin_high();

  // Run the benchmark (if enabled via compiler switch).

  #if(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_NONE)

  const bool result_is_ok = app::benchmark::run_none();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_COMPLEX)

  const bool result_is_ok = app::benchmark::run_complex();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_CRC)

  const bool result_is_ok = app::benchmark::run_crc();

  #elif (APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_FAST_MATH)

  const bool result_is_ok = app::benchmark::run_fast_math();

  #elif (APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_FILTER)

  const bool result_is_ok = app::benchmark::run_filter();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_FIXED_POINT)

  const bool result_is_ok = app::benchmark::run_fixed_point();

  #elif (APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_FLOAT)

  const bool result_is_ok = app::benchmark::run_float();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_WIDE_INTEGER)

  const bool result_is_ok = app::benchmark::run_wide_integer();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_PI_SPIGOT)

  const bool result_is_ok = app::benchmark::run_pi_spigot();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_PI_SPIGOT_SINGLE)

  const bool result_is_ok = app::benchmark::run_pi_spigot_single();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_HASH)

  const bool result_is_ok = app::benchmark::run_hash();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_WIDE_DECIMAL)

  const bool result_is_ok = app::benchmark::run_wide_decimal();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_TRAPEZOID_INTEGRAL)

  const bool result_is_ok = app::benchmark::run_trapezoid_integral();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_PI_AGM)

  const bool result_is_ok = app::benchmark::run_pi_agm();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_BOOST_MATH_CBRT_TGAMMA)

  const bool result_is_ok = app::benchmark::run_boost_math_cbrt_tgamma();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_CNL_SCALED_INTEGER)

  const bool result_is_ok = app::benchmark::run_cnl_scaled_integer();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_SOFT_DOUBLE_H2F1)

  const bool result_is_ok = app::benchmark::run_soft_double_h2f1();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_BOOST_MULTIPRECISION_CBRT)

  const bool result_is_ok = app::benchmark::run_boost_multiprecision_cbrt();

  #elif(APP_BENCHMARK_TYPE == APP_BENCHMARK_TYPE_BOOST_MATH_CYL_BESSEL_J)

  const bool result_is_ok = app::benchmark::run_boost_math_cbrt_cyl_bessel_j();

  #endif

  // Set the benchmark port pin level to low.
  port_type::set_pin_low();

  if(!result_is_ok)
  {
    // Purposefully crash the system (watchdog) if the benchmark fails.
    for(;;)
    {
      mcal::cpu::nop();
    }
  }
}
