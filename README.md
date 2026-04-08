# zmk-board-efogtech-trackball-0

ZMK board definition for the Endgame trackball by efogtech.

Forked from [efogtech/endgame-trackball-config](https://github.com/efogtech/endgame-trackball-config) `paw3395` branch and converted to a ZMK v0.3 split peripheral.

## Hardware

- **MCU:** nRF52833 (Nordic Semiconductor)
- **Sensors:** Dual PAW3395 optical sensors (SPI0 + SPI1)
- **Buttons:** 8 direct GPIO keys
- **Encoders:** 2 x EC11-ISH rotary encoders
- **Battery:** Voltage divider on ADC channel 7

## Peripheral Mode

This board is configured as a BLE split peripheral:
- USB and ZMK Studio disabled
- RGB underglow removed
- Input events forwarded to central via `zmk,input-split`
- Position offset and keymap bindings are set in user config, not here

## Modules

Requires these efogdev modules (referenced in config/west.yml):
- zmk-paw3395-driver
- zmk-pointer-2s-mixer
- zmk-axis-clamper
- zmk-report-rate-limit
- zmk-ec11-ish-driver
- zmk-acceleration-curves
- zmk-input-processor-rotate-plane
- zmk-runtime-config
