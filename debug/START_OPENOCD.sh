
echo 'STEP 1. Run this script'
echo 'STEP 2: run GDB:'
echo 'GDB: arm-none-eabi-gdb --eval-command="target remote localhost:3333" ../bin/blink.elf'
echo ' type in gdb to set breakpoint: b main'
echo 'STEP 3: run telnet:'
echo 'TELNET: telnet localhost 4444'
echo 'STEP 4: execute command over telnet: > reset init'
echo 'STEP 5: continue in gdb: c'

openocd

