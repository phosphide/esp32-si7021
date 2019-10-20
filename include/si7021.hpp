/*
 * si7021.hpp
 *
 *  Created on: 20.10.2019
 *      Author: phosphide
 */

#pragma once

#include "esp_err.h"

#include "si7021.h"

class Si7021 {
public:
	Si7021() {
	}
	int init(i2c_port_t port, gpio_num_t sda_pin, gpio_num_t scl_pin,  gpio_pullup_t sda_internal_pullup,  gpio_pullup_t scl_internal_pullup) {
		int ret = si7021_init(port, sda_pin, scl_pin, sda_internal_pullup, scl_internal_pullup);
		if (ret == SI7021_ERR_OK) {
			port_ = port;
		}
		return ret;
	}
	float read_temperature() {
		return si7021_read_temperature(port_);
	}
	float read_humidity() {
		return si7021_read_humidity(port_);
	}
	uint8_t get_resolution() {
		return si7021_get_resolution(port_);
	}
	int set_resolution(uint8_t resolution) {
		return si7021_set_resolution(port_, resolution);
	}
	int soft_reset() {
		return si7021_soft_reset(port_);
	}

private:
	i2c_port_t port_ = I2C_NUM_MAX;
};
