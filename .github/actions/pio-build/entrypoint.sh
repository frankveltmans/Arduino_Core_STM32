#!/bin/bash

readonly CMSIS_VERSION="$1"
readonly CMSIS_ARCHIVE="CMSIS-${CMSIS_VERSION}.tar.bz2"

# Install the development version of ststm32 platform
platformio platform install "https://github.com/platformio/platform-ststm32.git" || {
  exit 1
}
# Prepare framework for CI
python3 -c "import json; import os; fp=open(os.path.expanduser('~/.platformio/platforms/ststm32/platform.json'), 'r+'); data=json.load(fp); data['packages']['framework-arduinoststm32']['version'] = '*'; del data['packages']['framework-arduinoststm32']['owner']; fp.seek(0); fp.truncate(); json.dump(data, fp); fp.close()" || {
  exit 1
}

# Fix for variant path change while not updated in PIO
python3 -c "import json; import os; fp=open(os.path.expanduser('~/.platformio/platforms/ststm32/boards/malyanm300_f070cb.json'), 'r+'); data=json.load(fp); data['build']['variant'] = 'STM32F0xx/F070CBT'; data['build']['extra_flags'] = '-DSTM32F070xB -DVARIANT_H=\\\\\"variant_MALYANMx00_F070CB.h\\\\\"'; fp.seek(0); fp.truncate(); json.dump(data, fp); fp.close()" || {
  exit 1
}
python3 -c "import json; import os; fp=open(os.path.expanduser('~/.platformio/platforms/ststm32/boards/nucleo_l152re.json'), 'r+'); data=json.load(fp); data['build']['variant'] = 'STM32L1xx/L151RET_L152RET_L162RET'; data['build']['extra_flags'] = '-DSTM32L152xE -DVARIANT_H=\\\\\"variant_NUCLEO_L152RE.h\\\\\"'; fp.seek(0); fp.truncate(); json.dump(data, fp); fp.close()" || {
  exit 1
}

ln --symbolic "$GITHUB_WORKSPACE" "$HOME/.platformio/packages/framework-arduinoststm32" || {
  exit 1
}
# Download and unpack CMSIS package
wget --no-verbose "https://github.com/stm32duino/ArduinoModule-CMSIS/releases/download/$CMSIS_VERSION/$CMSIS_ARCHIVE" || {
  exit 1
}
tar --extract --bzip2 --file="$CMSIS_ARCHIVE" || {
  exit 1
}
cd "$GITHUB_WORKSPACE/CI/build/" || {
  exit 1
}
python3 platformio-builder.py --board=malyanm300_f070cb --board=nucleo_l152re

exit $?
